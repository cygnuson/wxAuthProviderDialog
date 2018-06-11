#pragma once

#include <memory>
#include <functional>

#include "IRecordProvider.hpp"
#include "IAuthValidator.hpp"
#include "IAuthProvider.hpp"
#include "CommonPopups.hpp"
#include "wxAuthProvidorDialogBase.h"


/**Auth provider.*/
class wxAuthProviderDialog : public wxAuthProviderDialogBase,
    public IAuthProvider
{
public:
    /**Authenticate something.
    \return (ture, code) if authentication success, or (false,code) other wise.
    \p code is a return code for why it failed.*/
    virtual RetCode Authenticate();

    /**Create a safe pointe for an auth window.
    \param parent The parent of the dialog (for modality).*/
    static std::shared_ptr<wxAuthProviderDialog> Make(wxWindow* parent);

    /**Set the record provider.
    \param rp The record provider pointer.*/
    void SetRecordProvider(std::shared_ptr<IRecordProvider> rp);

    /**Set the auth validator.
    \param av The auth vaidator to set.*/
    void SetAuthValidator(std::shared_ptr<IAuthValidator> av);

    /**Handle the close operation.
    \param ret The code to return.*/
    void DoClose(int ret, bool force);

    /**Handler auth checking
    \param rec The record to check*/
    virtual void DoAuth(const IRecordProvider::Record& rec);

    /**Handler for when user does not exist.*/
    virtual inline void OnNoUser()
    {
        OnBadAuth(IAuthProvider::RetCode::UserNoExist);
    }

    /**Handler for bad auth.
    \param code The code for why.
    \return True to keep trying.*/
    virtual inline bool OnBadAuth(IAuthProvider::RetCode code)
    {
        std::string errMsg;
        switch (code)
        {
        case IAuthProvider::PassNoGood:
            errMsg = "Your username/password is incorrect.";
            break;
        case IAuthProvider::UserBanned:
            errMsg = "Your account is banned.";
            break;
        case IAuthProvider::UserNoExist:
            errMsg = "Your username/password is incorrect.";
            break;
        default:
            errMsg = "Unknown error.";
            break;
        }
        ShowAuthMessage(this, errMsg);
        return true;
    }

    /**For when auth is good.
    \param rec The record that compared.*/
    virtual inline void OnGoodAuth(const IRecordProvider::Record& rec)
    {
        ShowAuthMessage(this, "Auth Successful (here is where one might lauch"
            " another window with the auth info to do stuff)!");
    }

    /**Event for when cant connect.
    \param rp The record provider that cant connect.*/
    virtual inline void OnCantConnect(std::shared_ptr<IRecordProvider> rp)
    {
        ShowErrorMessage(this, 
            "Cannot conenct the the authentication database, closing...");
        DoClose(IAuthProvider::RetCode::NoConnect, true);
    }

    virtual void wxAuthProviderDialogBaseOnClose(wxCloseEvent& event);

    virtual void wxAuthProviderDialogBaseOnInitDialog(
        wxInitDialogEvent& event);

    virtual void m_userEntryOnTextEnter(wxCommandEvent& event);

    virtual void m_passEntryOnTextEnter(wxCommandEvent& event);

    virtual void m_loginButtonOnButtonClick(wxCommandEvent& event);

    virtual void m_cancelOnButtonClick(wxCommandEvent& event);

private:
    /**Verify the record provider is connected, if not, try to reconnect.
    \return True if connected.*/
    bool VerifyConnection();

    /**Create the auth provider.  Use factory instead.
    \param parent The parent of the widget, for modality.
    \param recProvider The provider for database records.*/
    wxAuthProviderDialog(wxWindow* parent);

    /**The record provider.*/
    std::shared_ptr<IRecordProvider> m_recProvider;

    /**The user/password validator.*/
    std::shared_ptr<IAuthValidator> m_authValidator;

    /**The amount of retries on reconnect.*/
    size_t m_retryCt = 5;

    /**The amount of time between retries in mill sec.*/
    size_t m_retryWait = 100;
};

