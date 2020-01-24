#ifndef CDATABASE
#define CDATABASE

#include <string>
#include <stdlib.h>
#include <iostream>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

class Database
{
public:
	Database(std::string url, std::string user, std::string password);
	~Database();

	Database(const Database&) = delete;
	Database& operator=(const Database&) = delete;

	void connect();
	void switchDatabase(const std::string& name);

private:

	std::string url_;
	std::string user_;
	std::string password_;

	sql::Driver* driver;
	sql::Connection* con;

};

#endif

