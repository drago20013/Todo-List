//
// Created by drago on 6/24/21.
//
//! Main functions are defined here.
/** @file functions.h */

#ifndef CPPROJECT_FUNCTIONS_H
#define CPPROJECT_FUNCTIONS_H

#include <vector>
#include <cstring>
#include "FileManager.h"
#include "TlistFullS.h"

//! Structure which helps to manage input on program startup
struct parameter{
    std::string option; //!< the switch option
    std::string value; //!< the program argument
};

//! Function for verifying start parameters.

//! @param argc number of parameters
//! @param argv array of chars
//! @param parameters vector of parameters
//! @return true if everything is correct, false otherwise
bool verifyParameters(int argc, char **argv, std::vector<parameter> &parameters);

//! Function or printing help message.

//! @param argv program name
void printUsage(const std::string &argv);

//! Function for displaying TlistSmallS lists and managing user input.

//! @param lists container with lists
//! @param src screen where to display
//! @param ptrFull pointer for current TlistFullS object
void normalMode(Tscreen &src, std::deque<TlistSmallS *> &lists, TlistFullS *&ptrFull);

//! Function for displaying TlistFullS object and managing user input.

//! @param src screen where to display
//! @param ptrFull pointer for current TlistFullS object
void fullMode(Tscreen &src, TlistFullS *&ptrFull);

//! Function for switching to fullscreen.

//! it creates a new TlistFullS object from TlistSmallS object
//! @param nId id of a list we want to see in fullscreen
//! @param lists container with TlistSmallS lists
//! @return new object of class TlistFullS
TlistFullS *switchFullScreen(int nId, std::deque<TlistSmallS *> &lists);

//! Function for adding new list to container

//! it creates new object of TlistSmallS and puts it in container
//! @param sName name for the list
//! @param ptrScreen pointer to Tscreen object
//! @param lists container with lists
void addList(const std::string &sName, Tscreen *ptrScreen, std::deque<TlistSmallS *> &lists);

//! Function for removing list from container.

//! @param nId id of list we want to remove
//! @param lists container with lists
void removeList(int nId, std::deque<TlistSmallS *> &lists);

//! Function for changing name of a list

//! @param lists container with lists
//! @param nId id of list
//! @param sNewName new name for list
void changeListName(std::deque<TlistSmallS *> &lists, int nId, const std::string &sNewName);

//! Function for clearing memory at the end of program

//! @param lists container with lists
void clear(std::deque<TlistSmallS *> &lists);

#endif //CPPROJECT_FUNCTIONS_H
