/*! \file CISOtriangle.h
	\brief Declaration of the class ISOtriangle

	Details.
*/


#ifndef ISOSCELES_H
#define ISOSCELES_H

#include<iostream>

#include "triangle.h"

using namespace std;

/// @class ISOtriangle
/// @brief to manage an object with the shape of a ISOtriangle
class ISOtriangle : public Triangle
{
protected:
	float base;
	float side;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	ISOtriangle();
	ISOtriangle(float b, float s);
	ISOtriangle(const ISOtriangle& r);

	~ISOtriangle();
	/// @}

	/// @name OPERATORS
	/// @{
	ISOtriangle& operator=(const ISOtriangle& r);
	bool operator==(const ISOtriangle& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const ISOtriangle& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @
	void SetDim(float b, float s);
	void GetDim(float& b, float& s);

	float GetHeight();
	float GetArea();
	/// @}


	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

#endif

