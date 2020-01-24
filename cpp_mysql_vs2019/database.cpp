#include "database.h"

Database::Database()
{
	driver = nullptr;
	con = nullptr;
}

Database::~Database()
{
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
