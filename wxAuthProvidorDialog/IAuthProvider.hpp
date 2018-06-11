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

#include <utility>

class IAuthProvider
{
public:
    /**Various ret codes the auth provider could utilize*/
    enum RetCode
    {
        Unknown,
        /**Could not connect*/
        NoConnect,
        /**The password is bad.*/
        PassNoGood,
        /**All good*/
        Success,
        /**User is disabled.*/
        UserBanned,
        /**User does not exist.*/
        UserNoExist,
        /**Cenceled*/
        Cancel,

        Amt,
    };

    /**Authenticate something.
    \return A code describing the result of authentication.*/
    virtual RetCode Authenticate() = 0;
};