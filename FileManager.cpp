//
// Created by drago on 6/17/21.
//
/** @file */

#include "headers/FileManager.h"

//! Overloaded << operator for Tlist class
std::ostream &operator<<(std::ostream &o, Tlist &lst) {
    o << lst.generateOut();
    return o;
}

bool FileManager::readFile(std::deque<TlistSmallS *> &lists, Tscreen *ptrScreen, const std::string &fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile) {
        std::cout << "Successfully opened input file: " << fileName << "\n";

        std::string line;

        while (getline(inFile, line)) {
            if (!line.empty()) {

                std::string sListName, sTask;
                bool check{};


                size_t first = line.find(';');
                size_t next = first + 1;
                sListName = line.substr(0, first);
                auto *tmp = new TlistSmallS(sListName, ptrScreen);

                while (true) {
                    first = line.find(';', next);
                    if (first == std::string::npos) { break; }
                    sTask = line.substr(next, first - next);
                    next = first + 1;
                    first = line.find(';', next);
                    check = static_cast<bool>(std::stoi(line.substr(next, first - next)));
                    next = first + 1;
                    tmp->addTask(sTask, check);
                }
                lists.push_back(tmp);
            }
        }
        inFile.close();
    } else {
        return false;
    }
    return true;
}
to_str
bool FileManager::writeFile(std::deque<TlistSmallS *> &lists, const std::string &fileName) {
    std::ofstream outFile;
    outFile.open(fileName);
    if (outFile) {
        for (auto &list:lists) {
            outFile << *list;
        }
        outFile.close();
    } else {
        return false;
    }
    return true;
}
