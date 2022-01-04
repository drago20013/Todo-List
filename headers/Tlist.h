//
// Created by Michal on 04.06.2021.
//
//! Abstract class Tlist, defines general idea of a list.
#ifndef CPPROJECT_TLIST_H
#define CPPROJECT_TLIST_H

#include "Tscreen.h"

class Tlist {
    int _nId; //!< Id of a list
    std::string _sName;//!< Name of a list
    Tscreen *_ptrScreen{};//!< Pointer to Tscreen used for printing
public:
    static int _nCounter;//!< Keeps number of existing instances of Tlist derived classes

    //! Constructor for list class.

    //! Initialize class fields and increase number of existing tasks.
    //! @param sName name of list
    //! @param ptrScreen pointer to Tscreen object
    Tlist(const std::string &sName, Tscreen *ptrScreen);

    //! Function returns id of list.

    //! @return value of id
    int getId() const { return _nId; }

    //! Function sets id.

    //!@param nId new id
    void setId(int nId) { _nId = nId; }

    //! Function returns name of a list.

    //! @return name of a list
    std::string getName() { return _sName; }

    //! Function sets new name.

    //! @param sNewName new name
    void setName(const std::string &sNewName);

    //! Function returns pointer to used Tscreen.

    //! @return pointer to Tscreen
    Tscreen *getScreen() { return _ptrScreen; }

    //! Pure virtual function to print itself on screen.
    virtual void show() = 0;

    //! Function for generating name text.

    //! @param resize set to true if printing on TlistSmallS, set to false if printing to TlistFullS
    //! @return  modified string with name
    std::string showName(bool resize);

    //! Pure virtual function for resetting ids.

    //! @param nId new id
    virtual void resetId(int nId) = 0;

    //! Pure virtual function for adding Ttask objects to Tlist derived objects.

    //! @param sName name of a task
    //! @param done true if task is done, false if not
    virtual void addTask(const std::string &sName, bool done) = 0;

    //! Pure Virtual function for generating output for writing to file.

    //! @return  a string in proper format for saving
    virtual std::string generateOut() = 0;

    //! Virtual destructor of Tlist class.

    //! Decreases number of existing lists.
    virtual ~Tlist();
};

#endif //CPPROJECT_TLIST_H