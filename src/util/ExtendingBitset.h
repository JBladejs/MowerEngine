//
// Created by goon on 17.08.2021.
//

#ifndef MOWERENGINE_EXTENDINGBITSET_H
#define MOWERENGINE_EXTENDINGBITSET_H


#include <cstdint>
#include <vector>

class ExtendingBitset {
private:
    std::vector<uint8_t> bytes;
    int size;

    void extend();
public:
    ExtendingBitset();
    void set(int index);
    void unset(int index);
    bool get(int index);
    void clear();
};


#endif //MOWERENGINE_EXTENDINGBITSET_H
