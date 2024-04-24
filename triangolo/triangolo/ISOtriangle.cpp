/// \file ISOtriangle.cpp
///	\brief class ISOtriangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "ISOtriangle.h"

/// @brief default constructor 
ISOtriangle::ISOtriangle() {

	cout << "ISOtriangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param b base of the ISOtriangle
/// @param s side of the ISOtriangle
ISOtriangle::ISOtriangle(float b, float s) {

	Init();

	cout << "ISOtriangle - constructor" << endl;

	if (s <= 0 || b <= 0) {
		WarningMessage("constructor: side should be > 0");
		SetDim(0, 0);
	}
	else
		SetDim(b, s);

}

/// @brief destructor 
ISOtriangle::~ISOtriangle() {

	cout << "ISOtriangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
ISOtriangle::ISOtriangle(const ISOtriangle& r) {

	cout << "ISOtriangle - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
ISOtriangle& ISOtriangle::operator=(const ISOtriangle& r) {

	cout << "ISOtriangle - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool ISOtriangle::operator==(const ISOtriangle& r) {

	if (r.side == side && r.base== base)
		return true;

	return false;
}

/// @brief default initialization of the object
void ISOtriangle::Init() {
	SetDim(0, 0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void ISOtriangle::Init(const ISOtriangle& r) {
	Init();
	SetDim(r.base, r.side);
}

/// @brief total reset of the object  
void ISOtriangle::Reset() {

	SetDim(0, 0);

}

/// @brief set side of the object
/// @param b base
/// @param s side
void ISOtriangle::SetDim(float b, float s) {

	base = b;
	side = s;
	Triangle::SetSides(b, s, s);

	return;
}

/// @brief get side of the object
/// @param b base
/// @param s side
void ISOtriangle::GetDim(float& b, float& s) {

	b = base;
	s = side;

	return;
}

/// @brief computes the area of the object
/// @return the area 
float ISOtriangle::GetArea() {

	return (base * (sqrt(side * side - side * side / 4)));
}

/// @brief write an error message 
/// @param string message to be printed
void ISOtriangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- ISOtriangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void ISOtriangle::WarningMessage(const char* string) {

	cout << endl << "WARNING -- ISOtriangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void ISOtriangle::Dump() {
	cout << endl;
	cout << "---ISOtriangle---" << endl;
	cout << endl;

	cout << "Base = " << base << endl;
	cout << "Side = " << side << endl;

	Triangle::Dump();

	cout << endl;

}