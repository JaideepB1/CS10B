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
    delete _data;
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

int& IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }

    else {
        return _data[index];
    }
}
    
void IntVector::insert(unsigned index, int value) {

    if (_size >= _capacity) {
            expand();
        }
    
    if (index >= _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    else {

        for (unsigned i = index; i < _size; i++) {
            _data[i + 1] = _data[i];
        }

        _size  += 1;
        _data[index] = value;
    }
    
}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < (_size - 1); i++) {
        _data[i] = _data[i + 1];
    }

    _size -= 1;
}

const int& IntVector::front() const {
    return _data[0];
}

int& IntVector::front() {
    return _data[0];
}

const int& IntVector::back() const {
    return _data[_size - 1];
}

int& IntVector::back() {
    return _data[_size - 1];
}

void IntVector::assign(unsigned size, int value) {
    if (size <= _size) {
        _size = size;
    }

    else if (size > _size) {
        if (size > _capacity) {
            if (((size - _capacity) + _capacity) > (2 * _capacity)) {
                expand(size - _capacity);
                _capacity = size;
                _size = size;
            }

            else {
                expand();
                _capacity *= 2;
                _size = size;
            }
        }

        else {
            _size = size;
        }
    }

    for (unsigned i = 0; i < _size; i++) {
        _data[i] = value;
    }
}

void IntVector::push_back(int value) {
    if (_capacity == 0) {
        expand();
        _capacity = 1;
    }
    
    else if ((_size + 1) > _capacity) {
        expand();
        _capacity *= 2;
    }

    _size += 1;
    _data[_size - 1] = value;
}

void IntVector::pop_back() {
    _size -= 1;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size < _size) {
        _size = size;
    }

    else if (size > _size) {
        if (size > _capacity) {
            if (((size - _capacity) + _capacity) > (2 * _capacity)) {
                expand(size - _capacity);
                _capacity = size;
            }

            else {
                expand();
                _capacity *= 2;
            }
        }
        
        for (unsigned i = _size; i < size; i++) {
            _data[i] = value;
        }
        
        _size = size;

    }
}

void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        expand(n - _capacity);
        _capacity += (n - _capacity);
    }
}

void IntVector::expand() {
    int *holder;
    if (_capacity == 0) {
        holder = new int[1];
        for (unsigned i = 0; i < _size; i++) {
            holder[i] = _data[i];
        }
        delete[] _data;
        _data = holder;
    }

    else {
        holder = new int[2 * _capacity];
        for (unsigned i = 0; i < _size; i++) {
            holder[i] = _data[i];
        }
        delete[] _data;
        _data = holder;
    }
    
}

void IntVector::expand(unsigned amount) {
    int *holder;
    holder = new int[amount + _capacity];
    for (unsigned i = 0; i < _size; i++) {
        holder[i] = _data[i];
    }
    delete[] _data;
    _data = holder;

}