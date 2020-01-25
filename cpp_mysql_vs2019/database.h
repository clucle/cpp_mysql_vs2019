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

	void prepare(const std::string& query);
	void deletePrepare();

	void setInt(const int& num, const int& data);
	void setString(const int& num, const std::string& data);

	void executeQuery(const std::string& query);

	std::string getString(const std::string& field);
	std::string getString(const int& index);

	int getInt(const std::string& field);
	int getInt(const int& index);

	sql::ResultSet* getRes();

	bool next();

private:

	void disconnect();

	std::recursive_mutex databaseLock;

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* prep_stmt;
	sql::ResultSet* res;

};

#endif

