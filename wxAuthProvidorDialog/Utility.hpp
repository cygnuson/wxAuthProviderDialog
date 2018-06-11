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