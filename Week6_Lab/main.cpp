#include <iostream>
#include "IntVector.h"

using namespace std;

int main() {

    IntVector testVector(10, 3);

    cout << testVector.size() << endl;
    cout << testVector.capacity() << endl;

    if (testVector.empty()) {
        cout << "The Vector is empty" << endl;
    }

    else {
        cout << "The Vector is not empty" << endl;
    }

    cout << testVector.at(3) << " and " << testVector.at(9) << endl;
    cout << testVector.front() << " and " << testVector.back() << endl;
    

    return 0;
}
