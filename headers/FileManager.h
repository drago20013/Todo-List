//
// Created by drago on 6/17/21.
//
//! FileManager class for reading/saving from/to file
#ifndef MAIN_CPP_FILEMANAGER_H
#define MAIN_CPP_FILEMANAGER_H

#include <fstream>
#include "TlistSmallS.h"

class FileManager {
public:
    //! Static function for reading from file.

    //! Function parse input data from file, creates objects of type TlistSmallS and puts them into std::deque container.
    //! @param lists container where objects are put
    //! @param ptrScreen pointer to object Tscreen, it's passed to TlistSmallS objects
    //! @param fileName name of file where the data is stored, default name "lists.txt"
    static bool readFile(std::deque<TlistSmallS *> &lists,  Tscreen *ptrScreen, const std::string &fileName = "lists.txt");

    //! Static function for writing to file.

    //! Function saves the lists from container to file.
    //! @param lists container where objects are stored
    //! @param fileName name of file where the data is stored, default name "lists.txt"
    static bool writeFile(std::deque<TlistSmallS *> &lists, const std::string &fileName = "lists.txt");
};

#endif //MAIN_CPP_FILEMANAGER_H
