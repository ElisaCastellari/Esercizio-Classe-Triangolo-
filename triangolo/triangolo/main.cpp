#include<iostream>

#include "Trequilatero.h"

int main() {
	EQtriangle a(2);
	EQtriangle b;
	b.Dump();
	cout << "the area of triangle a is: " << a.GetArea() << endl;
	a.Dump();
	a.GetPerimeter();
	//EQtriangle c = a;
	EQtriangle c;
	c = a;
	c.Dump();
	return 0;
}