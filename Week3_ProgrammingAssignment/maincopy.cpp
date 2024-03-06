#include <iostream>
#include <string>

using namespace std;


string lol(int ans) {
    if ((ans % 2 == 0) || (ans % 3 == 0)) {
        return "lol";
    }

    else {
        return "no lol";
    }
}

int main() {
    int input;

    cin >> input;

    cout << lol(input) << endl;
}