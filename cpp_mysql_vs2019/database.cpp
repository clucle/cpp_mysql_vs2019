#include "database.h"

Database::Database()
{
	driver = nullptr;
	con = nullptr;
	stmt = nullptr;
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
		stmt = con->createStatement();
	}
	catch (sql::SQLException & e) {
		// err
	}
}

std::shared_ptr<sql::ResultSet> Database::executeQuery(const std::string& query)
{
	databaseLock.lock();
	std::shared_ptr<sql::ResultSet> res;
	try {
		res.reset(stmt->executeQuery(query.c_str()));
	}
	catch (sql::SQLException & e) {
		// err
	}
	databaseLock.unlock();

	return res;
}

bool Database::execute(const std::string& query)
{
	databaseLock.lock();
	bool res = false;
	try {
		res = stmt->execute(query.c_str());
	}
	catch (sql::SQLException & e) {
		// err
	}
	databaseLock.unlock();

	return res;
}

void Database::disconnect()
{
	con->close();
}
