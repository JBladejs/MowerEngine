//
// Created by goon on 17.08.2021.
//

#include "ExtendingBitset.h"

ExtendingBitset::ExtendingBitset() {
    size = 0;
}

void ExtendingBitset::extend() {
    bytes.push_back(0x00);
    size += 8;
}

void ExtendingBitset::set(int index) {
    while (index >= size) extend();
    int byte = index / 8;
    int bit = index % 8;
    bytes[byte] = bytes[byte] | (0x01 << bit);
}

void ExtendingBitset::unset(int index) {
    if (index < size) {
        int byte = index / 8;
        int bit = index % 8;
        bytes[byte] = bytes[byte] & ~(0x01 << bit);
    }
}


bool ExtendingBitset::get(int index) {
    if (index >= size) return false;
    return (bytes[index / 8] >> (index % 8)) & 0x01;
}

void ExtendingBitset::clear() {
    bytes.clear();
    size = 0;
}
