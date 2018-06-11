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
#include "MyRecordValidator.hpp"

IAuthProvider::RetCode MyRecordValidator::Validate(
    const std::string & username,
    const std::string & password,
    const IRecordProvider::Record& rec)
{
    if (rec.size() == 0)
        return IAuthProvider::RetCode::UserNoExist;

    bool usernameGood = username == rec.at("username");
    bool passGood = password == rec.at("pw");
    bool enabled = "t" == rec.at("enabled");
    if (usernameGood && passGood && enabled)
        return IAuthProvider::RetCode::Success;
    else if (!usernameGood)
        return IAuthProvider::RetCode::UserNoExist;
    else if (!passGood)
        return IAuthProvider::RetCode::PassNoGood;
    else if (!enabled)
        return IAuthProvider::RetCode::UserBanned;
    else
        return IAuthProvider::RetCode::Unknown;
}

std::shared_ptr<MyRecordValidator> MyRecordValidator::Make()
{
    return std::shared_ptr<MyRecordValidator>(new MyRecordValidator());
}
