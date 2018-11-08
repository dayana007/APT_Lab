//============================================================================
// Name        : CSetOfMeasurementValues.cpp
// Author      : dayana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CSetOfMeasurementValues.h"

using namespace std;

CSetOfMeasurementValues::CSetOfMeasurementValues() {

	unsigned int index;
	for (index = 0; index < MAXVALUE; index++)
	{
		m_value[index] = 0;
	}
	m_unit = V;
	m_name = "myVoltageValues";


}

CSetOfMeasurementValues::CSetOfMeasurementValues(double value,t_unit unit,std::string name)
{
	unsigned int index;
	for (index = 0; index< MAXVALUE; index++)
	{
		m_value[index] = value;
	}
	m_unit = unit;
	m_name = name;

	cout<< "Constructor is invoked"<<endl;
	cout<< "Address of the object is "<< this <<endl;
	cout<< "Address of attribute m_value is "<< &(this->m_value)<<endl;
	cout<< "Address of  attribute m_unit is "<< &(this->m_unit)<<endl;
	cout<< "Address of  attribute m_name is "<< &(this->m_name) <<endl;

}

CSetOfMeasurementValues::~CSetOfMeasurementValues()
{

}

void CSetOfMeasurementValues::setValue(unsigned int pos, double value)
{

	if (pos >MAXVALUE )
	{

		cout<<"ERROR setValue : Position out of bounds"<<endl;

	}
	else
	{
	    m_value[pos] = value;
	    //this->printSingleValue(pos);
    }
}

void CSetOfMeasurementValues::printSingleValue(unsigned int pos)
{

	std:: string unit;
		switch(this->m_unit)
		{
		case A:
			unit ="Amperes";
			break;
		case V:
			unit ="Volts";
			break;
		case S:
			unit ="Seconds";
			break;
		case W:
			unit ="Watts";
			break;
		case NONE:
			unit ="None";
			break;
		}

    cout<<"Value["<<pos<<"] "<<this->m_value[pos]<<" "<< unit<<endl;
}

double CSetOfMeasurementValues::getValue(unsigned int pos)
{

   int value;
   if(pos > MAXVALUE)
   {
	   cout<<"Error get value : Position out of bound"<<endl;
	   this->m_value[pos] = NOVALUE;
	   value = this->m_value[pos];
	   cout<<"Returning a value"<<" :"<<value<<endl;
   }
   else
   {

	   value = this->m_value[pos];

   }
   return value;
}

double CSetOfMeasurementValues::getMin()
{
	double currvalue,prevvalue,minvalue;
	unsigned int counter;
	unsigned int index;
	counter = 0;
	prevvalue = this->getValue(0);
	for(index = 0;index< MAXVALUE;index++)
	{
		currvalue = this->getValue(index);
		if (currvalue != NOVALUE)
		{
			minvalue = min(currvalue,prevvalue);
			prevvalue = minvalue;
		}
		else
		{
			counter += 1;

		}
	}
	if (counter == MAXVALUE)
	{
		minvalue = NOVALUE;

	}
	else
	{

	}
	//cout<<"Min Value is "<<minvalue<<endl;
	return minvalue;

}

double CSetOfMeasurementValues::getMax()
{
	double currvalue,prevvalue,maxvalue;
	int counter= 0;
	unsigned int index;
	prevvalue = this->getValue(0);
	for(index = 0;index< MAXVALUE;index++)
	{
		currvalue = this->getValue(index);
		if (currvalue != NOVALUE)
		{
			maxvalue = max(currvalue,prevvalue);
			prevvalue = maxvalue;
		}
		else
		{
			 counter += 1;

		}
	}
	if (counter == MAXVALUE)
	{
		maxvalue = NOVALUE;

	}
	else
	{

	}
	//cout<<"Max Value is "<<maxvalue<<endl;

	return maxvalue;
}

double CSetOfMeasurementValues::getAverage()
{
	double currvalue,prevvalue,Avgvalue,sum;
	unsigned int index;
	int counter,novalcnt;
	prevvalue = 0.0;
	sum =0.0;
	counter = 0;
	novalcnt =0;

	for(index = 0;index< MAXVALUE;index++)
	{
		currvalue = this->getValue(index);
		if (currvalue != NOVALUE)
		{
			sum = currvalue + prevvalue;
			prevvalue = sum;
			counter +=1;

		}
		else
		{
			novalcnt += 1;

		}
	}

	Avgvalue = (sum /(double)counter);

	if (novalcnt == MAXVALUE)
	{
		Avgvalue = NOVALUE;

	}
	else
	{

	}

	//cout<<"Average Value is "<<Avgvalue<<endl;

	return Avgvalue;
}


void CSetOfMeasurementValues::print()
{
	unsigned int index ;
	cout<<this->m_name<<endl;
    for (index= 0; index< MAXVALUE; index++)
    {
       if(this->getValue(index)!= NOVALUE)
       {
         this->printSingleValue(index);
       }
       else
       {

       }
    }
    cout<<"Min value is "<<this->getMin()<<endl;
    cout<<"Max value is "<<this->getMax()<<endl;
    cout<<"Average value is "<<this->getAverage()<<endl;
}

void CSetOfMeasurementValues::setRandomValues(int min,int max)
{
	unsigned int index;
	int randum_num;
	double randum;
	time_t t;
	srand((unsigned) time(&t) );
	for(index=0; index<MAXVALUE;index++)
	{
		randum_num = rand()% (max*10) - (min*10);
		randum = (double)randum_num/10.0;
	    m_value[index] = randum;
	}

}
