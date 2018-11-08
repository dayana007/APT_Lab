/*
 * CFraction.cpp
 *
 *  Created on: 21 Nov 2016
 *      Author: dayan
 */

#include "CFraction.h"



void CFraction::shorten()
{
	long gcd;
	gcd = max(m_numerator,m_denominator);
	while(gcd > 1)
	{
		if((m_numerator % gcd == 0 )&&(m_denominator% gcd == 0 ))
	    {
			m_numerator = m_numerator/gcd;
			m_denominator = m_denominator/gcd;
			break;
	    }
		else
		{
			gcd--;
		}
	}
}

CFraction::CFraction(long numerator, long denominator)
{
	m_numerator   = numerator;
	if(denominator == 0)
	{
		cout<<"Math error : division by zero "<<endl;
		m_denominator = 1;
	}
	else
	{
		m_denominator = denominator;
	}

}

void CFraction::set(long numerator, long denominator)
{
	m_numerator   = numerator;

	if(denominator == 0)
	{
		cout<<"Math error : division by zero "<<endl;
		m_denominator = 1;
	}
	else
	{
		m_denominator = denominator;
	}

}

double CFraction::todouble()
{
   double quotient;
   this->shorten();
   quotient = (double)m_numerator/m_denominator;
   return quotient;
}

void CFraction::print()
{
	this->shorten();
	cout<<"CFraction[m_numerator= "<< m_numerator <<"; m_denominator ="<<m_denominator<<"]"<<endl;
}

CFraction& CFraction::operator ++()
{
	m_numerator = m_numerator +m_denominator;
	return *this;

}

CFraction CFraction::operator ++(int)
{
	CFraction fTemp(*this);
	operator ++();
	return fTemp;

}

CFraction::CFraction(const CFraction& f)
{
	m_numerator = f.m_numerator;
	m_denominator =f.m_denominator;
}

CFraction CFraction::operator +(CFraction f)
{
	m_numerator =(m_numerator*f.m_denominator + f.m_numerator*m_denominator);
	m_denominator = m_denominator *f.m_denominator;
	this->shorten();
    return *this;
}

CFraction CFraction::operator -(CFraction f)
{
	m_numerator =(m_numerator*f.m_denominator - f.m_numerator*m_denominator);
	m_denominator = m_denominator *f.m_denominator;
	this->shorten();
    return *this;
}

CFraction CFraction::operator *(CFraction f)
{
	m_numerator =m_numerator*f.m_numerator;
	m_denominator = m_denominator *f.m_denominator;
	this->shorten();
    return *this;
}

CFraction CFraction::operator /(CFraction f)
{
	m_numerator =m_numerator*f.m_denominator;
	m_denominator = m_denominator *f.m_numerator;
	this->shorten();
    return *this;

}

CFraction::~CFraction()
{
	// TODO Auto-generated destructor stub
}
ostream& operator <<(ostream& out, CFraction& f)
{
    f.shorten();
	out <<f.m_numerator<< "/"<< f.m_denominator<<endl;
   return out;
}

