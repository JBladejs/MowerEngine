//
// Created by goon on 13.08.2021.
//
#pragma once

#ifndef MOWERENGINE_BAG_H
#define MOWERENGINE_BAG_H

//Extending array to use when order is not important

//TODO: implement "empty()"
//TODO: implement shrinking
#include <cstdlib>
#include <algorithm>
#include <cstdint>

template <typename T>
class Bag {
private:
    T* data_ptr = nullptr;
    uint32_t data_size = 0;
    uint32_t bag_capacity = 0;
public:
    explicit Bag(int capacity);
    Bag();
    ~Bag();
    uint32_t size();
    uint32_t capacity();
    void add(T element);
    void remove(uint32_t i);
    bool removeElement(T element);
    T get(uint32_t i);
    void set(uint32_t i, T value);
    void clear();
    bool contains(T element);
private:
    void ensureCapacity(uint32_t size);
    void grow(uint32_t capacity);
    void grow();
};

//TODO: change from malloc to new

template<typename T>
Bag<T>::Bag(int capacity): bag_capacity(capacity) {
    data_ptr = (T*) malloc(bag_capacity * (sizeof(T)));
    data_size = 0;
}

template<typename T>
Bag<T>::Bag(): Bag(64) { }

template<typename T>
uint32_t Bag<T>::size() {
    return data_size;
}

template<typename T>
uint32_t Bag<T>::capacity() {
    return bag_capacity;
}

template<typename T>
void Bag<T>::grow(uint32_t capacity) {
    data_ptr = (T*) realloc(data_ptr, capacity * sizeof(T));
    bag_capacity = capacity;
}

template<typename T>
void Bag<T>::grow() {
    grow(data_size * 3 / 2 + 1);
}

template<typename T>
void Bag<T>::ensureCapacity(uint32_t size) {
    while (size > bag_capacity) {
        grow();
    }
}

template<typename T>
void Bag<T>::add(T element) {
    ensureCapacity(data_size + 1);
    data_ptr[data_size++] = element;
}

template<typename T>
void Bag<T>::remove(uint32_t i) {
    data_ptr[i] = data_ptr[--data_size];
}

template<typename T>
bool Bag<T>::removeElement(T element) {
    for (uint32_t i = 0; i < data_size; i++) {
        if (data_ptr[i] == element) {
            remove(i);
            return true;
        }
    }
    return false;
}

template<typename T>
T Bag<T>::get(uint32_t i) {
    return data_ptr[i];
}

template<typename T>
void Bag<T>::set(uint32_t i, T value) {
    if (i > bag_capacity) grow(i * 2);
    auto new_size = i + 1;
    if (new_size > data_size) data_size = new_size;
    data_ptr[i] = value;
}

template<typename T>
bool Bag<T>::contains(T element) {
    for (int i = 0; i < data_size; i++) {
        if (element == data_ptr) return true;
    }
    return false;
}

template<typename T>
void Bag<T>::clear() {
    data_size = 0;
}

template<typename T>
Bag<T>::~Bag() {
    free(data_ptr);
    data_ptr = nullptr;
}

#endif //MOWERENGINE_BAG_H
