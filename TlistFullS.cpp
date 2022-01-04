//
// Created by Michal on 17.06.2021.
//

#include "headers/TlistFullS.h"

TlistFullS::TlistFullS(TlistSmallS &source) : TlistSmallS(source.getName(), source.getScreen(), source.getTasks()) {
    TtaskList::setTasksNumber(source.getTasks()->size());
    _ptrSource = &source;
}

void TlistFullS::show() {
    getScreen()->clearScreen();
    std::string sLine1(" ");
    for (int i = 0; i < constants::nScreenWidth - 3; ++i) sLine1 += "_";
    sLine1 += " ";
    getScreen()->write(0, 1, sLine1);
    sLine1.replace(0, 1, "|");
    sLine1.replace(sLine1.size() - 1, sLine1.size(), "|");

    std::string sLine2("|");
    for (int i = 0; i < constants::nScreenWidth - 3; ++i) sLine2 += " ";
    sLine2 += "|";
    for (int i = 1; i < constants::nScreenHeight - 2; ++i) {
        getScreen()->write(0, 1 + i, sLine2);
    }
    getScreen()->write(0, constants::nScreenHeight - 1, sLine1);

    std::string sTempName = this->showName(false);
    int offsetX = static_cast<int>((constants::nScreenWidth - sTempName.length()) / 2);
    getScreen()->write(offsetX, 1, sTempName);
}

void TlistFullS::showTask(int nId) {
    getScreen()->write(1, nId % constants::nMaxVisTasks + 2, (*getTasks())[nId]->showName(false));
}

void TlistFullS::addTask(const std::string &sName, bool check) {
    _nNumberOfTasks++;
    getTasks()->push_back(new Ttask(_nNumberOfTasks, sName, check));
}

void TlistFullS::checkTask(int nId) {
    getTasks()->at(nId - 1)->check();
}

void TlistFullS::removeTask(int nId) {
    _nNumberOfTasks--;
    nId--;
    auto it = getTasks()->begin();
    while (nId--)
        it++;

    delete *it;
    getTasks()->erase(it);
    int i{1};
    for (auto &task:*getTasks()) {
        task->resetId(i);
        i++;
    }
}

void TlistFullS::clearDone() {
    for (size_t i = _nNumberOfTasks; i > 0; i--) {
        if (getTasks()->at(i - 1)->isDone())
            removeTask(getTasks()->at(i - 1)->getId());
    }
}

TlistFullS::~TlistFullS() {
    _ptrSource->getTasks()->resize(0);
    _ptrSource->_nNumberOfTasks = 0;
    for (auto &task:*this->getTasks()) {
        _ptrSource->addTask(task->getName(), task->isDone());
    }
}
