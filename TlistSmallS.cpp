//
// Created by drago on 6/17/21.
//

#include "headers/TlistSmallS.h"

TlistSmallS::TlistSmallS(const std::string &sName, Tscreen *ptrScreen) : Tlist(sName, ptrScreen), TtaskList() {
    _nX = (constants::nListWidth + 1) * ((getId() - 1) % constants::nMaxInRow);
    _nY = (constants::nListHeight + 1) * (((getId() - 1) / constants::nMaxInRow) % constants::nMaxInCol) + 1;
//    TlistSmallS::addTask("x: " + std::to_string(_nX), 0);
//    TlistSmallS::addTask("y: " + std::to_string(_nY), 0);
//    TlistSmallS::addTask("id: " + std::to_string(getId()), 0);
}

TlistSmallS::TlistSmallS(const std::string &sName, Tscreen *ptrScreen, std::deque<Ttask *> *tasks) : Tlist(sName,
                                                                                                           ptrScreen),
                                                                                                     TtaskList(tasks) {

}

void TlistSmallS::show() {
    std::string sLine1(" ");
    for (int i = 0; i < constants::nListWidth - 2; ++i) sLine1 += "_";
    sLine1 += " ";
    getScreen()->write(_nX, _nY, sLine1);
    sLine1.replace(0, 1, "|");
    sLine1.replace(sLine1.size() - 1, sLine1.size(), "|");

    std::string sLine2("|");
    for (int i = 0; i < constants::nListWidth - 2; ++i) sLine2 += " ";
    sLine2 += "|";
    for (int i = 1; i < constants::nListHeight - 1; ++i) {
        getScreen()->write(_nX, _nY + i, sLine2);
    }
    getScreen()->write(_nX, _nY + constants::nListHeight - 1, sLine1);

    std::string sTempName = this->showName(true);
    int offsetX = static_cast<int>((constants::nListWidth - sTempName.length()) / 2);
    getScreen()->write(_nX + offsetX, _nY, sTempName);

    size_t n{};
    getTasks()->size() >= constants::nListHeight - 1 ? (n = constants::nListHeight - 3) : (n = getTasks()->size());
    //displaying tasks
    int i{};
    for (; i < n; ++i)
        getScreen()->write(_nX + 1, _nY + i + 1, (*getTasks())[i]->showName(true));
    if (getTasks()->size() >= constants::nListHeight - 1) getScreen()->write(_nX + 1, _nY + i + 1, "...");
    getScreen()->show();
}

void TlistSmallS::resetId(int nId) {
    setId(nId);
    _nX = (constants::nListWidth + 1) * ((getId() - 1) % constants::nMaxInRow);
    _nY = (constants::nListHeight + 1) * (((getId() - 1) / constants::nMaxInRow) % constants::nMaxInCol) + 1;
}

void TlistSmallS::addTask(const std::string &sName, bool done) {
    _nNumberOfTasks++;
    *this += new Ttask(_nNumberOfTasks, sName, done);
}

std::string TlistSmallS::generateOut() {
    std::string tmp{};
    tmp += getName() + ";";
    for (auto &task: *getTasks()) {
        tmp += task->getName() + ";" + std::to_string(task->isDone()) + ";";
    }
    tmp += "\n";
    return tmp;
}

void TlistSmallS::operator+=(Ttask *tsk) {
    getTasks()->push_back(tsk);
}

TlistSmallS::~TlistSmallS() {
    for (auto &task : *getTasks()) {
        delete task;
    }
    delete getTasks();
}
