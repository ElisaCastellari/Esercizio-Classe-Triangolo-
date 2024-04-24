#include<iostream>

#include "EQtriangle.h"
#include "ISOtriangle.h"

int main() {
	EQtriangle a(2);
	ISOtriangle d(2, 4);
	ISOtriangle e(-2, -4);
	EQtriangle b;
	b.Dump();
	cout << "the area of triangle a is: " << a.GetArea() << endl;
	cout << "the area of triangle d is: " << d.GetArea() << endl;
	a.Dump();
	a.GetPerimeter();
	//EQtriangle c = a;
	EQtriangle c;
	c = a;
	c.Dump();
	e.Dump();
	d.Dump();
	e = d;
	e.Dump();
	ISOtriangle f = d;

	return 0;
}