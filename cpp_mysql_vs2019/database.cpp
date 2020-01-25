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

void Database::prepare(const std::string& query)
{
}

void Database::deletePrepare()
{
}

void Database::setInt(const int& num, const int& data)
{
}

void Database::setString(const int& num, const std::string& data)
{
}

void Database::executeQuery(const std::string& query)
{
}

std::string Database::getString(const std::string& field)
{
	return std::string();
}

std::string Database::getString(const int& index)
{
	return std::string();
}

int Database::getInt(const std::string& field)
{
	return 0;
}

int Database::getInt(const int& index)
{
	return 0;
}

sql::ResultSet* Database::getRes()
{
	return nullptr;
}

bool Database::hasNext()
{
	return false;
}

bool Database::next()
{
	return false;
}

void Database::disconnect()
{
	con->close();
}
