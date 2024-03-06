#include "IntList.h"
#include "SortedSet.h"
#include <iostream>

using namespace std;

int main() {
    IntList valList2;

    valList2.push_back(25);
    valList2.push_back(29);
    valList2.push_back(14);
    valList2.push_back(7);
    valList2.push_back(8);

    IntList valList;

    valList.push_back(25);
    valList.push_back(36);

    SortedSet valSet2 = SortedSet(valList2);

    SortedSet valSet3 = SortedSet(valList);

    valSet3.add(3);

    valSet3.push_front(4);
}