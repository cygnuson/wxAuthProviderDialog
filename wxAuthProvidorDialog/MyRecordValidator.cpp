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
