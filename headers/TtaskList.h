//
// Created by Michal on 18.06.2021.
//
//! Class TtaskList, defines list of task. Used only for multiple inheritance.

#ifndef MAIN_CPP_TTASKLIST_H
#define MAIN_CPP_TTASKLIST_H

#include "Ttask.h"
#include <deque>

class TtaskList {
    std::deque<Ttask *> *_tasks; //!< Pointer to container of Ttask pointers.
public:
    size_t _nNumberOfTasks{}; //!< Number of tasks in container.

    //! Default constructor
    TtaskList();

    //! Constructor used for copying.

    //! @param tasks container with tasks
    explicit TtaskList(std::deque<Ttask *> *tasks);

    //! Function for updating the task number.

    //! @param n new number
    void setTasksNumber(size_t n);

    //! Function which returns pointer to container with tasks.

    //! @return container with Ttask pointers
    std::deque<Ttask *> *getTasks() { return _tasks; }

    //! Function for changing name of a task.

    //! @param nId id of task
    //! @param sNewName new name of a task
    void changeTaskName(int nId, const std::string &sNewName);
};


#endif //MAIN_CPP_TTASKLIST_H
