#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    this->_size = capacity;
    this->_capacity = capacity;

    if (_size == 0) {
        _data = nullptr;
    }

    else {
        _data = new int[capacity];
        for (unsigned i = 0; i < _size; i++) {
            _data[i] = value;
        }
    }
}

IntVector::~IntVector() {

}

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    if (_size == 0) {
        return true;
    }

    else {
        return false;
    }
}

const int& IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }

    else {
        return _data[index];
    }
}

const int& IntVector::front() const {
    return _data[0];
}

const int& IntVector::back() const {
    return _data[_capacity - 1];
}