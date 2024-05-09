/// \file SCALtriangle.cpp
///	\brief class SCALtriangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "SCALtriangle.h"

/// @brief default constructor 
SCALtriangle::SCALtriangle() {

	cout << "SCALtriangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param b base of the SCALtriangle
/// @param s side of the SCALtriangle
SCALtriangle::SCALtriangle(float s0, float s1, float s2){

	Init();

	cout << "SCALtriangle - constructor" << endl;

		if (s0 <= 0 || s1 <= 0 || s2 <= 0) {
			WarningMessage("constructor: side should be > 0");
			SetSides(0, 0, 0);
		}
		else if (s0 > s1 + s2 || s1 > s0 + s2 || s2 > s1 + s0) {
			WarningMessage("constructor: this is NOT a triangle");
			SetSides(0, 0, 0);
		}
		else
			SetSides(s0, s1, s2);

	}

/// @brief destructor 
SCALtriangle::~SCALtriangle() {

	cout << "SCALtriangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
SCALtriangle::SCALtriangle(const SCALtriangle& r) {

	cout << "SCALtriangle - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
SCALtriangle& SCALtriangle::operator=(const SCALtriangle& r) {

	cout << "SCALtriangle - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool SCALtriangle::operator==(const SCALtriangle& r) {

	if (r.sides[0] == SCALsides[0] && r.SCALsides[1] == SCALsides[1] && r.SCALsides[2] == SCALsides[2])
		return true;

	return false;
}

/// @brief default initialization of the object
void SCALtriangle::Init() {
	SetDim(0, 0, 0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void SCALtriangle::Init(const SCALtriangle& r) {
	Init();
	SetDim(r.SCALsides[0], r.SCALsides[1], r.SCALsides[2]);
}

/// @brief total reset of the object  
void SCALtriangle::Reset() {

	SetDim(0, 0, 0);

}

/// @brief set side of the object
/// @param b base
/// @param h height
void SCALtriangle::SetDim(float s0, float s1, float s2) {

	SCALsides[0] = s0;
	SCALsides[1] = s1;
	SCALsides[2] = s2;

	return;
}

/// @brief get side of the object
/// @param b base
/// @param h height
void SCALtriangle::GetDim(float &s0, float &s1, float &s2) {

	s0 = SCALsides[0];
	s1 = SCALsides[1];
	s2 = SCALsides[2];

	return;
}

/// @brief computes the area of the object
/// @return the area 
float SCALtriangle::GetArea() {

	float areaSecondPower = (GetSemiPerimeter() * (GetSemiPerimeter() - SCALsides[0]) * (GetSemiPerimeter() - SCALsides[1]) * (GetSemiPerimeter() - SCALsides[2]));
	return sqrt(areaSecondPower);
}
float SCALtriangle::GetHeight() {

	return 2 * GetArea() / SCALsides[0];;
}

/// @brief write an error message 
/// @param string message to be printed
void SCALtriangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- SCALtriangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void SCALtriangle::WarningMessage(const char* string) {

	cout << endl << "WARNING -- SCALtriangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void SCALtriangle::Dump() {
	cout << endl;
	cout << "---SCALtriangle---" << endl;
	cout << endl;

	cout << "side 1 = " << Triangle::sides[0] << endl;
	cout << "side 2 = " << Triangle::sides[1] << endl;
	cout << "side 3 = " << Triangle::sides[2] << endl;

	Triangle::Dump();

	cout << endl;

}