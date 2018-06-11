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
