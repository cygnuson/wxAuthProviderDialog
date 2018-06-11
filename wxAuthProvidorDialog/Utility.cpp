#include "Utility.hpp"

std::string AddSQuote(const std::string & str)
{
    return std::string("'") + str + "'";
}

std::string AddDQuote(const std::string & str)
{
    return std::string("\"") + str + "\"";
}

std::string AddBQuote(const std::string & str)
{
    return std::string("`") + str + "`";
}
