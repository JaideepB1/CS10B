#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
   vector<int> avgVal(0);
   int input;
   
   for (unsigned i = 0; i < 5; i++) {
    cin >> input;
    avgVal.push_back(input);
   }

   for (unsigned i = 0; i < avgVal.size(); i++) {
    cout << avgVal.at(i);
   }
   return 0;
}