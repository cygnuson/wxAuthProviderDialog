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