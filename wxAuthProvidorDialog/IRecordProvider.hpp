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
#include <map>
#include <vector>

class IRecordProvider
{
public:
    /**The type of one record. Access with rec["id"] which woudl return the
    value of the ID field for the record.*/
    using Record = std::map<std::string, std::string>;
    /**A list of records.*/
    using RecordList = std::vector<Record>;

    /**Get a record list.
    \param table The table to get from.
    \param whereVal value of the where clause. eg id>1
    \param limit The max recs to get, 0 for all recs.*/
    virtual RecordList GetRecords(
        const std::string& table,
        const std::string& whereVal,
        size_t limit = 0) = 0;

    /**Connect to the database.*/
    virtual void ReConnect() = 0;

    /**Determine if the database is connected.
    \return true if the db is connected, false if not.*/
    virtual bool connected() const = 0;

    /**Get the address of the providers conenction.
    \return The address.*/
    virtual std::string GetAddress() const = 0;
private:

};