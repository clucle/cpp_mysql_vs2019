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
		stmt = con->createStatement();
	}
	catch (sql::SQLException & e) {
		// err
	}
}

void Database::prepare(const std::string& query)
{
	try {
		prep_stmt = con->prepareStatement(query.c_str());
	}
	catch (sql::SQLException & e) {
		// err
	}
}

void Database::deletePrepare()
{
	delete prep_stmt;
	prep_stmt = nullptr;
}

void Database::setInt(const int& num, const int& data)
{
	prep_stmt->setInt(num, data);
}

void Database::setString(const int& num, const std::string& data)
{
	prep_stmt->setString(num, data);
}

void Database::executeQuery(const std::string& query)
{
	try {
		if (query != "") {
			res = stmt->executeQuery(query.c_str());
		}
		else {
			res = prep_stmt->executeQuery();
		}
	}
	catch (sql::SQLException & e) {
		// err
	}
}

void Database::execute(const std::string& query)
{
	try {
		if (query != "") {
			stmt->execute(query.c_str());
		}
		else {
			prep_stmt->execute();
		}
	}
	catch (sql::SQLException & e) {
		// err
	}
}

std::string Database::getString(const std::string& field)
{
	return res->getString(field);
}

std::string Database::getString(const int& index)
{
	return res->getString(index);
}

int Database::getInt(const std::string& field)
{
	return res->getInt(field);
}

int Database::getInt(const int& index)
{
	return res->getInt(index);
}

sql::ResultSet* Database::getRes()
{
	return res;
}

bool Database::next()
{
	return res->next();
}

void Database::disconnect()
{
	con->close();
}
