
#include <stdlib.h>
#include <iostream>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;

int main(void)
{
	sql::Driver* driver;
	sql::Connection* con;

	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "admin", "w2aredeveloper");
	con->setSchema("sampledatabase");

	delete con;

	cout << endl;

	return EXIT_SUCCESS;
}
