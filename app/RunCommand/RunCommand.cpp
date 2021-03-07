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
                con = driver->connect(configManager->get("DB_URL"), configManager->get("DB_USERNAME"), configManager->get("DB_PASSWORD"));
                con->setSchema(configManager->get("DB_NAME"));
                stmt = con->createStatement();
                stmt->executeQuery("");


            } catch (sql::SQLException &e) {

            }
        }
    }
}
