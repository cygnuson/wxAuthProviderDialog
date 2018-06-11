#include "TestApp.hpp"
#include "wxAuthProviderDialog.h"
#include "MyRecordValidator.hpp"
#include "PostgreSQLRecordProvider.hpp"
#include "CommonPopups.hpp"
#include <wx\imagpng.h>

IMPLEMENT_APP(TestApp)


bool TestApp::OnInit()
{
    wxPNGHandler* pngHandler = new wxPNGHandler();
    wxImage::AddHandler(pngHandler);
    auto myRecProvidor = PostgreSQLRecordProvider::Make("postgres", "postgres",
        "192.168.42.133", "testdb");
    auto myAuthValidator = MyRecordValidator::Make();
    auto myAuthProvider = wxAuthProviderDialog::Make(nullptr);
    myAuthProvider->SetAuthValidator(myAuthValidator);
    myAuthProvider->SetRecordProvider(myRecProvidor);
    auto ret = myAuthProvider->Authenticate();
    if (ret == IAuthProvider::RetCode::Cancel)
        Exit();
    delete pngHandler;
    return true;
}
