#pragma once

#include <stdexcept>
#include <initializer_list>
#include <iostream>
#include <sstream>

template<typename T>
class Array {
public:
    Array(int size);
    Array(std::initializer_list<T> initList);
    ~Array();

    T& operator[](int index);
    void insert(int index, T value);
    void remove(int index);
    int getSize() const;
    void display();

private:
    void resize(int newCapacity);

    T* data;
    /// @brief The amount of elements the array is currently holding.
    int size;
    /// @brief The amount of elements the array can hold.  
    int capacity;

};

// Implementation

template<typename T>
Array<T>::Array(int size) : size(0), capacity(size){
    data = new T[capacity];
}

template<typename T>
Array<T>::Array(std::initializer_list<T> initList) : size(initList.size()), capacity(initList.size()){
    data = new T[capacity];
    int i = 0;
    for (const T& value : initList){
        data[i++] = value;
    }
    // Show array
    display();
}

template<typename T>
Array<T>::~Array(){
    delete[] data;
}

template<typename T>
T& Array<T>::operator[](int index){
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of range");
    }
    if (index >= size) {
        size = index + 1;
    }
    return data[index];
}

template<typename T>
void Array<T>::insert(int index, T value){
    // Don't allow insertions passed uninitialized elements 
   if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range - you cannot insert pass uninitialized elements.");
    }
    if (size == capacity) {
        //resize(capacity * 2);
        throw std::out_of_range("Index out of range - you reached the max capacity");
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

template<typename T>
void Array<T>::remove(int index){
    if (index < 0 || index > size){
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++){
        data[i] = data[i + 1];
    }
    size--;
}

template<typename T>
int Array<T>::getSize() const{
    return size;
}

template<typename T>
void Array<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
void Array<T>::display() {
    if (size > 0){
        std::stringstream ss;
        ss << "\t<Array>[";
        for (int i = 0; i < size; i++){
            ss << data[i];
            if (i < size - 1){
                ss << ", ";
            }
        }
        ss << "]";
        std::cout << ss.str() << std::endl;
        return;
    }
    std::cout << "\t[System] The array is empty!" << std::endl;
}