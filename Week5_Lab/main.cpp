#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <array>

using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
   double sum = 0.0;

   for (int j = 0; j < arraySize; j++) {
      sum += array[j];
   }

   return sum / arraySize;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index) {
   for (int i = index; i < (arraySize - 1); i++) {
      array[i] = array[i + 1];
   }

   arraySize -= 1;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
   cout << array[0];
   if (arraySize > 1) {
      for (int i = 1; i < arraySize; i++) {
         cout << ", " << array[i];
      }
   }
}


int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string inputFile;
   string outputFile;
   
   inputFile = argv[1];

   // open file and verify it opened

   ifstream inFS;

   inFS.open(inputFile);

   if (!inFS.is_open()) {
    cout << "Error opening " << inputFile << endl;
    return 1;
   }

   // Declare an array of doubles of size ARR_CAP.



   double array[ARR_CAP];

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

   ARR_CAP = 0;
   int i = 0;

   while (inFS >> array[i]) {
      ARR_CAP += 1;
      i += 1;
   }
   

    
   // Call the mean function passing it this array and output the 
   // value returned.

   cout << "Mean: " << mean(array, ARR_CAP) << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int indexVal;
   cout << "Enter index of value to be removed (0 to " << (ARR_CAP - 1) << ") :" << endl;
   cin >> indexVal;

	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(array, ARR_CAP);

   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(array, ARR_CAP, indexVal);
  
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(array, ARR_CAP);

   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(array, ARR_CAP) << endl;

   
	return 0;
}