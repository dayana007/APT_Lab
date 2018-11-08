/*
 * CComplex.cpp
 *
 *  Created on: 20 Nov 2016
 *      Author: dayan
 */

#include "CComplex.h"


CComplex::CComplex(float real, float imaginary)
{
	if((real > -100.0) && (real < 100.0))
	{
		m_real = real;
	}
	else
	{
		m_real = 0.0;
	}
	if((imaginary > -100.0) && (imaginary < 100.0))
	{
		m_imaginary = imaginary;
	}
	else
	{
		m_imaginary = 0.0;
	}
//
//	cout<<"Address of the object created "<<this<<endl;
//	cout<<"The value of attribute real part "<< this->m_real<<endl;
//	cout<<"The value of attribute imaginary  part "<< this->m_imaginary<<endl;
}

CComplex::CComplex(const CComplex& c)
{
	m_real = c.m_real;
	m_imaginary = c.m_imaginary;
}

void CComplex::set(float real, float imaginary)
{
	if((real > -100.0) && (real < 100.0))
	{
		m_real = real;
	}
	else
	{
		m_real = 0.0;
	}
	if((imaginary > -100.0) && (imaginary < 100.0))
	{
		m_imaginary = imaginary;
	}
	else
	{
		m_imaginary = 0.0;
	}
}

float CComplex::abs()
{
	float real, imaginary,sum,absvalue;
	real = this->m_real;
	imaginary = this->m_imaginary;
	sum = (powf(real,2)+ powf(imaginary,2));
	absvalue = sqrt(sum);
	return absvalue;

}

CComplex& CComplex::operator ++()
{
	++m_real;
	return *this;
}

CComplex CComplex::operator ++(int )
{
	CComplex cTmp(*this);
	operator++();
	return cTmp;
}

CComplex CComplex::operator +(CComplex c)
{
	m_real = m_real +c.m_real;
	m_imaginary = m_imaginary +c.m_imaginary;
	return *this;
}

CComplex CComplex::operator +(float c)
{
	m_real =m_real + c;
	return *this;
}

CComplex CComplex::operator -(CComplex c)
{
	m_real = m_real - c.m_real;
	m_imaginary = m_imaginary - c.m_imaginary;
	return *this;

}

CComplex CComplex::operator *(CComplex c)
{
	m_real =((m_real*c.m_real) -(m_imaginary*c.m_imaginary));
	m_imaginary = ((m_real*c.m_imaginary) +( m_imaginary*c.m_real));
	return *this;
}

CComplex CComplex::operator /(CComplex c)
{
	m_real =((m_real*c.m_real) +(m_imaginary*c.m_imaginary))/((c.m_real*c.m_real) +(c.m_imaginary*c.m_imaginary));
	m_imaginary = ((c.m_real*m_imaginary) +(c.m_imaginary*m_real))/((c.m_real*c.m_real) +(c.m_imaginary*c.m_imaginary));
	return *this;
}

CComplex::~CComplex()
{

}

void CComplex::print()
{
	cout<<"Complex number is "<<this->m_real<<"+"<<"i"<<this->m_imaginary<<endl;
}

ostream& operator <<(ostream& out, CComplex& c)
{
  if(c.m_imaginary > 0)
  {
	  out <<c.m_real<< "+i"<<fabs(c.m_imaginary);
  }
  else if (c.m_imaginary < 0)
  {
	  out << c.m_real<< "-i"<<fabs(c.m_imaginary);
  }
  else
  {
	  out << c.m_real;
  }

   return out;
}

