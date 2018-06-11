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
