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

#include "IRecordProvider.hpp"
#include "IAuthProvider.hpp"

class IAuthValidator
{
public:
    /**Validate a username and password.
    \param username The username to validate.
    \param password The password to validate.
    \param rec The record to check against.
    \return An IAuthProvider::RetCode that describes the result.*/
    virtual IAuthProvider::RetCode Validate(const std::string& username,
        const std::string& password,
        const IRecordProvider::Record& rec) = 0;
};