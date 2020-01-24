
#include <iostream>

#include "database.h"

using namespace std;

int main(void)
{
	Database& db = Database::getInstance();
	db.connect("tcp://127.0.0.1:3306", "admin", "w2aredeveloper");
	db.switchDatabase("sampledatabase");
	std::cout << "Hello World\n";
	return 0;
}
