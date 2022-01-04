//
// Created by Michal on 08.06.2021.
//
//! File with defined constants used in program
#ifndef CPPROJECT_CONSTANTS_H
#define CPPROJECT_CONSTANTS_H

namespace constants {
    constexpr int nListWidth{19};//!< Width of a small list
    constexpr int nListHeight{10};//!< Height of a small list
    constexpr int nScreenWidth{80};//!< Width of a screen
    constexpr int nScreenHeight{25};//!< Height of a screen
    constexpr int nMaxInRow{nScreenWidth / nListWidth};//!< Maximum number of lists in one row
    constexpr int nMaxInCol{(nScreenHeight - 1) / nListHeight};//!< Maximum number of lists in column
    constexpr int nMaxOnPage{nMaxInCol * nMaxInRow};//!< Maximum number of lists on one page
    constexpr int nMaxVisTasks{nScreenHeight - 3};//!< Maximum number of tasks displayed on fullscreen mode
}

#endif //CPPROJECT_CONSTANTS_H