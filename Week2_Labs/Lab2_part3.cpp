#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];

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

   // Close input stream.
   inFS.close();

   // Get integer average of all values read in.
   int sum = 0;
   double avg;
   for (unsigned i = 0; i < avgVal.size(); i++) {
    sum += avgVal.at(i);
   }
   
   avg = sum / avgVal.size();

   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned i = 0; i < avgVal.size(); i++) {
    avgVal.at(i) -= avg;
   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS;

   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
    cout << "Error opening " << outputFile << endl;
    return 1;
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   
   outFS << avgVal.at(0);
   for (unsigned i = 1; i < avgVal.size(); i++) {
    outFS << ", " << avgVal.at(i);
   }
   
   // Close output stream.
   outFS.close();
   
   
   
   return 0;
}