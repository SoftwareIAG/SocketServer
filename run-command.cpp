#include "lib/LinkList/LinkList.h"
#include "lib/HashTable/HashTable.h"
#include "lib/ConfigManager/ConfigManager.h"
#include "app/RunCommand/RunCommand.h"

/**
 * Main.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
    RunCommand::initialize(argc, argv);
}
