/** @file */
#include "headers/functions.h"

int main(int argc, char **argv) {
    //! std::vector<parameter> parameters - Vector of parameters (pairs of switch and path)
    std::vector<parameter> parameters;
    //! Tscreen screen("ORGANIZER") - Main screen
    Tscreen screen("ORGANIZER");
    //! std::deque<TlistSmallS *> lists - Double-ended queue of lists
    std::deque<TlistSmallS *> lists;
    //! TlistFullS *ptrFullList - Pointer to list currently opened in fullscreen
    TlistFullS *ptrFullList{};

    if (verifyParameters(argc, argv, parameters))
        return 1;

    //opening file
    for (auto &a :parameters) {
        if (a.option == "-i") {
            if (FileManager::readFile(lists, &screen, a.value)) {
                break;
            }
            return 1;
        }
    }

    normalMode(screen, lists, ptrFullList);

    for (auto &a :parameters) {
        if (a.option == "-o") {
            if (FileManager::writeFile(lists, a.value)) {
                break;
            }
            return 1;
        }
    }

    clear(lists);
    return 0;
}