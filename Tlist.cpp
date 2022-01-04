//
// Created by Michal on 04.06.2021.
//
#include "headers/Tlist.h"

int Tlist::_nCounter{};

Tlist::Tlist(const std::string &sName, Tscreen *ptrScreen) : _sName(sName), _ptrScreen(ptrScreen) {
    _nCounter++;
    _nId = _nCounter;
}

std::string Tlist::showName(bool resize) {
    std::string sTemp{};
    if (resize) {
        sTemp += std::to_string(this->_nId) + ".";
        sTemp += _sName;
        if (sTemp.length() > constants::nListWidth - 2) {
            sTemp.resize(constants::nListWidth - 5);
            sTemp += "...";
        }
    } else {
        sTemp += _sName;
        if (sTemp.length() > constants::nScreenWidth - 3) {
            sTemp.resize(constants::nScreenWidth - 6);
            sTemp += "...";
        }
    }
    return sTemp;
}

Tlist::~Tlist() {
    _nCounter--;
}

void Tlist::setName(const std::string &sNewName) {
    _sName = sNewName;
}