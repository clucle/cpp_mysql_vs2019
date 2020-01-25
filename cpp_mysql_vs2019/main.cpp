
#include <iostream>

#include "database.h"

using namespace std;

int main(void)
{
	Database& db = Database::getInstance();
	db.connect("tcp://127.0.0.1:3306", "admin", "w2aredeveloper");
	db.switchDatabase("sampledatabase");

	// Test Create Table
	db.execute("create table member(m_id VARCHAR(10) NOT NULL PRIMARY KEY, m_pw VARCHAR(10) NOT NULL);");
	std::cout << "Hello World\n";
	return 0;
}
