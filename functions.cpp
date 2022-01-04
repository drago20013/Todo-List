//
// Created by drago on 6/24/21.
//
#include "headers/functions.h"

bool verifyParameters(int argc, char **argv, std::vector<parameter> &parameters) {
    if (argc == 1){
        parameters.push_back({"-i", "lists.txt"});
        parameters.push_back({"-o", "lists.txt"});
    } else if ( (argc == 2 && strcmp(argv[1], "-h") == 0)) {
        printUsage(argv[0]);
        return true;
    } else if (argc != 5) {
        std::cerr << "Incorrect parameters!\n\n";
        printUsage(argv[0]);
        return true;
    } else {
        for (int i = 1; i < argc; i += 2) {
            parameters.push_back({argv[i], argv[i + 1]});
        }
    }
    bool i{}, o{};
    for (auto &arg:parameters) {
        if (arg.option == "-o" && !o) {
            o = true;
            continue;
        } else if (arg.option == "-i" && !i) {
            i = true;
            continue;
        } else {
            std::cerr << "Incorrect parameters!\n\n";
            printUsage(argv[0]);
            return true;
        }
    }

    return false;
}

void printUsage(const std::string &argv) {
    std::cerr << "Usage: " + argv +
                 " [-i <path>] [-o <path>]\n\n-i input file with lists\n-o output file with lists\n";
}

void normalMode(Tscreen &src, std::deque<TlistSmallS *> &lists, TlistFullS *&ptrFull) {
    const std::string sHelp(
            "q to quit,\n"
            "n to add new list,\n"
            "e to edit list name,\n"
            "r to remove list,\n"
            "number of list to expand it\n\n");

    std::string sInput;
    std::string sInfo = sHelp;

    int nPage{1};
    while (true) {
        src.clearScreen();
        //drawing lists
        if (!ptrFull) {
            for (int i = (constants::nMaxOnPage * (nPage - 1)); (i < lists.size() &&
                                                                 i < constants::nMaxOnPage * nPage); ++i) {
                lists[i]->show();
            }
        } else {
            fullMode(src, ptrFull);
            continue;
        }

        if (lists.size() > constants::nMaxOnPage) {
            sInfo += "Page " + std::to_string(nPage) + " of " +
                     std::to_string((lists.size() - 1) / constants::nMaxOnPage + 1) +
                     ". Use k, l to navigate.\nWhat do you want to do?: ";
        } else {
            sInfo += "What do you want to do?: ";
        }

        src.write(0, constants::nScreenHeight, sInfo);
        src.show();
        std::cin >> sInput;
        sInfo = sHelp;

        if (sInput == "q") { //Save and quit program
            break;
        } else if (sInput == "n") { //Create new list of type TlistSmallS
            std::cout << "Provide a name of new list: ";
            getline((std::cin >> std::ws), sInput, '\n');
            addList(sInput, &src, lists);
        } else if (sInput == "e") {
            std::cout << "Enter a number of a list: ";
            std::cin >> sInput;
            if (Tlist::_nCounter == 0) {
                sInfo += "There is nothing to edit. Try adding new list.\n";
            } else {
                try {
                    int n{std::stoi(sInput)};
                    if (n < 1 || n > Tlist::_nCounter)
                        throw std::exception();
                    std::cout << "Provide a new name for list: ";
                    getline((std::cin >> std::ws), sInput, '\n');
                    changeListName(lists, n, sInput);
                } catch (std::exception &e) {
                    sInfo += "There is no such list.\n";
                }
            }
        } else if (sInput == "r") { //Removing chosen list
            std::cout << "Enter a number of a list: ";
            std::cin >> sInput;
            if (Tlist::_nCounter == 0) {
                sInfo += "There is nothing to delete. Sorry :(\n";
            } else {
                try {
                    int n{std::stoi(sInput)};
                    if (n < 1 || n > Tlist::_nCounter) throw std::exception();
                    removeList(n, lists);
                    if (nPage != 1 && !(Tlist::_nCounter % constants::nMaxOnPage)) nPage--;
                } catch (std::exception &e) {
                    sInfo += "There is no such list.\n";
                }
            }
        } else if (sInput == "k") {
            if (nPage > 1) nPage--;
        } else if (sInput == "l") {
            if (nPage < (lists.size() - 1) / constants::nMaxOnPage + 1) nPage++;
        } else {
            try {
                int n{std::stoi(sInput)};
                if (n < 1 || n > Tlist::_nCounter) throw std::exception();
                ptrFull = switchFullScreen(n, lists);
            } catch (std::exception &e) {
                sInfo += "There is no such list.\n";
            }
        }
    }
}

