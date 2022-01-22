//
// Created by Alan Ćwiek on 2022-01-21.
//

#ifndef MOWERENGINE_LOG_H
#define MOWERENGINE_LOG_H


#include <string>

namespace Log {
    void init();
    void write(const std::string &msg);
    void close();
}


#endif //MOWERENGINE_LOG_H
