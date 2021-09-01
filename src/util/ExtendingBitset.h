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
    uint32_t size;

    void extend();
public:
    ExtendingBitset();
    void set(uint32_t index);
    void unset(uint32_t index);
    bool get(uint32_t index);
    void clear();
    ExtendingBitset operator&(const ExtendingBitset &other) const;
};


#endif //MOWERENGINE_EXTENDINGBITSET_H
