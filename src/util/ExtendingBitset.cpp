//
// Created by goon on 17.08.2021.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

#include "ExtendingBitset.h"

ExtendingBitset::ExtendingBitset() {
    size = 0;
}

void ExtendingBitset::extend() {
    bytes.push_back(0x00);
    size += 8;
}

void ExtendingBitset::set(uint32_t index) {
    while (index >= size) extend();
    uint32_t byte = index / 8;
    uint32_t bit = index % 8;
    bytes[byte] = bytes[byte] | (0x01 << bit);
}

void ExtendingBitset::unset(uint32_t index) {
    if (index < size) {
        uint32_t byte = index / 8;
        uint32_t bit = index % 8;
        bytes[byte] = bytes[byte] & ~(0x01 << bit);
    }
}


bool ExtendingBitset::get(uint32_t index) {
    if (index >= size) return false;
    return (bytes[index / 8] >> (index % 8)) & 0x01;
}

void ExtendingBitset::clear() {
    bytes.clear();
    size = 0;
}

ExtendingBitset ExtendingBitset::operator&(const ExtendingBitset &other) const {
    auto result = ExtendingBitset();

    uint32_t this_elements = bytes.size();
    //TODO: check if this copies the "other" bitset
    uint32_t other_elements = other.bytes.size();
    uint32_t elements = std::max(this_elements, other_elements);
    uint8_t a, b;

    for (uint32_t i = 0; i < elements; i++) {
        if (i > this_elements) a = 0x00;
        else a = bytes[i];
        if (i > other_elements) b = 0x00;
        else b = other.bytes[i];

        result.bytes.push_back(a & b);
        result.size += 8;
    }

    return result;
}

#pragma clang diagnostic pop