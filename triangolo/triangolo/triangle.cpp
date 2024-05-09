/// \file triangle.cpp
///	\brief class triangle: implementation of the functions
///
///	Details.
///

#include "triangle.h"

/// @brief default constructor 
Triangle::Triangle() {

	cout << "Triangle - constructor - default" << endl;

	Reset();

}


/// @brief constructor 
/// @param s0, s1, s2 side of the Triangle
Triangle::Triangle(float s0, float s1, float s2) {

	Init();

	cout <<"Triangle - constructor" << endl;

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

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Triangle::Triangle(const Triangle& o) {

	cout << "Triangle - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Triangle::~Triangle() {

	cout << "Triangle - destructor" << endl;
	Reset();

}


/// @brief sets the value of the 3 sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3 
void Triangle::SetSides(float s1, float s2, float s3) {

	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;

	return;

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Triangle& Triangle::operator=(const Triangle& o) {

	return *this;

}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Triangle::operator==(const Triangle& o) {

	return false;
}


/// @brief default initialization of the object
void Triangle::Init() {
	sides[0] = sides[1] = sides[2] = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Triangle::Init(const Triangle& o) {
	Init();
	sides[0] = o.sides[0];
	sides[1] = o.sides[1];
	sides[2] = o.sides[2];

}

/// @brief total reset of the object  
void Triangle::Reset() {
	sides[0] = sides[1] = sides[2] = 0.;

}
/*
/// @brief get the perimeter of the object
/// @return perimeter 
float Triangle::GetHeight() {
	return 2* GetArea() / sides[0];
}
*/

/// @brief get the perimeter of the object
/// @return perimeter 
float Triangle::GetPerimeter() {

	return (sides[0] + sides[1] + sides[2]);

}

/// @brief get the semiperimeter of the object
/// @return semiperimeter 
float Triangle::GetSemiPerimeter() {
	return GetPerimeter() / 2;
}

/*
/// @brief computes the area of the object
/// @brief uses Erone's formula
/// @param areaSecondPower is area^2
/// @return the area 
float Triangle::GetArea() {

	float areaSecondPower = (GetSemiPerimeter() * (GetSemiPerimeter() - sides[0]) * (GetSemiPerimeter() - sides[1]) * (GetSemiPerimeter() - sides[2]));
	return sqrt(areaSecondPower);
}
*/

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
void Triangle::GetSides(float& s0, float& s1, float& s2) {

	s0 = sides[0];
	s1 = sides[1];
	s2 = sides[2];

}

/// @brief write an error message 
/// @param string message to be printed
void Triangle::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Triangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Triangle::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Triangle --";
	cout << string << endl;
	
}


/// @brief for debugging: all about the object
void Triangle::Dump() {

	cout << endl;
	cout << "---Triangle---" << endl;
	cout << endl;
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << endl;

}