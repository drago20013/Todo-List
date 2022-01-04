//
// Created by Michal on 04.06.2021.
//
//! Class Ttask, defines single task.
#ifndef CPPROJECT_TTASK_H
#define CPPROJECT_TTASK_H

#include <string>
#include "constants.h"

class Ttask {
    int _nId; //!< Id of a task.
    std::string _sName; //!< Name of a task.
    bool _done{}; //!< Done/Undone state of a task.

public:
    //! Constructor

    //! @param nId id of a task
    //! @param sName name of a task
    //! @param done done/undone state
    Ttask(int nId, std::string sName, bool done);

    //! Function which returns name of a task.

    //! @return name of a task
    std::string getName() { return _sName; }

    //! Function for setting name of a task.

    //! @param sNewName new name
    void setName(const std::string& sNewName);

    //! Function for resetting id.

    //! @param i new id
    void resetId(int i);

    //! Function which returns id of a task.

    //! @return id of a task
    int getId() const { return _nId; }

    //! Function which returns state of task.

    //! @return done/undone state of a task
    bool isDone() const { return _done; }

    //! Function which returns name of task in proper format.

    //! @param resize true if you want resized name
    //! @return modified name
    std::string showName(bool resize = false);

    //! Function for changing done/undone state.
    void check();
};


#endif //CPPROJECT_TTASK_H
