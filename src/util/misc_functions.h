//
// Created by Alan Ćwiek on 1/14/2021.
//

#ifndef MOWERENGINE_MISC_FUNCTIONS_H
#define MOWERENGINE_MISC_FUNCTIONS_H

#include <GL/gl.h>
#include <vector>
//TODO: add util namespace
template<typename T>
inline bool vector_contains(std::vector<T> vector, T element) {
    if (find(vector.begin(), vector.end(), element) != vector.end())
        return true;
    else
        return false;
}


#endif //MOWERENGINE_MISC_FUNCTIONS_H
