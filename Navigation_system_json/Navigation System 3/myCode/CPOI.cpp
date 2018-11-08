/*
 * CPOI.cpp

 *
 *  Created on: 29 Oct 2016
 *      Author: dayan
 */


#include "CPOI.h"

/** Used to print all the information about a particular POI
 * in degmmss format
 * @return void
 */
void CPOI::print(int format)
{
	string name;

	switch (m_type)
	{
	case DEFAULT:
	{
		name = "DEFAULT";
		break;
	}
	case RESTAURANT:
	{
		name = "RESTAURANT";
		break;
	}
	case SIGHTSEEING:
	{
		name = "SIGHTSEEING";
		break;
	}
	case AIRPORT:
	{
		name = "AIRPORT";
		break;
	}
	case UNIVERSITY:
	{
		name = "UNIVERSITY";
		break;
	}
	default:
	{
		break;
	}
	}
	cout<<" Point of interest is of type "<<name<< ":" <<m_description<<endl;
	CWaypoint::print(format);

}

/** Constructor is called
 * @param t_poi type : initialises the member attribute m_type
 * @param string name : initialises the member attribute m_name
 * @param string description : initialises the member attribute m_description
 * @param double latitude : initialises the member attribute m_latitude
 * @param double longitude : initialises the member attribute m_longitude
 */

CPOI::CPOI(t_poi type , string name, string description, double latitude,
		double longitude)
{
	m_type = type;
	m_name = name;
	m_description = description;
	m_latitude = latitude;
	m_longitude = longitude;

}

/** All data of the POI is accessed with this function
 * @param t_poi type : gets the data from the member attribute m_type
 * @param string name : gets the data from the member attribute m_name
 * @param string description : gets the data from the member attribute m_description
 * @param double latitude : gets the data from the member attribute m_latitude
 * @param double longitude : gets the data from the member attribute m_longitude
 */

void CPOI::getAllDataByReference(string& name, double& latitude,
		double& longitude, t_poi& type, string& description)
{
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
	type = m_type;
	description = m_description;

}

/**
 * Conversion of POI type to corresponding string
 * @ param POI type
 * @return the appropriate string for the type
 */
string CPOI::getStringFromPoiType(t_poi& type)
{
	string type_name;
	switch (type)
	{
	case DEFAULT:
	{
		type_name = "DEFAULT";
		break;
	}
	case RESTAURANT:
	{
		type_name = "RESTAURANT";
		break;
	}
	case SIGHTSEEING:
	{
		type_name = "SIGHTSEEING";
		break;
	}
	case AIRPORT:
	{
		type_name = "AIRPORT";
		break;
	}
	case UNIVERSITY:
	{
		type_name = "UNIVERSITY";
		break;
	}
	default:
	{
		break;
	}
	}
	return type_name;
}

/**
 * Set all attributes of the object with the parameters passed
 * @param t_poi type
 * @param string name
 * @param string description
 * @param double latitude
 * @param double longitude
 * @return void
 */
void CPOI::setAllDataByReference(t_poi type, string name, string description,
		double latitude, double longitude)
{
	this->set(name,latitude,longitude);
	m_type = type;
	m_description = description;

}
/**
 * Conversion of string to corresponding POI type
 * @ param string
 * @return the appropriate POI type
 */
t_poi CPOI::getTypeFromstring(string type)
{
	t_poi tPOI;

	if( type == "DEFAULT")
	{
		tPOI = DEFAULT;
	}
	else if( type == "RESTAURANT")
	{
		tPOI = RESTAURANT;
	}
	else if( type == "SIGHTSEEING" )
	{
		tPOI = SIGHTSEEING;
	}
	else if( type == "AIRPORT")
	{
		tPOI = AIRPORT;
	}
	else if( type == "UNIVERSITY" )
	{
		tPOI = UNIVERSITY;
	}
	else
	{
		tPOI = DEFAULT;
	}

	return tPOI;
}

/**
 * Friend function which is the operator overloading of
 * << and used for print
 * @param outstream object and reference of a POI object
 * @return an outstream object
 */
ostream& operator <<(ostream& out, CPOI& origin)
{
	origin.print(MMSS);
	return out;
}



