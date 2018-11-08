/*
 * CWaypoint.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: dayan
 */
#include <iostream>
#include "CWaypoint.h"
using namespace std;

//CWaypoint::CWaypoint()
//{
//    m_name = "DESTINATION";
//    m_latitude = 0;
//    m_longitude = 0;
//
//}

CWaypoint::CWaypoint(double latitude, double longitude,string name)
{
	m_name = name;
	m_latitude = latitude;
	m_longitude = longitude;

	//this->set(name,latitude,longitude);

    #ifdef SHOWADDRESS
    cout<<"Constructor is invoked"<< endl;

    /*Memory location for the object created is displayed*/
	cout<<"Address of this object is "<<this<<endl;

    /* Attribute of type string occupies a data memory of 4 bytes*/
	cout<<"Address of the attribute m_name is"<<&(this->m_name)<<endl;
	cout<<"Address of the attribute m_name is"<<sizeof(m_name)<<endl;

	/* Attribute of type double  occupies a data memory of 8 bytes*/
	cout<<"Address of the attribute m_latitude is "<<&(this->m_latitude)<<endl;
	cout<<"Address of the attribute m_latitude is"<<sizeof(m_latitude)<<endl;
	cout<<"Address of the attribute m_longitude is "<<&(this->m_longitude)<<endl;
	cout<<"Address of the attribute m_latitude is"<<sizeof(m_longitude)<<endl;

	/* Value of the attributes stored in the class*/
	cout<<"Value of the attribute m_name is "<<this->m_name<<endl;
	cout<<"Value of the attribute m_latitude is "<<this->m_latitude<<endl;
	cout<<"Value of the attribute m_longitude is "<<this->m_longitude<<endl;
    #endif
}

void CWaypoint::set(string name, double latitude, double longitude)
{
	m_name = name ;
	if ((latitude >= -90.0) &&(latitude <= 90.0))
	{
		m_latitude = latitude;
	}
	else
	{
		m_latitude = 0;
	}

	if ((longitude >=-180.0) &&(longitude <= 180.0))
	{
		m_longitude = longitude;
	}
	else
	{
		m_longitude = 0;
	}

}

void CWaypoint::print(int format)
{
	if(format == DEGREE)
	{
		cout<<this->m_name<<" on latitude = "<<this->m_latitude<<" and on longitude = "<<this->m_longitude<<endl;

	}
	else if(format == MMSS)
	{
		int deg;
		int mm;
		double ss;
		//cout<<this->m_name<<"on latitude ="<<endl;
		this->transformLatitude2degmmss(deg,mm, ss);
		//cout<<"and on latitude ="<<endl;
		this->transformLongitude2degmmss(deg, mm,ss);
	}
}

string CWaypoint::getName()
{
	string name;
	name = this->m_name;
	//cout<<"Name : "<<name<<endl;
	return name;
}

double CWaypoint::getLatitude()
{
	double latitude;
	latitude = this->m_latitude;
	//cout<<"Latitude : "<<latitude<<endl;
	return latitude;
}

double CWaypoint::getLongitude()
{
	double longitude;
	longitude = this->m_longitude;
	//cout<<"Longitude : "<<longitude<<endl;
	return longitude;
}

void CWaypoint:: getAllDataByReference(string& name, double& latitude,
		double& longitude)
{
	name = this->m_name;
	latitude = this->m_latitude;
	longitude = this->m_longitude;
	/* The addresses of local variables passed in main file to get function is same as
	 * addresses of the parameters used inside the function as the parameters are passed
	 * by reference to the function
	 */
	cout<<"Address of parameter name "<<&name<<endl;
	cout<<"Address of parameter latitude "<<&latitude<<endl;
	cout<<"Address of parameter longitude "<<&longitude<<endl;

	cout<<"Name as return value is "<<name<<endl;
	cout<<"Latitude as return value is "<<latitude<<endl;
	cout<<"Longitude as return value is "<<longitude<<endl;
}

double CWaypoint::calculateDistance(const CWaypoint& wp)
{
    double distance,invangle,dist1,dist2,dist3,dist4;
    double difference,latitude_1,latitude_2,longitude_1,longitude_2;
    latitude_1 = this->m_latitude;
    latitude_2 = wp.m_latitude;
    longitude_1 = this->m_longitude;
    longitude_2 = wp.m_longitude;

    /* Degree to radian conversion should be done before using
     * trigonometric functions sin and cos
     */
    dist1 = sin(latitude_1*PI/180)*sin(latitude_2*PI/180);
    dist2 = cos(latitude_1*PI/180)*cos(latitude_2*PI/180);
    difference = (longitude_2*PI/180) - (longitude_1*PI/180);
    dist3 = cos(difference);
    dist4 = dist2*dist3;
    invangle = dist1 + dist4;
    distance = RADIUS* acos(invangle);
    //cout<<"Distance between "<<this->m_name<<" and "<<wp.m_name<<" is "<<distance<<endl;
    return distance;
}

CWaypoint::~CWaypoint()
{
	// TODO Auto-generated destructor stub
}

void CWaypoint::transformLongitude2degmmss(int& deg, int& mm, double& ss)
{


	double mintosec,degtomin,longitude;
	longitude = this->m_longitude;
	degtomin = (longitude - trunc(longitude));
	deg = trunc(longitude);
	//cout<<m_latitude;
	mm = trunc(degtomin *60);
	mintosec = degtomin*60.0;
	ss =(mintosec - mm)*60.0;
    cout<<"and on longitude = "<<deg<<"deg "<<mm<<"min "<<ss<<"sec"<<endl;

}

void CWaypoint::transformLatitude2degmmss(int& deg, int& mm, double& ss)
{
	double mintosec,degtomin,latitude;
	latitude = this->m_latitude;
	degtomin = (latitude - trunc(latitude));
	deg = trunc(latitude);
	//cout<<m_latitude;
	mm = trunc(degtomin *60);
	mintosec = degtomin*60.0;
	ss =(mintosec - mm)*60.0;
    cout<<this->m_name<<" on latitude = "<<deg<<"deg "<<mm<<"min "<<ss<<"sec"<<endl;
}
