//
// Created by drago on 6/17/21.
//
//! Class TlistSmallS, defines list which is visible as preview.

#ifndef CPPROJECT_TLISTSMALLS_H
#define CPPROJECT_TLISTSMALLS_H

#include "Tlist.h"
#include "TtaskList.h"

class TlistSmallS : public Tlist, public TtaskList{
    int _nX{}, //!< X coordinate on the screen
        _nY{}; //!< Y coordinate on the screen

public:
    //! Constructor of TlistSmallS.

    //! This constructor is used by FileManager when reading from file.
    //! @param sName name of a list
    //! @param ptrScreen pointer to the Tscreen
    TlistSmallS(const std::string &sName, Tscreen *ptrScreen);

    //! Constructor of TlistSmallS.

    //! This constructor is used by copy constructor of TlistFullS.
    //! @param sName name of a list
    //! @param ptrScreen pointer to Tscreen
    //! @param tasks pointer to container with tasks
    TlistSmallS(const std::string &sName, Tscreen *ptrScreen, std::deque<Ttask*>* tasks);

    //! Overloaded += operator for adding tasks.
    void operator+=(Ttask*);

    //! Function for printing list with tasks.
    void show() override;

    //! Function for adding tasks.

    //! This function is used by FileManager when reading from file.
    //! @param sName name of a task
    //! @param done done/undone state of a task
    void addTask(const std::string &sName, bool done) override;

    //! Function for resetting id.

    //! @param nId new id
    void resetId(int nId) final;

    //! Function for generating output string.

    //! It generates string in proper format for saving in file.
    //! @return generated string
    std::string generateOut() final;

    //! Destructor
    ~TlistSmallS() override;
};


#endif //CPPROJECT_TLISTSMALLS_H
