#pragma once

#include <string>

/**Add single quotes to a string.
\param str The inside of the quotes.
\return The new string with quotes.*/
std::string AddSQuote(const std::string& str);
/**Add double quotes to a string.
\param str The inside of the quotes.
\return The new string with quotes.*/
std::string AddDQuote(const std::string& str);
/**Add back quotes (back ticks) to a string.
\param str The inside of the quotes.
\return The new string with quotes.*/
std::string AddBQuote(const std::string& str);