//
// Created by goon on 13.08.2021.
//

#ifndef MOWERENGINE_BAG_H
#define MOWERENGINE_BAG_H

//Extending array to use when order is not important

#include <cstdlib>
#include <algorithm>

template <typename T>
class Bag {
private:
    T* data_ptr = nullptr;
    int data_size = 0;
    int bag_capacity = 0;
public:
    explicit Bag(int capacity);
    Bag();
    ~Bag();
    int size();
    int capacity();
    void add(T element);
    void remove(int i);
    void removeElement(T element);
    T get(int i);
    void clear();
    bool contains(T element);
private:
    void ensureCapacity(int size);
    void grow(int capacity);
    void grow();
};


template<typename T>
Bag<T>::Bag(int capacity): bag_capacity(capacity) {
    data_ptr = (T*) malloc(bag_capacity * (sizeof(T)));
    data_size = 0;
}

template<typename T>
Bag<T>::Bag(): Bag(64) { }

template<typename T>
int Bag<T>::size() {
    return data_size;
}

template<typename T>
int Bag<T>::capacity() {
    return bag_capacity;
}

template<typename T>
void Bag<T>::grow(int capacity) {
    data_ptr = (T*) realloc(data_ptr, capacity * sizeof(T));
    bag_capacity = capacity;
}

template<typename T>
void Bag<T>::grow() {
    grow(data_size * 3 / 2 + 1);
}

template<typename T>
void Bag<T>::ensureCapacity(int size) {
    if (size > bag_capacity) {
        grow();
    }
}

template<typename T>
void Bag<T>::add(T element) {
    ensureCapacity(data_size + 1);
    data_ptr[data_size++] = element;
}

template<typename T>
void Bag<T>::remove(int i) {
    data_ptr[i] = data_ptr[--data_size];
}

template<typename T>
void Bag<T>::removeElement(T element) {
    for (int i = 0; i < data_size; i++) {
        T e = data_ptr[i];
        if (e == element) {
            remove(i);
        }
    }
}

template<typename T>
T Bag<T>::get(int i) {
    return data_ptr[i];
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
    for (int i = 0; i < data_size; i++) {
        delete data_ptr[i];
    }
    data_size = 0;
}

template<typename T>
Bag<T>::~Bag() {
    free(data_ptr);
    data_ptr = nullptr;
}

#endif //MOWERENGINE_BAG_H
