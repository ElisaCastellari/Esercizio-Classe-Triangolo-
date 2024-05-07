#include<iostream>

#include "EQtriangle.h"
#include "ISOtriangle.h"
#include "RECTtriangle.h"


int main() {
	EQtriangle a(2);
	ISOtriangle d(2, 4);
	ISOtriangle e(-2, -4);
	EQtriangle b;
	Triangle* aptr;
	aptr = &a;
	b.Dump();
	cout << "the area of triangle a is: " << a.GetArea() << endl;
	cout << "the area of triangle a with otr is: " << aptr->Triangle::GetArea() << endl;
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
	RECTtriangle g(1, 3);
	g.Dump();
	Triangle h (1, 2, 5);
	h.Dump();
	cout << "the area of triangle h is: " << h.GetArea() << endl;
	cout << "the area of triangle h with triangle is: " << h.Triangle::GetArea() << endl;
	cout << "the height of triangle h is: " << h.GetHeight() << endl;
	ISOtriangle error(10, 2);
	error.Dump();
	Triangle bello(5, 5, 5);
	bello.Dump();
	cout << "the area of triangle bello is: " << bello.GetArea() << endl;


	return 0;
}