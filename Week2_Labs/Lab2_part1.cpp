#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//Collaborated with Khang Hyunh (Khuyn102)

int fileSum (string fileName) {
ifstream SumFS;

SumFS.open(fileName);
if (!SumFS.is_open()) {
    cout << "Error opening " << fileName << endl;
    exit(EXIT_FAILURE);
}

int Sum = 0;
int Value;


while (SumFS >> Value) {
Sum += Value;
}

SumFS.close();

return Sum;

}

int main()
{
    string fileName;
    cout << "Enter the name of the input file: " << endl;
    cin >> fileName;

    int sumVal;

    sumVal = fileSum(fileName);



    cout << "Sum: " << sumVal  << endl;



    return 0;
}