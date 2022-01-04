//
// Created by Michal on 17.06.2021.
//
//! Class TlistFullS, defines list which is currently visible in fullscreen.

#ifndef CPPROJECT_TLISTFULLS_H
#define CPPROJECT_TLISTFULLS_H

#include "TlistSmallS.h"

class TlistFullS : public TlistSmallS {
    TlistSmallS *_ptrSource; //!< pointer to TlistSmallS object from which TlistFullS object was created.
public:
    //! Copy constructor form TlistSmallS object.

    //! @param source source object
    explicit TlistFullS(TlistSmallS &source);

    //! Function for printing list in fullscreen.
    void show() override;

    //! Function for adding task.

    //! @param sName name of a task
    //! @param check true for done task, false for not done
    void addTask(const std::string &sName, bool check) override;

    //! Function for removing task.

    //! @param nId id of task to delete
    void removeTask(int nId);

    //! Function for changing done/undone state.

    //! @param nId id of a task
    void checkTask(int nId);

    //! Function for removing all done tasks.
    void clearDone();

    //! Function for printing task.

    //! @param nId id of task
    void showTask(int nId);

    //! Destructor
    ~TlistFullS() override;
};


#endif //CPPROJECT_TLISTFULLS_H
