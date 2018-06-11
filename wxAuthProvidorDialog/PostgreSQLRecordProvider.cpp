
#include "PostgreSQLRecordProvider.hpp"

void PostgreSQLRecordProvider::ReConnect()
{
    PQreset(m_connection.get());
    if (PQstatus(m_connection.get()) != CONNECTION_OK)
        ;//log cant recon
}

bool PostgreSQLRecordProvider::connected() const
{
    auto stat = PQstatus(m_connection.get());
    return (stat == CONNECTION_OK);
}

std::shared_ptr<PostgreSQLRecordProvider> PostgreSQLRecordProvider::Make(
    const std::string & username,
    const std::string & pw,
    const std::string & address, 
    const std::string & dbname)
{
    return std::shared_ptr<PostgreSQLRecordProvider>(
        new PostgreSQLRecordProvider(username, pw, address,dbname));
}

typename PostgreSQLRecordProvider::RecordList
PostgreSQLRecordProvider::GetRecords(
    const std::string & table, 
    const std::string & whereVal,
    size_t limit)
{
    if (!connected())
        throw std::runtime_error("Not connected to the database.");
    RecordList ret;
    std::stringstream ss;
    ss << "SELECT * FROM " << table << " WHERE " << whereVal;
    if (limit > 0)
        ss << " LIMIT " << limit;
    PGresult *res = PQexec(m_connection.get(), ss.str().c_str());
    size_t rows = PQntuples(res);
    size_t cols = PQnfields(res);
    for (size_t i = 0; i < rows; ++i)
    {
        ret.emplace_back();
        for (size_t j = 0; j < cols; ++j)
        {
            char * fname = PQfname(res, (int) j);
            std::string field(fname);
            ret.back()[field] = PQgetvalue(res, (int) i, (int) j);
        }
    }
    PQclear(res);
    return ret;
}

std::string PostgreSQLRecordProvider::GetAddress() const
{
    return m_addr;
}

PostgreSQLRecordProvider::PostgreSQLRecordProvider(
    const std::string & username, 
    const std::string & pw, 
    const std::string & address, 
    const std::string & dbname)
    :m_user(username), m_pw(pw), m_addr(address), m_dbName(dbname)
{
    std::stringstream ss;
    ss << "user=" << m_user << " password=" << m_pw
        << " hostaddr=" << m_addr << " dbname=" << m_dbName
        << " connect_timeout=1";
    PGconn* lCon = PQconnectdb(ss.str().c_str());
    int con = PQstatus(lCon);
    if (con == CONNECTION_BAD)
        ;//log no immediate connection
    //special deleter so that its cleaned properly.
    m_connection.reset(lCon, [](PGconn* p) {
        PQfinish(p);
    });
    return;
}
