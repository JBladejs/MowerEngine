//
// Created by goon on 17.08.2021.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

#include "ExtendingBitset.h"

uint8_t ExtendingBitset::get_byte(uint32_t index) const {
    if (index >= bytes.size()) return 0x00;
    else return bytes[index];
}

void ExtendingBitset::set_byte(uint32_t index, uint8_t byte) {
    if (index >= bytes.size()) {
        if (index > bytes.size()) {
            uint32_t elements_to_be_added = index - bytes.size();
            for (uint32_t i = 0; i < elements_to_be_added; i++)
                bytes.push_back(0x00);
        }
        bytes.push_back(byte);
    } else bytes[index] = byte;
}

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


bool ExtendingBitset::get(uint32_t index) const {
    if (index >= size) return false;
    return (bytes[index / 8] >> (index % 8)) & 0x01;
}

void ExtendingBitset::clear() {
    bytes.clear();
    size = 0;
}

ExtendingBitset &ExtendingBitset::operator&=(const ExtendingBitset &other) {
    uint32_t elements = std::max(bytes.size(), other.bytes.size());

    for (uint32_t i = 0; i < elements; i++)
        set_byte(i, get_byte(i) & other.get_byte(i));
    return *this;
}

bool ExtendingBitset::operator==(const ExtendingBitset &other) {
    uint32_t elements = std::max(bytes.size(), other.bytes.size());

    for (uint32_t i = 0; i < elements; i++)
        if (get_byte(i) != other.get_byte(i)) return false;
    return true;
}

#pragma clang diagnostic pop