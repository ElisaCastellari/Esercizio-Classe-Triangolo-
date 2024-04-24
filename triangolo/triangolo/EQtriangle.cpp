/// \file CEQtriangle.cpp
///	\brief class EQtriangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "EQtriangle.h"

/// @brief default constructor 
EQtriangle::EQtriangle() {

	cout << "EQtriangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param s side of the EQtriangle
EQtriangle::EQtriangle(float s) {

	Init();

	cout << "EQtriangle - constructor" << endl;

	if (s <= 0) {
		WarningMessage("constructor: side should be > 0");
		SetDim(0);
	}
	else
		SetDim(s);

}

/// @brief destructor 
EQtriangle::~EQtriangle() {

	cout << "EQtriangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
EQtriangle::EQtriangle(const EQtriangle& r) {

	cout << "EQtriangle - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
EQtriangle& EQtriangle::operator=(const EQtriangle& r) {

	cout << "EQtriangle - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool EQtriangle::operator==(const EQtriangle& r) {

	if (r.side == side)
		return true;

	return false;
}

/// @brief default initialization of the object
void EQtriangle::Init() {
	SetDim(0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void EQtriangle::Init(const EQtriangle& r) {
	Init();
	SetDim(r.side);
}

/// @brief total reset of the object  
void EQtriangle::Reset() {

	SetDim(0);

}

/// @brief set side of the object
/// @param s side
void EQtriangle::SetDim(float s) {

	side = s;
	Triangle::SetSides(s, s, s);

	return;
}

/// @brief get side of the object
/// @param s side
void EQtriangle::GetDim(float& s) {

	s = side;

	return;
}

/// @brief computes the area of the object
/// @return the area 
float EQtriangle::GetArea() {

	return side * GetHeight() /2;
}

float EQtriangle::GetHeight() {

	return sqrt((side * side) - (side * side / 4));
}

/// @brief write an error message 
/// @param string message to be printed
void EQtriangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- EQtriangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void EQtriangle::WarningMessage(const char* string) {

	cout << endl << "WARNING -- EQtriangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void EQtriangle::Dump() {
	cout << endl;
	cout << "---EQtriangle---" << endl;
	cout << endl;

	cout << "Side = " << side << endl;
	cout << "Height = " << GetHeight() << endl;

	Triangle::Dump();

	cout << endl;

}