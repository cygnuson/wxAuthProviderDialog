/*

(C) Matthew Swanson

This file is part of wxAuthProviderDialog.

wxAuthProviderDialog is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

wxAuthProviderDialog is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with wxAuthProviderDialog.  If not, see <http://www.gnu.org/licenses/>.

*/
#include <fstream>
#include <thread>

#include "wxAuthProviderDialog.h"
#include "PostgreSQLRecordProvider.hpp"
#include "Utility.hpp"

IAuthProvider::RetCode wxAuthProviderDialog::Authenticate()
{
    int code = ShowModal();
    return (RetCode)code;
}

std::shared_ptr<wxAuthProviderDialog> wxAuthProviderDialog::Make(
    wxWindow * parent)
{
    return std::shared_ptr<wxAuthProviderDialog>(
        new wxAuthProviderDialog(parent));
}

void wxAuthProviderDialog::SetRecordProvider(
    std::shared_ptr<IRecordProvider> rp)
{
    if (!rp)
        throw std::runtime_error("The record provider to be set is invalid.");
    m_recProvider = rp;
}

void wxAuthProviderDialog::SetAuthValidator(std::shared_ptr<IAuthValidator> av)
{
    if (!av)
        throw std::runtime_error("The auth validator to be set is invalid");
    m_authValidator = av;
}

void wxAuthProviderDialog::DoClose(int ret, bool force)
{
    if (IsModal())
        EndModal(ret);
    else
    {
        SetReturnCode(ret);
        Close(force);
    }
}

void wxAuthProviderDialog::DoAuth(const IRecordProvider::Record & rec)
{
    auto username = m_userEntry->GetValue().ToStdString();
    auto password = m_passEntry->GetValue().ToStdString();
    auto code = m_authValidator->Validate(username, password, rec);
    bool stop = false;
    switch (code)
    {
    case IAuthProvider::Success:
        OnGoodAuth(rec);
        break;
    case IAuthProvider::UserNoExist:
        OnNoUser();
        break;
    default:
        stop = !OnBadAuth(code);
        break;
    }
    if (stop)
        DoClose(code, false);
}

void wxAuthProviderDialog::wxAuthProviderDialogBaseOnClose(
    wxCloseEvent & event)
{
    DoClose(IAuthProvider::RetCode::Cancel, true);
}

void wxAuthProviderDialog::wxAuthProviderDialogBaseOnInitDialog(
    wxInitDialogEvent & event)
{
    if (!m_recProvider)
        throw std::runtime_error("There is no record provider.");
    if (!m_authValidator)
        throw std::runtime_error("There is no auth validator.");
    if (!VerifyConnection())
        DoClose(IAuthProvider::RetCode::NoConnect, true);
}

void wxAuthProviderDialog::m_userEntryOnTextEnter(
    wxCommandEvent & event)
{
    //enter = same as click login
    m_loginButtonOnButtonClick(event);
}

void wxAuthProviderDialog::m_passEntryOnTextEnter(
    wxCommandEvent & event)
{
    //enter = same as click login
    m_loginButtonOnButtonClick(event);
}

void wxAuthProviderDialog::m_loginButtonOnButtonClick(
    wxCommandEvent & event)
{
    auto username = m_userEntry->GetValue().ToStdString();
    std::string comparison = "username=" + AddSQuote(username);
    auto rec = m_recProvider->GetRecords("users", comparison.c_str());
    if (rec.size() == 1)
        DoAuth(rec[0]);
    else if (rec.size() > 1)
        throw std::runtime_error("There are multiple user records.");
    else
        DoAuth(IRecordProvider::Record());

    m_userEntry->Clear();
    m_passEntry->Clear();
    m_userEntry->SetFocus();
}

void wxAuthProviderDialog::m_cancelOnButtonClick(
    wxCommandEvent & event)
{
    DoClose(IAuthProvider::RetCode::Cancel, true);
}

bool wxAuthProviderDialog::VerifyConnection()
{
    for (int i = 0; i < m_retryCt && !m_recProvider->connected(); ++i)
    {
        m_recProvider->ReConnect();
        std::this_thread::sleep_for(std::chrono::milliseconds(m_retryWait));
    }
    if (!m_recProvider->connected())
    {
        OnCantConnect(m_recProvider);
        return false;
    }
    return true;
}


wxAuthProviderDialog::wxAuthProviderDialog(wxWindow* parent)
    : wxAuthProviderDialogBase(parent)
{
}

