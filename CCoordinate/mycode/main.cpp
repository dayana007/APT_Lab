/*
 * main.c
 *
 *  Created on: 23 Oct 2016
 *      Author: dayan
 */

#include <iostream>
#include "CCoordinate.h"

using namespace std;


int main()
{
	cout<<"Constructors"<<endl;
	CCoordinate c1(4.0,4.0,4.0);
	CCoordinate c2;
	CCoordinate c3(-4);

	cout<<"Get and set operations"<<endl;
	//float x,y,z;
//	cObj1.getCartesian( x, y, z);
//	cout<< "Cartesian representation (x,y,z) = "<<x<< ","<<y<<","<<z<<endl;
//	cObj2.getCartesian( x, y, z);
//	cout<< "Cartesian representation (x,y,z) = "<<x<< ","<<y<<","<<z<<endl;
//	c1.setCartesian( 1.0, 2.0, 3.0);
//	c1.print(CARTESIAN);
//	cObj1.getCartesian( x, y, z);
//	cout<< "Cartesian representation (x,y,z) = "<<x<< ","<<y<<","<<z<<endl;
//	c2.setCartesian( 10.0, 12.0, 13.0);
//	c2.print(CARTESIAN);
//	cObj2.getCartesian( x, y, z);
//	cout<< "Cartesian representation (x,y,z) = "<<x<< ","<<y<<","<<z<<endl;

	/*Print test*/
	cout<<"Cylindrical and polar conversions"<<endl;
	c1.print(CARTESIAN);
	c2.print(CARTESIAN);
	c3.print(CARTESIAN);
	c1.print(CYLINDER);
	c2.print(CYLINDER);
	c1.print(POLAR);
	c2.print(POLAR);
	c3.print(POLAR);

	cout<<"Addition Operations"<<endl;
	c1.add(c1);
	c1.print(CARTESIAN);
//	cObj1.getCartesian( x, y, z);
//	cout<< "Cartesian representation (x,y,z) = "<<x<< ","<<y<<","<<z<<endl;
	c1.add(c2);
	c1.print(CARTESIAN);

	c1.add(c3);
	c1.print(CARTESIAN);

	c1.add(CCoordinate(1.0,2.0,3.0));
	c1.print(CARTESIAN);
//	cObj1.getCartesian( x, y, z);
//	cout<< "Cartesian representation (x,y,z) = "<<x<< ","<<y<<","<<z<<endl;

	return 0;
}


