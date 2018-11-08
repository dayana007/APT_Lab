/*
 * main.cpp
 *
 *  Created on: 24 Oct 2016
 *      Author: dayan
 */

#include <iostream>
#include "CSetOfMeasurementValues.h"
using namespace std;

int main()
{
	CSetOfMeasurementValues Value(NOVALUE,V,"myVoltageValues");
	CSetOfMeasurementValues Cobj1(NOVALUE,V,"myVoltageValues");
	CSetOfMeasurementValues Cobj2(NOVALUE,A,"myCurrentValues");;
	CSetOfMeasurementValues Cobj3;
//	Cobj1.setValue(1,10);
//  Cobj1.setValue(3,20);
//  Cobj1.print();
//  Cobj2.setValue(30,20);
//	Cobj2.print();
  //Cobj2.getValue(11);
    Cobj2.setRandomValues(0,100);
    Cobj2.print();



//	Cobj1.getMin();
//	Cobj1.getMax();
//	Cobj1.getAverage();
//
//	Cobj2.setValue(15,40);
//	Cobj2.setValue(20,100);
//	Cobj2.getMin();
//	Cobj2.getMax();
//	Cobj2.getAverage();
//	Cobj2.getValue(15);
	return 0;
}


