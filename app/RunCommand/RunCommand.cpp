#include <iostream>
#include <cstring>
#include "RunCommand.h"
#include "mysql_driver.h"
#include "mysql_connection.h"

void RunCommand::initialize(int argc, char *argv[]) {
    if (argc == 1) {
        perror("RunCommand executed with no parameter");
    } else if (argc == 2) {
        if (strcmp(argv[1], "migrate") == 0) {
        }
    }
}
