//
// Created by JJBla on 1/14/2021.
//

#ifndef MOWERENGINE_MISC_FUNCTIONS_H
#define MOWERENGINE_MISC_FUNCTIONS_H

#include <GL/gl.h>
#include <vector>
//TODO: add util header
//TODO: find a way to make separate it into header and source
namespace MowerEngine {
    template <typename T>
    bool vector_contains(std::vector<T> vector, T element) {
        if (find(vector.begin(), vector.end(), element) != vector.end())
            return true;
        else
            return false;
    }
}

#endif //MOWERENGINE_MISC_FUNCTIONS_H
