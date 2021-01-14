//
// Created by JJBla on 1/14/2021.
//

#ifndef MOWERENGINE_MISC_FUNCTIONS_H
#define MOWERENGINE_MISC_FUNCTIONS_H

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
