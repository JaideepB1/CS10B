#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void readData(const string& fileName, vector<double>& Angle, vector<double>& Lift) {
    //passes in the name of a file and two empty vectors (double) and stores 
    //in the first vector the flight-path angles (first column) and in the second
    // vector the corresponding coefficients of lift (2nd column). If the file does 
    //not open properly, this function should output an error message and then call
    //the exit function passing it an exit value of 1.

    ifstream InFS;

    InFS.open(fileName);
    if (!InFS.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    double flightPathAngle;
    double coefficientOfLift;

    while (InFS >> flightPathAngle >> coefficientOfLift) {
        Angle.push_back(flightPathAngle);
        Lift.push_back(coefficientOfLift);
    }

    for (unsigned i = 0; i < Angle.size(); i++) {
        cout << Angle.at(i) << endl;
    }

    cout << endl;

    for (unsigned i = 0; i < Lift.size(); i++) {
        cout << Lift.at(i) << endl;
    }

}



double interpolation(double AngleInput, const vector<double>& Angle, const vector<double>& Lift) {
    double ans;

    if (AngleInput == Angle.at(Angle.size() - 1)) {
        ans = Lift.at(Angle.size() - 1);
    }

    for (unsigned i = 0; i + 1 < Angle.size(); i++) {
        if (AngleInput == Angle.at(i)) {
            ans = Lift.at(i);
        }

        else if ((AngleInput > Angle.at(i)) && (AngleInput < Angle.at(i + 1))) {
            ans = Lift.at(i) + ((AngleInput - Angle.at(i)) / (Angle.at(i + 1) - Angle.at(i))) * (Lift.at(i + 1) - Lift.at(i));
        }
    }

    return ans;

}

bool isOrdered(const vector<double>& Angle) {
    bool isOrder = true;
    for (unsigned i = 0; i + 1 < Angle.size(); i++) {
        if (Angle.at(i) > Angle.at(i + 1)) {
            isOrder = false;
        }
    }

    if (isOrder) {
        return true;
    }

    else {
        return false;
    }
}

void reorder(vector<double>& Angle, vector<double>& Lift) {
    bool isOrder = false;
    cout << "I am in reorder function." << endl;
    while (!isOrder) {
        for (unsigned int i = 0; i + 1 < Angle.size(); i++) {
            if (Angle.at(i) > Angle.at(i + 1)) {
                swap(Angle.at(i), Angle.at(i + 1));
                swap(Lift.at(i), Lift.at(i + 1));
            }
        }

        isOrder = true;
        for (unsigned i = 0; i + 1 < Angle.size(); i++) {
            if (Angle.at(i) > Angle.at(i + 1)) {
                isOrder = false;
            }
        }

    }
    cout << "The while loop ran" << endl;
    for (unsigned i = 0; i < Angle.size(); i++) {
        cout << Angle.at(i) << endl;
    }

    
    
}

int main(int argc, char *argv[]) {

    string fileName;
    fileName = argv[1];

    vector<double> AngleNum;
    vector<double> LiftNum;

    double AngleInput;
    string repeatLoop;

    readData(fileName, AngleNum, LiftNum);

    if (!isOrdered(AngleNum)) {
        reorder(AngleNum, LiftNum);
    }

    do {
        cin >> AngleInput;

        if ((AngleInput > AngleNum.at(0)) && (AngleInput < AngleNum.at(AngleNum.size() - 1))) {
            interpolation(AngleInput, AngleNum, LiftNum);
        }
        
        cin >> repeatLoop;

    } while (repeatLoop == "Yes");

    // readData(fileName, AngleNum, LiftNum);

    // cout << endl;
    // cout << endl;
    // cout << endl;

    // if (isOrdered(AngleNum)) {
    //     cout << "Cool" << endl;
    // }

    // else {
    //     cout << "Not cool" << endl;
    // }

    // cout << endl;
    // cout << endl;
    // cout << endl;

    // reorder(AngleNum, LiftNum);

    // cout << endl;
    // cout << endl;
    // cout << endl;

    // double AngleInput;

    // cin >> AngleInput;

    // cout << interpolation(AngleInput, AngleNum, LiftNum) << endl;


    return 0;
}