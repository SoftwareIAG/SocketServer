#include <iostream>
#include <cstring>
#include "RunCommand.h"
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/statement.h"
#include "../../main.h"

void RunCommand::initialize(int argc, char *argv[]) {
    configManager->initialize();

    if (argc == 1) { perror("RunCommand executed with no parameter"); }
    else if (argc == 2) {
        if (strcmp(argv[1], "migrate") == 0) {
            try {
                sql::Driver *driver;
                sql::Connection *con;
                sql::Statement *stmt;
                std::string CREATE_TABLES_QUERY = "CREATE TABLE IF NOT EXISTS sockets(id BIGINT AUTO_INCREMENT PRIMARY KEY, uuid VARCHAR(36) NOT NULL, ip VARCHAR(15) NOT NULL, port INT NOT NULL, connected BOOLEAN DEFAULT true NOT NULL, connected_at TIMESTAMP DEFAULT now() NOT NULL, disconnected_at TIMESTAMP null) ENGINE=INNODB;";
                driver = get_driver_instance();
                con = driver->connect(configManager->get("DB_URL"), configManager->get("DB_USERNAME"), configManager->get("DB_PASSWORD"));
                con->setSchema(configManager->get("DB_NAME"));
                stmt = con->createStatement();
                stmt->execute(CREATE_TABLES_QUERY);
            } catch (sql::SQLException &e) {
                std::cout << "# ERR: SQLException in " << __FILE__;
                std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
                std::cout << "# ERR: " << e.what();
                std::cout << " (MySQL error code: " << e.getErrorCode();
                std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
            }
        }
    }
}
