//
// Created by Alan Ćwiek on 2022-01-21.
//

#include <iostream>
#include <fstream>
#include "Log.h"
#include "../common.h"

#ifndef TERM_LOGS
std::streambuf* old = nullptr;
std::filebuf* logfile = nullptr;
#endif

void Log::init() {
#ifndef TERM_LOGS
    logfile = new std::filebuf();
    logfile->open(LOGFILE, std::ios_base::out);
    old = std::cout.rdbuf(logfile);
#endif
    write("Logging started.");
}

void Log::write(const std::string &msg) {
    std::cout << msg << std::endl;
}

void Log::close() {
    write("Ending logging.");
#ifndef TERM_LOGS
    if (old != nullptr) {
        std::cout.rdbuf(old);
        old = nullptr;
    }
    if (logfile != nullptr) {
        logfile->close();
        logfile = nullptr;
    }
#endif
}
