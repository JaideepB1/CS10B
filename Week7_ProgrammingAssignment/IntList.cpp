#include <iostream>
#include <stdexcept>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &cpy) {
    this->head = nullptr;
    this->tail = nullptr;
    for (IntNode* newNode = cpy.head; newNode != nullptr; newNode = newNode->next) {
        push_back(newNode->value);
    }
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

void IntList::selection_sort() {
    if (head != nullptr) {
        int minVal;
        int currVal;
        int tempVal;
        for (IntNode* newNode = head; newNode != nullptr; newNode = newNode->next) {
            for (IntNode* newerNode = newNode; newerNode->next != nullptr; newerNode = newerNode->next) {
                minVal = newNode->value;
                currVal = newerNode->next->value;
                if (currVal < minVal) {
                    tempVal = newNode->value;
                    newNode->value = newerNode->next->value;
                    newerNode->next->value = tempVal;
                }
            }
        }
    }
}

void IntList::insert_ordered(int value) {
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
            if (value <= currNode->value) {
                insertNode->next = prevNode->next;
                prevNode->next = insertNode;
                count += 1;
            }
            prevNode = prevNode->next;
        }
    }
    
}

void IntList::remove_duplicates() {
    if (head != nullptr) {
        IntNode* iNode = head;
        while(iNode->next != nullptr) {
            IntNode* pNode = iNode;
            IntNode* cNode = iNode->next;
            while (cNode->next != nullptr) {
                if (iNode->value == cNode->value) {
                    if (cNode == tail) {
                        tail = pNode;
                    }
                    pNode->next = cNode->next;
                    delete cNode;
                }
                cNode = cNode->next;
                pNode = pNode->next;
            }
            if (tail->value == iNode->value) {
                delete cNode;
                tail = pNode;
            }
            iNode = iNode->next;
        }
    }

    for (IntNode* oneNode = head; oneNode != nullptr; oneNode = oneNode->next) {
        for (IntNode* twoNode = head; twoNode != nullptr; twoNode = twoNode->next) {
            IntNode* tempNode = nullptr;
            if ((oneNode->value = twoNode->value) && (oneNode != twoNode)) {
                for (IntNode* threeNode = head; threeNode != nullptr; threeNode = threeNode->next) {
                    if (threeNode->next == twoNode) {
                        tempNode = threeNode;
                    }
                }
                
                if (twoNode->next != nullptr) {
                    tempNode->next = twoNode->next;
                    delete twoNode;
                }
            }
        }
    }
}

void IntList::push_front(int valNum) {
    IntNode* newNode = new IntNode(valNum);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

void IntList::push_back(int value) {
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

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        if (head != nullptr) {
            clear();
        }

        for (IntNode* newNode = rhs.head; newNode != nullptr; newNode = newNode->next) {
            push_back(newNode->value);
        }
    }

    return *this;
} 