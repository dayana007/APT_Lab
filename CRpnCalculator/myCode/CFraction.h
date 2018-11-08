/*
 * CFraction.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dayan
 */

#ifndef CFRACTION_H_
#define CFRACTION_H_

#include <iostream>
#include "math.h"
using namespace std;

class CFraction {
private :
	long m_numerator;
	long m_denominator;
	void shorten();
public:
	CFraction(long numerator = 0, long denominator =1);
	CFraction(CFraction const& f);
	void set(long numerator, long denominator);
	double todouble();
	void print();
	CFraction& operator++();
	CFraction operator++(int);
	CFraction operator + (CFraction c);
	//CFraction operator + (float d);
	CFraction operator - (CFraction c);
	CFraction operator * (CFraction c);
	CFraction operator / (CFraction c);
	void operator = (const CFraction& data);
	friend ostream& operator <<(ostream& out, CFraction& f);
	friend bool operator ==(const CFraction& g, const CFraction& f);
	virtual ~CFraction();
};

#endif /* CFRACTION_H_ */
