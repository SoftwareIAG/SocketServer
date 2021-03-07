#include <iostream>
#include <cstring>
#include "RunCommand.h"
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "cppconn/statement.h"
#include "../../main.h"

void RunCommand::initialize(int argc, char *argv[]) {
    configManager->initialize();

    if (argc == 1) {
        perror("RunCommand executed with no parameter");
    } else if (argc == 2) {
        if (strcmp(argv[1], "migrate") == 0) {
            try {
                sql::Driver *driver;
                sql::Connection *con;
                sql::Statement *stmt;
                sql::ResultSet *res;

                driver = get_driver_instance();
                con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
                con->setSchema("test");
                stmt = con->createStatement();
                stmt->executeQuery("");


            } catch (sql::SQLException &e) {

            }
        }
    }
}
