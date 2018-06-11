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
#include "CommonPopups.hpp"


void ShowModalPopup_SingleButton(
    wxWindow* parent,
    const std::string& msg,
    const std::string& caption,
    const std::string& bText,
    long pic,
    const std::string& exMsg)
{
    long style = wxCenter | wxOK | pic;
    style &= ~wxYES_NO;
    wxMessageDialog* box = new wxMessageDialog(parent, msg, caption, style);
    if (exMsg != "")
        box->SetExtendedMessage(exMsg);
    box->SetOKLabel(wxString(bText));
    box->ShowModal();
    delete box;
}

void ShowAuthMessage(wxWindow* parent, const std::string & message)
{
    ShowModalPopup_SingleButton(parent,
        message,
        "Authentication Error",
        "Ok",
        wxICON_AUTH_NEEDED);
}

void ShowErrorMessage(wxWindow* parent, const std::string & message)
{
    ShowModalPopup_SingleButton(parent,
        message,
        "Error",
        "Exit",
        wxICON_ERROR);
}
