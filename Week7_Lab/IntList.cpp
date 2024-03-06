#include <iostream>
#include <stdexcept>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    while (head != nullptr) {
        IntNode* next = head->next;
        delete head;
        head = next;
    }
}

void IntList::clear() {
    while (head != nullptr) {
        IntNode* next = head->next;
        delete head;
        head = next;
    }
    
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int valNum) {
    IntNode* newNode = new IntNode(valNum);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

void IntList::pop_front() {
    if (head != nullptr) {
        IntNode* newNode = head;
        head = head->next;
        delete newNode;
    }
    
    else {
        tail = nullptr;
    }
}

bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }

    else {
        return false;
    }
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream & out, const IntList &list) {
    if (list.head != nullptr) {
        out << list.head->value;
        for (IntNode* newNode = list.head->next; newNode != nullptr; newNode = newNode->next) {
            out << " " << newNode->value;
        }
    }

    return out;
}