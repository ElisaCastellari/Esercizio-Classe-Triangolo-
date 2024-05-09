/*! \file RECTtriangle.h
	\brief Declaration of the class RECTtriangle

	Details.
*/


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>

#include "triangle.h"

using namespace std;

/// @class RECTtriangle
/// @brief to manage an object with the shape of a RECTtriangle
	class RECTtriangle : public Triangle {
	protected:
		float base;
		float height;
	public:

		/// @name CONSTRUCTORS/DESTRUCTOR
		/// @{
		RECTtriangle();
		RECTtriangle(float b, float h);
		RECTtriangle(const RECTtriangle& r);

		~RECTtriangle();
		/// @}

		/// @name OPERATORS
		/// @{
		RECTtriangle& operator=(const RECTtriangle& r);
		bool operator==(const RECTtriangle& r);
		/// @}

		/// @name BASIC HANDLING
		/// @{
		void Init();
		void Init(const RECTtriangle& r);
		void Reset();
		/// @}


		/// @name GETTERS / SETTERS
		/// @
		void SetDim(float b, float h);
		void GetDim(float& b, float& h);

		float GetHeight();
		float GetArea();
		float GetHypotenuse();
		/// @}


		/// @name DEBUG and SERIALIZATION 
		/// @{
		void ErrorMessage(const char* string);
		void WarningMessage(const char* string);
		void Dump();
		/// @}

	};

#endif


