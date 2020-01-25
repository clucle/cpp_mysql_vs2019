#include "database.h"

Database::Database()
{
	driver = nullptr;
	con = nullptr;
	stmt = nullptr;
	prep_stmt = nullptr;
	res = nullptr;
}

Database::~Database()
{
	disconnect();
	delete con;
}

void Database::connect(std::string url, std::string user, std::string password)
{
	driver = get_driver_instance();
	con = driver->connect(
		sql::SQLString(url.c_str())
		, sql::SQLString(user.c_str())
		, sql::SQLString(password.c_str()));
}

void Database::switchDatabase(const std::string& name)
{
	try {
		con->setSchema(sql::SQLString(name.c_str()));
	}
	catch (sql::SQLException & e) {
		// err
	}
}

void Database::disconnect()
{
	con->close();
}
