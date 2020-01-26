#ifndef CDATABASE
#define CDATABASE

#include <string>
#include <stdlib.h>
#include <iostream>
#include <mutex>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

class Database
{
public:
	Database();
	~Database();

	Database(const Database&) = delete;
	Database& operator=(const Database&) = delete;

	static Database& getInstance()
	{
		static Database instance;
		return instance;
	}

	void connect(std::string url, std::string user, std::string password);
	void switchDatabase(const std::string& name);

	/**
	 * Execute query
	 *
	 * Executes query which generates results
	 *
	 * @param query command
	 * @return std::shared_ptr<sql::ResultSet>
	 */
	std::shared_ptr<sql::ResultSet>  executeQuery(const std::string& query);

	/**
	 * Execute query
	 *
	 * Executes query which doesn't generates results
	 *
	 * @param query command
	 * @return bool
	 */
	bool execute(const std::string& query);

private:

	void disconnect();

	std::recursive_mutex databaseLock;

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
};

#endif

