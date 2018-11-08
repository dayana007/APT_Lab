/*
 * CRpnCalculator.h
 *
 *  Created on: 24 Nov 2016
 *      Author: dayan
 */

#ifndef CRPNCALCULATOR_H_
#define CRPNCALCULATOR_H_

#include "CLifoBuffer.h"

class CRpnCalculator
{
private:
	CLifoBuffer stack;
public:
	bool pushValue(const CFraction& data);
	bool popResult(const CFraction& data);
	CFraction add();
	CFraction subtract();
	CFraction multiply();
	CFraction divide();
	void print();
	CRpnCalculator();
	virtual ~CRpnCalculator();
};

#endif /* CRPNCALCULATOR_H_ */
