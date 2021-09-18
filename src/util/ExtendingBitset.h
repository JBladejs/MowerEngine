//
// Created by Alan Ćwiek on 17.08.2021.
//

#ifndef MOWERENGINE_EXTENDINGBITSET_H
#define MOWERENGINE_EXTENDINGBITSET_H


#include <cstdint>
#include <vector>
#include <set>

class ExtendingBitset {
private:
    std::vector<uint8_t> bytes;
    uint32_t size;

    void extend();
    uint8_t get_byte(uint32_t index) const;
    void set_byte(uint32_t index, uint8_t byte);
public:
    ExtendingBitset();
    void set(uint32_t index);
    void unset(uint32_t index);
    bool get(uint32_t index) const;
    bool empty() const;
    void clear();
    ExtendingBitset& operator&=(const ExtendingBitset &other);
    bool operator==(const ExtendingBitset &other);
};

inline ExtendingBitset operator&(const ExtendingBitset &a, const ExtendingBitset &b) {
    ExtendingBitset result(a);
    result &= b;
    return result;
}

#endif //MOWERENGINE_EXTENDINGBITSET_H
