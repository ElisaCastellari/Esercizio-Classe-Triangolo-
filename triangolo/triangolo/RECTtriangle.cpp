/// \file RECTtriangle.cpp
///	\brief class RECTtriangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "RECTtriangle.h"

/// @brief default constructor 
RECTtriangle::RECTtriangle() {

	cout << "RECTtriangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param b base of the RECTtriangle
/// @param s side of the RECTtriangle
RECTtriangle::RECTtriangle(float b, float h) {

	Init();

	cout << "RECTtriangle - constructor" << endl;

	if (h <= 0 || b <= 0) {
		WarningMessage("constructor: side should be > 0");
		SetDim(0, 0);
	}
	else
		SetDim(b, h);

}

/// @brief destructor 
RECTtriangle::~RECTtriangle() {

	cout << "RECTtriangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
RECTtriangle::RECTtriangle(const RECTtriangle& r) {

	cout << "RECTtriangle - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
RECTtriangle& RECTtriangle::operator=(const RECTtriangle& r) {

	cout << "RECTtriangle - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool RECTtriangle::operator==(const RECTtriangle& r) {

	if (r.height == height && r.base == base)
		return true;

	return false;
}

/// @brief default initialization of the object
void RECTtriangle::Init() {
	SetDim(0, 0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void RECTtriangle::Init(const RECTtriangle& r) {
	Init();
	SetDim(r.base, r.height);
}

/// @brief total reset of the object  
void RECTtriangle::Reset() {

	SetDim(0, 0);

}

/// @brief set side of the object
/// @param b base
/// @param h height
void RECTtriangle::SetDim(float b, float h) {

	base = b;
	height = h;
	Triangle::SetSides(b, h, GetHypotenuse());

	return;
}

/// @brief get side of the object
/// @param b base
/// @param h height
void RECTtriangle::GetDim(float& b, float& h) {

	b = base;
	h = height;

	return;
}

/// @brief computes the area of the object
/// @return the area 
float RECTtriangle::GetArea() {

	return (base * GetHeight() / 2);
}

float RECTtriangle::GetHeight() {

	return height;
}

float RECTtriangle::GetHypotenuse() {

	return sqrt((base * base) + (height * height));
}

/// @brief write an error message 
/// @param string message to be printed
void RECTtriangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- RECTtriangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void RECTtriangle::WarningMessage(const char* string) {

	cout << endl << "WARNING -- RECTtriangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void RECTtriangle::Dump() {
	cout << endl;
	cout << "---RECTtriangle---" << endl;
	cout << endl;

	cout << "Base = " << base << endl;
	cout << "Height = " << height << endl;
	cout << "Hypotenuse = " << GetHypotenuse() << endl;

	Triangle::Dump();

	cout << endl;

}