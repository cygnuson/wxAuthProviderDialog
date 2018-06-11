#pragma once

#include <string>

#include <wx/wx.h>

/**Show a popup.
\param parent The modality parent for the popup.
\param msg The message to show.
\param bText The button text.
\param caption The caption fo the box.
\param pic The image style (wxICON_*  )
\param exMsgs The extended message.*/
void ShowModalPopup_SingleButton(
    wxWindow* parent,
    const std::string& msg,
    const std::string& caption,
    const std::string& bText = "Ok",
    long pic = wxICON_EXCLAMATION,
    const std::string& exMsg = "");

/**Create an auth related popup with only OK
\param parent The modality parent.
\param message The message to display..*/
void ShowAuthMessage(wxWindow* parent, const std::string& message);
/**Create an auth related popup with only OK
\param parent The modality parent.
\param message The message to display..*/
void ShowErrorMessage(wxWindow* parent, const std::string& message);