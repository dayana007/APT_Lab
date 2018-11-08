//============================================================================
// Name        : CWaypoint.cpp
// Author      : dayana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CWaypoint.h"
using namespace std;

int main()
{
    CWaypoint();
	CWaypoint CWaPo1(20.5937,78.9629,"INDIA");
		//CWaPo1.set("INDIA",50.55,90.99);
	CWaypoint CWaPo2(52.3702,4.8952,"AMSTERDAM");
	CWaypoint CWaPo3(49.8728,8.6512,"DARMSTADT");
	CWaypoint CWaPo4(52.5166,13.4,"BERLIN");
	CWaypoint CWaPo5(35.6895,139.6917,"TOKYO");
	CWaypoint newWayPoint();
	CWaPo2.print(1);
	CWaPo4.print(2);
	CWaPo4.getName();
	CWaPo4.getLatitude();
	CWaPo4.getLongitude();
	string name;
	double latitude,longitude;

	/* The addresses of local variables passed in main file to get function is same as
	* addresses of the parameters used inside the function as the parameters are passed
	* by reference to the function
	*/

	cout<<"Address of local variable name "<<&name<<endl;
	cout<<"Address of local variable latitude "<<&latitude<<endl;
	cout<<"Address of local variable longitude "<<&longitude<<endl;
	CWaPo4.getAllDataByReference(name,latitude,longitude);
	CWaPo2.calculateDistance(CWaPo4);
	CWaPo5.calculateDistance(CWaPo4);
	CWaPo5.~CWaypoint();
}
