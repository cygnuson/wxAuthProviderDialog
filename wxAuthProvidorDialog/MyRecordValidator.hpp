#pragma once

#include "IAuthValidator.hpp"
#include "IRecordProvider.hpp"

class MyRecordValidator : public IAuthValidator
{
public:
    /**Validate a username and password.
    \param username The username to validate.
    \param password The password to validate.
    \param rec The record to check against.
    \return An IAuthProvider::RetCode that describes the result.*/
    virtual IAuthProvider::RetCode Validate(const std::string& username,
        const std::string& password,
        const IRecordProvider::Record& rec);

    /**Make a safe ptr.*/
    static std::shared_ptr<MyRecordValidator> Make();
private:

};