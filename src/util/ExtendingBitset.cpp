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

#pragma clang diagnostic pop