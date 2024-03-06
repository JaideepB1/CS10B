#include <iostream>
#include "minFunc.h"

using namespace std;

int sum(int arr[], int arrSize) {
    int sumVal = 0;
    cout << arr[arrSize - 1] << " s ";
    if (arrSize > 0) {
        sumVal += arr[arrSize - 1];
        sum(arr, arrSize - 1);
        arrSize += sumVal;
        cout << arrSize << " ";
        cout << arr << endl;
    }

    cout << endl;

    return sumVal;
}


int main() {
   int arrSize;
   cin >> arrSize;
   if (arrSize > 0) {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      int minLoc = sum(arr, arrSize);
    cout << minLoc << " answer " << endl;
   }   
   return 0;
}