#include <iostream>
#include "Distance.h"
using namespace std;


/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
*/
Distance::Distance() {
    this->_feet = 0;
    this->_inches = 0.0;
}


/* Constructs a distance of ft feet and in inches,
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
    Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(unsigned ft, double in) {
    this->_feet = ft;
    this->_inches = in;
    init();
}


/* Constructs a distance of 0 ft and in inches, 
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
    Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(double in) {
    this->_feet = 0;
    this->_inches = in;

    init();
}


/* Returns just the feet portion of the Distance
*/
unsigned Distance::getFeet() const {
    return _feet;
}


/* Returns just the inches portion of the Distance
*/
double Distance::getInches() const {
    return _inches;
}


/* Returns the entire distance as the equivalent amount of inches.
    (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const {
    return ((_feet * 12.0) + _inches);
}


/* Returns the entire distance as the equivalent amount of feet.
    (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const {
    return ((_feet * 1.0) + (_inches / 12));
}


/* Returns the entire distance as the equivalent amount of meters.
    1 inch equals 0.0254 meters.
    (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const {
    return ((_feet / 3.28084) + (_inches / 39.3701));
}


/* Returns the sum of 2 Distances.
*/
Distance Distance::operator+(const Distance &rhs) const {
    double value;

    value = (this->distanceInInches() + rhs.distanceInInches());
    
    Distance result(value);

    return result;
}


/* Returns the difference between 2 Distances.
*/
Distance Distance::operator-(const Distance &rhs) const {
    double value;

    value = (this->distanceInInches() - rhs.distanceInInches());

    if (value < 0) {
        value = value * (-1);
    }

    Distance result(value);

    return result;
}

/* Outputs to the stream out the Distance in the format: 
   feet' inches'' (i.e. 3' 3.41'')
*/
ostream & operator<<(ostream &out, const Distance &rhs) {
   out << rhs._feet << "' " << rhs._inches << "\"";
   return out;
}

/* Used by the 2 parameterized constructors to convert any negative values to positive and
    inches >= 12 to the appropriate number of feet and inches.
*/
void Distance::init() {
    if (_inches < 0) {
        _inches = _inches * (-1);
    }

    if (_feet < 0) {
        _feet = _feet * (-1);
    }

    while (_inches >= 12) {
        _feet += 1;
        _inches -= 12;
    }
}
