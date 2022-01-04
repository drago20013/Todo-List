//
// Created by Michal on 08.06.2021.
//
#include "headers/Tscreen.h"

Tscreen::Tscreen(const std::string &sTitle, char cBackground) {
    _cBackground = cBackground;
    _sTitle = sTitle;
    clearScreen();
}

void Tscreen::clearScreen() {
    _sContent.clear();
    //filling whole "screen" with background char
    std::string sLine(constants::nScreenWidth - 1, _cBackground);
    sLine += "\n";
    for (int i = 0; i < constants::nScreenHeight; ++i) {
        _sContent += sLine;
    }
    write(static_cast<int>((constants::nScreenWidth - _sTitle.length()) / 2), 0, _sTitle);
}

void Tscreen::show() {
    std::cout << "\u001B[H\u001B[2J\u001B[3J" << _sContent << std::flush;
}

void Tscreen::write(int nX, int nY, const std::string &sContent) {
    _sContent.replace((constants::nScreenWidth * nY) + nX, sContent.length(), sContent);
}