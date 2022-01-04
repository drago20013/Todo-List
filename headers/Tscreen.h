//
// Created by Michal on 04.06.2021.
//

//! Class Tscreen, defines screen/display, based on Opus Magnum C++11 J. Grębosz.

#ifndef CPPROJECT_TSCREEN_H
#define CPPROJECT_TSCREEN_H

#include <iostream>
#include <string>
#include <list>
#include "constants.h"

class Tscreen {
    std::string _sContent; //!< Content of a screen, what will be displayed.
    std::string _sTitle; //!< Title of the screen.
    char _cBackground; //!< Background of screen, default " ", can be changed to "." for example.
public:
    //! Constructor.

    //! @param sTitle title of a screen
    //! @param cBackground background char
    explicit Tscreen(const std::string& sTitle,char cBackground = ' ');

    //! Function for clearing screen
    void clearScreen();

    //! Function for printing content
    void show();

    //! Function for putting some string in right place on screen

    //! @param nX X coordinate
    //! @param nY Y coordinate
    //! @param sContent content
    void write(int nX, int nY, const std::string &sContent);
};


#endif //CPPROJECT_TSCREEN_H
