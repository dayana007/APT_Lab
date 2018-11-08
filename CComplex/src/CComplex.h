/*
 * CComplex.h
 *
 *  Created on: 20 Nov 2016
 *      Author: dayan
 */

#ifndef CCOMPLEX_H_
#define CCOMPLEX_H_

#include <iostream>
#include "math.h"
using namespace std;

class CComplex {

private:
	float m_real;
	float m_imaginary;
public:
	CComplex(float real = 0, float imaginary = 0);
	CComplex(CComplex const &c );
	void set(float real, float imaginary);
	float abs();
	void print();
	CComplex& operator++();
	CComplex operator++(int);
	CComplex operator + (CComplex c);
	CComplex operator + (float d);
	CComplex operator - (CComplex c);
	CComplex operator * (CComplex c);
	CComplex operator / (CComplex c);
	friend ostream& operator <<(ostream& out, CComplex& c);
	virtual ~CComplex();

};



#endif /* BASE_H_ */
