///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXAUTHPROVIDORDIALOGBASE_H__
#define __WXAUTHPROVIDORDIALOGBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxAuthProviderDialogBase
///////////////////////////////////////////////////////////////////////////////
class wxAuthProviderDialogBase : public wxDialog 
{
	private:
	
	protected:
		
		// Virtual event handlers, overide them in your derived class
		virtual void wxAuthProviderDialogBaseOnClose( wxCloseEvent& event ) = 0;
		virtual void wxAuthProviderDialogBaseOnInitDialog( wxInitDialogEvent& event ) = 0;
		virtual void m_userEntryOnTextEnter( wxCommandEvent& event ) = 0;
		virtual void m_passEntryOnTextEnter( wxCommandEvent& event ) = 0;
		virtual void m_loginButtonOnButtonClick( wxCommandEvent& event ) = 0;
		virtual void m_cancelOnButtonClick( wxCommandEvent& event ) = 0;
		
	
	public:
		wxStaticBitmap* m_logo;
		wxStaticText* m_userLabel;
		wxTextCtrl* m_userEntry;
		wxStaticText* m_passLabel;
		wxTextCtrl* m_passEntry;
		wxButton* m_loginButton;
		wxButton* m_cancel;
		
		wxAuthProviderDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AuthProvidorTitle"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 575,252 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~wxAuthProviderDialogBase();
	
};

#endif //__WXAUTHPROVIDORDIALOGBASE_H__
