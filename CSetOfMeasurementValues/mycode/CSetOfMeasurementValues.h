/*
 * CSetOfMeasurementValues.h
 *
 *  Created on: 24 Oct 2016
 *      Author: dayan
 */

#ifndef CSETOFMEASUREMENTVALUES_H_
#define CSETOFMEASUREMENTVALUES_H_

#include <algorithm>
#include "string.h"
#include "stdlib.h"
#include "time.h"

//using namespace std;

#define MAXVALUE 10
#define NOVALUE -9999
//#define MAXRAND 100

enum t_unit {A,V,S,W,NONE};

class CSetOfMeasurementValues {

private :
	double m_value [MAXVALUE];
	t_unit m_unit;
	std :: string m_name;

public:
	CSetOfMeasurementValues();
	CSetOfMeasurementValues(double value,t_unit unit, std :: string name);
	virtual ~CSetOfMeasurementValues();
	void setValue(unsigned int pos, double value);
	void printSingleValue(unsigned int pos);
	double getValue(unsigned int pos);
	double getMin();
	double getMax();
	double getAverage();
    void print();
    void setRandomValues(int min,int max);
};

#endif /* CSETOFMEASUREMENTVALUES_H_ */
