/*
 * CRpnCalculator.cpp
 *
 *  Created on: 24 Nov 2016
 *      Author: dayan
 */

#include "CRpnCalculator.h"

bool CRpnCalculator::pushValue(const CFraction& data)
{
	stack.push(data);
	return 1;

}

bool CRpnCalculator::popResult(const CFraction& data)
{
	stack.pop(data);

	return 1;
}

CFraction CRpnCalculator::add()
{
	 CFraction data,popup1,popup2;
     data = stack.pop(popup1)+stack.pop(popup2);
     pushValue(data);
     return data;

}

CFraction CRpnCalculator::subtract()
{
	 CFraction data,popup1,popup2;
	 data = stack.pop(popup1)- stack.pop(popup2);
	 pushValue(data);
	 return data;
}

CFraction CRpnCalculator::multiply()
{
   CFraction data,popup1,popup2;
   data = stack.pop(popup1)* stack.pop(popup2);
   pushValue(data);
   return data;
}

CFraction CRpnCalculator::divide()
{
   CFraction data,popup1,popup2;
   data = stack.pop(popup1)/ stack.pop(popup2);
   pushValue(data);
   return data;
}

CRpnCalculator::CRpnCalculator()
{
  cout<<"Constructor in invocated "<<endl;

}

void CRpnCalculator::print()
{
	stack.print();
}

CRpnCalculator::~CRpnCalculator()
{
}