void fullMode(Tscreen &src, TlistFullS *&ptrFull) {
    const std::string sHelp(
            "q to go back,\n"
            "n to add new task,\n"
            "e to edit task,\n"
            "r to remove task,\n"
            "c to clear done tasks,\n"
            "number of task to mark it\n\n");

    std::string sInput;
    std::string sInfo = sHelp;

    int nPage{1};
    while (true) {
        src.clearScreen();
        //drawing tasks
        ptrFull->show();

        for (int i = (constants::nMaxVisTasks * (nPage - 1)); (i < ptrFull->getTasks()->size() && i < (constants::nMaxVisTasks) * nPage); ++i) {
            ptrFull->showTask(i);
        }
        ptrFull->getScreen()->show();

        if (ptrFull->getTasks()->size() > constants::nMaxVisTasks) {
            sInfo += "Page " + std::to_string(nPage) + " of " +
                     std::to_string((ptrFull->getTasks()->size() - 1) / constants::nMaxVisTasks + 1) +
                     ". Use k, l to navigate.\nWhat do you want to do?: ";
        } else {
            sInfo += "What do you want to do?: ";
        }

        src.write(0, constants::nScreenHeight, sInfo);
        src.show();
        std::cin >> sInput;
        sInfo = sHelp;
        if (sInput == "q") {
            delete ptrFull;
            ptrFull = nullptr;
            break;
        } else if (sInput == "n") {
            std::cout << "Provide a name of new task: ";
            getline((std::cin >> std::ws), sInput, '\n');
            ptrFull->addTask(sInput, false);
        } else if (sInput == "e") {
            std::cout << "Enter a number of a task: ";
            std::cin >> sInput;
            if (ptrFull->getTasks()->empty()) {
                sInfo += "There is nothing to edit. Try adding new task.\n";
            } else {
                try {
                    int n{std::stoi(sInput)};
                    if (n < 1 || n > ptrFull->getTasks()->size())
                        throw std::exception();
                    std::cout << "Provide a new name for task: ";
                    getline((std::cin >> std::ws), sInput, '\n');
                    ptrFull->changeTaskName(n, sInput);
                } catch (std::exception &e) {
                    sInfo += "There is no such task.\n";
                }
            }
        } else if (sInput == "r") {
            std::cout << "Enter a number of a task: ";
            std::cin >> sInput;
            if (ptrFull->getTasks()->empty()) {
                sInfo += "There is nothing to delete. Sorry :(\n";
            } else {
                try {
                    int n{std::stoi(sInput)};
                    if (n < 1 || n > ptrFull->getTasks()->size())
                        throw std::exception();
                    ptrFull->removeTask(n);
                    if (nPage != 1 && !(ptrFull->_nNumberOfTasks % constants::nMaxVisTasks)) nPage--;
                } catch (std::exception &e) {
                    sInfo += "There is no such task.\n";
                }
            }
        } else if (sInput == "c") {
            if (ptrFull->getTasks()->empty()) {
                sInfo += "There is nothing to delete. Sorry :(\n";
            } else {
                ptrFull->clearDone();
                sInfo += "Removed done tasks.\n";
            }
        }else if (sInput == "k") {
            if (nPage > 1) nPage--;
        } else if (sInput == "l") {
            if (nPage < (ptrFull->getTasks()->size() - 1) / constants::nMaxVisTasks + 1) nPage++;
        } else {
            try {
                int n{std::stoi(sInput)};
                if (n < 1 || n > ptrFull->getTasks()->size()) throw std::exception();
                ptrFull->checkTask(n);
            } catch (std::exception &e) {
                sInfo += "There is no such task.\n";
            }
        }
    }
}

TlistFullS *switchFullScreen(int nId, std::deque<TlistSmallS *> &lists) {
    return new TlistFullS(*lists[nId - 1]);
}

void addList(const std::string &sName, Tscreen *ptrScreen, std::deque<TlistSmallS *> &lists) {
    lists.push_back(new TlistSmallS(sName, ptrScreen));
}

void removeList(int nId, std::deque<TlistSmallS *> &lists) {
    nId--;
    auto it = lists.begin();
    while (nId--)
        it++;

    delete *it;
    lists.erase(it);
    int i{1};
    for (auto &list:lists) {
        list->resetId(i);
        i++;
    }
}

void changeListName(std::deque<TlistSmallS *> &lists, int nId, const std::string &sNewName) {
    for (auto &list :lists) {
        if (list->getId() == nId)
            list->setName(sNewName);
    }
}

void clear(std::deque<TlistSmallS *> &lists) {
    for (auto list:lists) {
        delete list;
    }
    std::cout << "\u001B[H\u001B[2J\u001B[3J";
}
