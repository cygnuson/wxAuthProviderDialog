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