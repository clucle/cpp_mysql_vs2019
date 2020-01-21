
#include <iostream>

#include "database.h"

using namespace std;

int main(void)
{
	Database db("tcp://127.0.0.1:3306", "admin", "w2aredeveloper");
	db.connect();
	db.switchDatabase("sampledatabase");
	std::cout << "Hello World\n";
	return 0;
}
