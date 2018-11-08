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
void CPOI::print()
{
	string name;
	CWaypoint* pCWaypoint;
	pCWaypoint = this;


	switch (m_type)
	{
	    case POI:
	    {
		   name = "POI";
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


	cout<<"Point of Interest "<<endl;
	cout<<"================= "<<endl;
	cout<<"is of type "<<name<< ":" <<m_description<<endl;
	pCWaypoint->print(MMSS);
	//CWaypoint obj(m_name,m_latitude,m_longitude);
	//obj.print(MMSS);

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




