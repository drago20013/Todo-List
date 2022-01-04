//
// Created by Michal on 18.06.2021.
//

#include "headers/TtaskList.h"

TtaskList::TtaskList() {
    _tasks = new std::deque<Ttask *>;
}

TtaskList::TtaskList(std::deque<Ttask *> *tasks) : _tasks(new std::deque<Ttask *>(*tasks)) {}

void TtaskList::setTasksNumber(size_t n) {
    _nNumberOfTasks = n;
}

void TtaskList::changeTaskName(int nId, const std::string &sNewName) {
    for(auto &task :*_tasks){
        if(task->getId()==nId)
            task->setName(sNewName);
    }
}
