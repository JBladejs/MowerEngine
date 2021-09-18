//
// Created by goon on 13.08.2021.
//
#ifndef MOWERENGINE_BAG_H
#define MOWERENGINE_BAG_H

//Extending array to use when order is not important

//TODO: implement "empty()"
//TODO: correct this

#include <cstdlib>
#include <algorithm>
#include <cstdint>

template <typename T>
class Bag {
public:
    explicit Bag(int capacity);
    Bag();
    ~Bag();
    uint32_t size() const;
    uint32_t capacity() const;
    void add(const T& element);
    void remove(uint32_t i);
    bool removeElement(const T& element);
    T& get(uint32_t i) const;
    void set(uint32_t i, T value);
    void clear();
    bool contains(T element) const;
private:
    void ensure_capacity(uint32_t size);
    void grow(uint32_t capacity);
    void grow();

private:
    T* data_ptr = nullptr;
    uint32_t data_size = 0;
    uint32_t bag_capacity = 0;
};

template<typename T>
Bag<T>::Bag(int capacity): bag_capacity(capacity) {
    data_ptr = (T*) malloc(bag_capacity * (sizeof(T)));
    data_size = 0;
}

template<typename T>
Bag<T>::Bag(): Bag(64) { }

template<typename T>
uint32_t Bag<T>::size() const{
    return data_size;
}

template<typename T>
uint32_t Bag<T>::capacity() const{
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
void Bag<T>::ensure_capacity(uint32_t size) {
    while (size > bag_capacity) {
        grow();
    }
}

template<typename T>
void Bag<T>::add(const T& element) {
    ensure_capacity(data_size + 1);
    data_ptr[data_size++] = element;
}

template<typename T>
inline void Bag<T>::remove(uint32_t i) {
    data_ptr[i] = data_ptr[--data_size];
}

template<typename T>
inline bool Bag<T>::removeElement(const T& element) {
    for (uint32_t i = 0; i < data_size; i++) {
        if (data_ptr[i] == element) {
            remove(i);
            return true;
        }
    }
    return false;
}

template<typename T>
inline T& Bag<T>::get(uint32_t i) const{
    //TODO: throw exception if it doesn't exist
    return data_ptr[i];
}

template<typename T>
inline void Bag<T>::set(uint32_t i, T value) {
    if (i > bag_capacity) grow(i * 2);
    auto new_size = i + 1;
    if (new_size > data_size) data_size = new_size;
    data_ptr[i] = value;
}

template<typename T>
inline bool Bag<T>::contains(T element) const{
    for (int i = 0; i < data_size; i++) {
        if (element == data_ptr) return true;
    }
    return false;
}

template<typename T>
inline void Bag<T>::clear() {
    data_size = 0;
}

template<typename T>
inline Bag<T>::~Bag() {
    free(data_ptr);
    data_ptr = nullptr;
}

#endif //MOWERENGINE_BAG_H
