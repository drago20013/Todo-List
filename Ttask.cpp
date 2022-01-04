//
// Created by Michal on 04.06.2021.
//

#include <utility>

#include "headers/Ttask.h"

Ttask::Ttask(int nId, std::string sName, bool done) : _nId(nId), _sName(std::move(sName)), _done(done) {}

std::string Ttask::showName(bool resize) {
    std::string sTemp;
    if (!resize) sTemp += std::to_string(_nId) + ".";
    _done ? sTemp += "[x]" : sTemp += "[ ]";
    sTemp += _sName;
    if (resize && sTemp.length() > constants::nListWidth - 2) {
        sTemp.resize(constants::nListWidth - 5);
        sTemp += "...";
    } else if (sTemp.length() > constants::nScreenWidth - 3) {
        sTemp.resize(constants::nScreenWidth - 6);
        sTemp += "...";
    }
    return sTemp;
}

void Ttask::check() {
    _done ? (_done = false) : (_done = true);
}

void Ttask::resetId(int i) {
    _nId = i;
}

void Ttask::setName(const std::string &sNewName) {
    _sName = sNewName;
}
