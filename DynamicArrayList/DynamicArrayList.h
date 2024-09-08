#ifndef DYNAMIC_ARRAY_LIST_H
#define DYNAMIC_ARRAY_LIST_H

#include "List.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

class DynamicArrayList : public List {
private:
    int* array;
    int size;
    int capacity;
    
    void resize(double factor) {
        std::cout << "Resizing.. " << std::endl;
        int newCapacity = std::max(5, static_cast<int>(capacity * factor));
        int* newArray = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    DynamicArrayList() : size(0), capacity(5) {
        array = new int[capacity];
    }

    ~DynamicArrayList() override {
        delete[] array;
    }

    int getSize() const {
        return size;
    }
    
    int get(int i) const {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return array[i];
    }

    void addAt(int pos, int value) {
        if (pos < 0 || pos > size) {
            throw std::out_of_range("Invalid position");
        }
        if (size == capacity) {
            resize(1.5);
        }
        for (int i = size; i > pos; i--) {
            array[i] = array[i-1];
        }
        array[pos] = value;
        size++;
    }

    void add(int n) override {
        if (size == capacity) {
            resize(1.5);
        }   
        array[size++] = n;
    }
 
    int remove(int n) override {
        for (int i = 0; i < size; i++) {
            if (array[i] == n) {
                removeAt(i);
                return i + 1;
            }
        }
        return -1;
    }

    int removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            throw std::out_of_range("Invalid position");
        }
        int temp = array[pos];
        for (int i = pos; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        if (size <= capacity * (2.0/3.0) && capacity > 5) {
            resize(0.75);
        }    
        return temp;
    }

    void combine(DynamicArrayList* list2) {
        while (!list2->isEmpty()) {
            add(list2->removeAt(0));
        }
    }

    void removeRange(int start, int end) {
        if (start < 0 || end > size || start > end) {
            throw std::out_of_range("Invalid range");
        }
        std::cout << "Removed: ";
        for (int i = start; i < end; i++) {
            std::cout << removeAt(start) << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void print() const override {
        std::cout << size << "/" << capacity << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // DYNAMIC_ARRAY_LIST_H
