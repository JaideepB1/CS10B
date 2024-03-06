#include <iostream>
#include "minFunc.h"

using namespace std;


const int * min(const int arr[], int arrSize) {
    
    if (arrSize == 0) {
        return nullptr;
    }

    if (arrSize == 1) {
        return arr;
    }

    const int* val = min(arr, arrSize - 1);

    if (*val > arr[arrSize - 1]) {
        val = &(arr[arrSize - 1]);
        return val;
    }

    else {
        return val;
    }
}