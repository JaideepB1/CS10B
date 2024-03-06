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
    testVector.insert(2, 5);
    testVector.erase(6);
    cout << testVector.front() << " and " << testVector.back() << endl;
    testVector.assign(3, 5);
    testVector.push_back(3);
    testVector.pop_back();
    testVector.resize(15, 1);
    testVector.reserve(16);
    testVector.clear();
    

    return 0;
}