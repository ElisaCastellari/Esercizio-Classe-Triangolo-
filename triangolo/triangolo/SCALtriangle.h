/*! \file SCALtriangle.h
	\brief Declaration of the class SCALtriangle

	Details.
*/


#ifndef SCALTRIANGLE_H
#define SCALTRIANGLE_H

#include<iostream>

#include "triangle.h"

using namespace std;

/// @class SCALtriangle
/// @brief to manage an object with the shape of a SCALtriangle
class SCALtriangle : public Triangle
{
protected:
	float SCALsides[3];
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	SCALtriangle();
	SCALtriangle(float s0, float s1, float s2);
	SCALtriangle(const SCALtriangle& r);

	~SCALtriangle();
	/// @}

	/// @name OPERATORS
	/// @{
	SCALtriangle& operator=(const SCALtriangle& r);
	bool operator==(const SCALtriangle& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const SCALtriangle& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @
	void SetDim(float s0, float s1, float s2);
	void GetDim(float& s0, float& s1, float& s2);

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



