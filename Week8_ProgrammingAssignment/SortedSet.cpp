#include <iostream>
#include <stdexcept>
#include "IntList.h"
#include <ostream>
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() : IntList() {

}

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) {
    
}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy) {
    selection_sort();
    remove_duplicates();
}

SortedSet::~SortedSet() {
    
}


bool SortedSet::in(int value) const{
    for (IntNode* newNode = head; newNode != nullptr; newNode = newNode->next) {
        if (value == newNode->value) {
            return true;
        }
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &rhs) const {
    SortedSet newSet (*this);

    for (IntNode* newNode = rhs.head; newNode != nullptr; newNode = newNode->next) {
        if (!newSet.in(newNode->value)) {
            newSet.push_back(newNode->value);
        }
    }

    return newSet;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) const {
    SortedSet newSet;


    for (IntNode* rhsNode = rhs.head; rhsNode != nullptr; rhsNode = rhsNode->next) {
        for (IntNode* lhsNode = this->head; lhsNode != nullptr; lhsNode = lhsNode->next) {
            if (rhsNode->value == lhsNode->value) {
                newSet.push_back(rhsNode->value);
            }
        }
    }

    newSet.remove_duplicates();

    return newSet;

}


void SortedSet::add(int value) {
    IntNode *insertNode = new IntNode(value);

    if (head == nullptr) {
        push_front(value);
    }

    else if (value <= head->value) {
        push_front(value);
    }

    else if (value >= tail->value) {
        push_back(value);
    }
    
    else {
        int count = 0;
        IntNode* prevNode = head;
        for (IntNode* currNode = prevNode->next; (currNode != nullptr) && (count == 0); currNode = currNode->next) {
            if (value < currNode->value) {
                insertNode->next = prevNode->next;
                prevNode->next = insertNode;
                count += 1;
            }
            prevNode = prevNode->next;
        }
    }
}

void SortedSet::push_front(int value) {
    
    if (head->value != value) {
        IntNode* newNode = new IntNode(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }
        
}

void SortedSet::push_back(int value) {
        
    if (tail->value != value) {
        IntNode* newNode = new IntNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

}

void SortedSet::insert_ordered(int value) {
    IntNode *insertNode = new IntNode(value);

    if (head == nullptr) {
        push_front(value);
    }

    else if (value <= head->value) {
        push_front(value);
    }

    else if (value >= tail->value) {
        push_back(value);
    }
    
    else {
        int count = 0;
        IntNode* prevNode = head;
        for (IntNode* currNode = prevNode->next; (currNode != nullptr) && (count == 0); currNode = currNode->next) {
            if (value < currNode->value) {
                insertNode->next = prevNode->next;
                prevNode->next = insertNode;
                count += 1;
            }
            prevNode = prevNode->next;
        }
    }
}

SortedSet SortedSet::operator|=(const SortedSet &rhs) {
    for (IntNode* newNode = rhs.head; newNode != nullptr; newNode = newNode->next) {
        if (rhs.in(newNode->value)) {
            push_back(newNode->value);
        }
    }
    return *this;
}

SortedSet SortedSet::operator&=(const SortedSet &rhs) {
    for (IntNode* newNode = rhs.head; newNode != nullptr; newNode = newNode->next) {
        if (in(newNode->value) && rhs.in(newNode->value)) {
            push_back(newNode->value);
        }
    }
    return *this;
}
