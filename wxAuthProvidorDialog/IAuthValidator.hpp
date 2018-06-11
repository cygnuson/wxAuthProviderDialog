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