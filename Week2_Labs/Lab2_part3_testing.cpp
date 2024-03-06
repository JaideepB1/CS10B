#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
   
   string inputFile;

   cin >> inputFile;
   
   
   // Create input stream and open input csv file.
   ifstream inFS;

   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
    cout << "Error opening " << inputFile << endl;
    return 1;
   }
   
   // Read in integers from input file to vector.
   int inputVal;
   char comma;
   vector<int> avgVal(0);
   inFS >> inputVal;
   avgVal.push_back(inputVal);
   while (inFS >> comma >> inputVal) {
    avgVal.push_back(inputVal);
   }

   for (unsigned i = 0; i < avgVal.size(); i++) {
      cout << avgVal.at(i);
   }
   // Close input stream.
   inFS.close();

   
   return 0;
}