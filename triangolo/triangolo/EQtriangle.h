/*! \file CEQtriangle.h
	\brief Declaration of the class EQtriangle

	Details.
*/


#ifndef EQUILATERAL_H
#define EQUILATERAL_H

#include<iostream>

#include "triangle.h"

using namespace std;

/// @class EQtriangle
/// @brief to manage an object with the shape of a EQtriangle
class EQtriangle : public Triangle
{
protected:
	float side;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	EQtriangle();
	EQtriangle(float s);
	EQtriangle(const EQtriangle& r);

	~EQtriangle();
	/// @}

	/// @name OPERATORS
	/// @{
	EQtriangle& operator=(const EQtriangle& r);
	bool operator==(const EQtriangle& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const EQtriangle& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float s);
	void GetDim(float& s);

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
