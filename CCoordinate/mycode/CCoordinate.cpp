//============================================================================
// Name        : CCoordinate.cpp
// Author      : dayana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CCoordinate.h"
using namespace std;


CCoordinate::~CCoordinate()
{
	cout<< "Destructor invoked " << endl;
	cout<< "Address of the destroyed object is " << this << endl;
}

CCoordinate::CCoordinate()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}
CCoordinate::CCoordinate(float x)
{
	m_x = x;
	m_y = 0;
	m_z = 0;
}

CCoordinate::CCoordinate(float x, float y, float z)
{
	m_x =x;
	m_y =y;
	m_z =z;

	cout<< "Constructor invoked " << endl;
	cout<< "Address of the object is " << this << endl;
	cout<< "Address of the attribute m_x is " <<&(this->m_x)  <<endl;
	cout<< "Address of the attribute m_y is " <<&(this->m_y)  <<endl;
	cout<< "Address of the attribute m_z is " <<&(this->m_z)  <<endl;
	cout<< "Value of the attribute m_x is "   << this->m_x  <<endl;
	cout<< "Value of the attribute m_y is "   << this->m_y  <<endl;
	cout<< "Value of the attribute m_z is "   << this->m_z  <<endl;

}

void CCoordinate::getCartesian(float& x, float& y, float& z)
{
   x = m_x;
   y = m_y;
   z = m_z;
}

void CCoordinate::setCartesian(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void CCoordinate::add(const CCoordinate& c)
{
	m_x = m_x + c.m_x;
	m_y = m_y + c.m_y;
	m_z = m_z + c.m_z;

}

void CCoordinate::getCylinder(float& r, float& phi, float& h)
{
    r  = sqrt(pow(m_x,2) + pow(m_y,2));
    if (m_x >0)
    {
    	phi = atan(m_y/m_x);
    }
    else if(m_x<0 && m_y>=0)
    {
    	phi = atan(m_y/m_x)+ PI;
    }
    else if (m_x<0 && m_y<0)
    {
    	phi = atan(m_y/m_x)- PI;
    }
    else if (m_x==0 && m_y>0)
    {
    	phi = (PI/2.0);
    }
    else if (m_x==0 && m_y<0)
    {
    	phi = (PI/2.0);
    }
    else
    {
    	cout<<"WARNING : Undefined Rsult. Setting phi to 0"<<endl;
    	this->setCartesian(0.0,0.0,0.0);
    	cout<<"Cylindrical Coordinate (r,phi,h) is "<<"("<<this->m_x<<","<<this->m_y<<","<<this->m_z<<")"<<endl;


    };

}

void CCoordinate::getPolar(float& r, float& phi, float& theta)
{
	 r     = sqrt(pow(m_x,2) + pow(m_y,2)+ pow(m_z,2));
	 if(!(m_x == 0)&& (m_y ==0))
	 {
	     phi   = atan2(m_y,m_x);
	    theta = ((PI/2.0) - atan(m_y/sqrt(pow(m_x,2) + pow(m_y,2))));
	 }
	 else
	 {
	    	cout<<"WARNING : Undefined Rsult. Setting all angles  to 0"<<endl;
	    	this->setCartesian(0.0,0.0,0.0);
	    	cout<<"Polar Coordinate (r,phi,theta) is "<<"("<<this->m_x<<","<<this->m_y<<","<<this->m_z<<")"<<endl;
	 }

}



void CCoordinate::print(t_coordinate style)
{
	switch(style)
	{
	   case CARTESIAN:
	      {
	    	  float x,y,z;
	    	  this->getCartesian(x,y,z);
	    	  cout<< "Cartesian coordintes  (x,y,z) = "<<x<<","<<y<<","<<z<<endl;
	    	  break;
	      }

	   case CYLINDER:
		   {
			   float r, phi, h;
			   this->getCylinder(r,phi,h);
			   cout<< "Cylindrical coordintes  (r,phi,h) = "<<r<<","<<phi<<","<<h<<endl;
			   break;
		   }
	   case POLAR:
		   {
			   float r, phi, theta;
			   this->getCylinder(r,phi,theta);
			   cout<< "Polar coordintes  (r,phi,theta) = "<<r<<","<<phi<<","<<theta<<endl;
			   break;
		   }
	   default:
	   {
	   }

	}


}
