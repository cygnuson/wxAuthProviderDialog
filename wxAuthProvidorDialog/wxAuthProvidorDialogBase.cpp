///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxAuthProvidorDialogBase.h"

///////////////////////////////////////////////////////////////////////////

wxAuthProviderDialogBase::wxAuthProviderDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* m_mainSizer;
	m_mainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_logo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("logo_holder.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_mainSizer->Add( m_logo, 0, wxALIGN_CENTER|wxALL|wxSHAPED, 5 );
	
	wxFlexGridSizer* m_authGrid;
	m_authGrid = new wxFlexGridSizer( 2, 2, 0, 0 );
	m_authGrid->AddGrowableCol( 1 );
	m_authGrid->SetFlexibleDirection( wxBOTH );
	m_authGrid->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_userLabel = new wxStaticText( this, wxID_ANY, wxT("Username"), wxDefaultPosition, wxDefaultSize, 0 );
	m_userLabel->Wrap( -1 );
	m_authGrid->Add( m_userLabel, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_userEntry = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_authGrid->Add( m_userEntry, 0, wxALL|wxEXPAND, 5 );
	
	m_passLabel = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_passLabel->Wrap( -1 );
	m_authGrid->Add( m_passLabel, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_passEntry = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD|wxTE_PROCESS_ENTER );
	m_authGrid->Add( m_passEntry, 0, wxALL|wxEXPAND, 5 );
	
	
	m_mainSizer->Add( m_authGrid, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* m_buttonBox;
	m_buttonBox = new wxBoxSizer( wxHORIZONTAL );
	
	m_loginButton = new wxButton( this, wxID_ANY, wxT("&Login"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonBox->Add( m_loginButton, 0, wxALIGN_TOP|wxRIGHT, 5 );
	
	m_cancel = new wxButton( this, wxID_ANY, wxT("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonBox->Add( m_cancel, 0, wxALIGN_TOP, 5 );
	
	
	m_mainSizer->Add( m_buttonBox, 1, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	
	this->SetSizer( m_mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxAuthProviderDialogBase::wxAuthProviderDialogBaseOnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( wxAuthProviderDialogBase::wxAuthProviderDialogBaseOnInitDialog ) );
	m_userEntry->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxAuthProviderDialogBase::m_userEntryOnTextEnter ), NULL, this );
	m_passEntry->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxAuthProviderDialogBase::m_passEntryOnTextEnter ), NULL, this );
	m_loginButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthProviderDialogBase::m_loginButtonOnButtonClick ), NULL, this );
	m_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthProviderDialogBase::m_cancelOnButtonClick ), NULL, this );
}

wxAuthProviderDialogBase::~wxAuthProviderDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxAuthProviderDialogBase::wxAuthProviderDialogBaseOnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( wxAuthProviderDialogBase::wxAuthProviderDialogBaseOnInitDialog ) );
	m_userEntry->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxAuthProviderDialogBase::m_userEntryOnTextEnter ), NULL, this );
	m_passEntry->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxAuthProviderDialogBase::m_passEntryOnTextEnter ), NULL, this );
	m_loginButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthProviderDialogBase::m_loginButtonOnButtonClick ), NULL, this );
	m_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxAuthProviderDialogBase::m_cancelOnButtonClick ), NULL, this );
	
}
