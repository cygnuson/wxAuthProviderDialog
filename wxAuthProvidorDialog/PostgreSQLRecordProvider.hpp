#pragma once

#include <map>
#include <vector>
#include <sstream>
#include <memory>

#include <libpq-fe.h>

#include "IRecordProvider.hpp"

/**A class tha provides records for other objects.*/
class PostgreSQLRecordProvider : public IRecordProvider
{
public:
    /**The type of one record. Access with rec["id"] which woudl return the
    value of the ID field for the record.*/
    using Record = IRecordProvider::Record;
    /**A list of records.*/
    using RecordList = IRecordProvider::RecordList;

    /**Make the provider ptr.
    \param username The username for the database.
    \param pw The db password.
    \param address The db address.
    \param dbname The name of the DB.*/
    static std::shared_ptr<PostgreSQLRecordProvider> Make(
        const std::string& username,
        const std::string& pw,
        const std::string& address,
        const std::string& dbname);

    /**Connect to the database.*/
    void ReConnect();

    /**Determine if the database is connected.
    \return true if the db is connected, false if not.*/
    bool connected() const;

    /**Get a record list.
    \param table The table to get from.
    \param whereVal value of the where clause. eg id>1
    \param limit The max recs to get, 0 for all recs.*/
    virtual RecordList GetRecords(
        const std::string& table,
        const std::string& whereVal,
        size_t limit = 0);

    /**Get the address of the providers conenction.
    \return The address.*/
    virtual std::string GetAddress() const;

private:
    /**Set the vars immediatly.
    \param username The username for the database.
    \param pw The db password.
    \param address The db address.
    \param dbname The name of the DB.*/
    PostgreSQLRecordProvider(const std::string& username,
        const std::string& pw,
        const std::string& address,
        const std::string& dbname);

    /**The postgres connection*/
    std::shared_ptr<PGconn> m_connection;

    /**The username for the database*/
    std::string m_user;
    /**The pw for the databae.*/
    std::string m_pw;
    /**The addr of the sb.*/
    std::string m_addr;
    /**The database name to connect.*/
    std::string m_dbName;
};

