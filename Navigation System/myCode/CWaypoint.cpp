/*
 * CWaypoint.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: dayan
 */

#include "CWaypoint.h"

/**Constructor for the CWaypoint class
 * @param string name : initialises the member attribute m_name
 * @param double latitude : initialises the member attribute m_latitude
 * @param double longitude : initialises the member attribute m_longitude
 */

CWaypoint::CWaypoint(string name,double latitude, double longitude)
{

	/** Parameter values are stored into the member attributes
	 * using set method
	 */

	set(name,latitude,longitude);

	/**Verbose method is implemented to hide the addresses of
	 * class attributes getting printed
	 */

    #ifdef SHOWADDRESS
    cout<<"Constructor is invoked"<< endl;
    cout<<"======================"<< endl;

    /**Memory location for the object created is displayed
    */
	cout<<"Address of this object is "<<this<<endl;

    /** Attribute of type string occupies a data memory of 4 bytes
     */
	cout<<"Address of the attribute m_name is"<<&(this->m_name)<<endl;
	cout<<"Address of the attribute m_name is"<<sizeof(m_name)<<endl;

	/** Attribute of type double  occupies a data memory of 8 bytes
	 */
	cout<<"Address of the attribute m_latitude is "<<&(this->m_latitude)<<endl;
	cout<<"Address of the attribute m_latitude is"<<sizeof(m_latitude)<<endl;
	cout<<"Address of the attribute m_longitude is "<<&(this->m_longitude)<<endl;
	cout<<"Address of the attribute m_latitude is"<<sizeof(m_longitude)<<endl;

	/** Value of the attributes stored in the class
	 */
	cout<<"Value of the attribute m_name is "<<this->m_name<<endl;
	cout<<"Value of the attribute m_latitude is "<<this->m_latitude<<endl;
	cout<<"Value of the attribute m_longitude is "<<this->m_longitude<<endl;
    #endif
}

/** Set method is used to set the attributes of the class with parameters passed
 * @param string name : sets the member attribute m_name
 * @param double latitude : sets the member attribute m_latitude
 * @param double longitude : sets the member attribute m_longitude
 * @return void
 */

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

/** Print method is used to print the geodetic data in two formats either Degree or MMSS
 *@param int format : Format of Print method either as Degree or MMSS
 *@return void
 */

void CWaypoint::print(int format)
{
	if(format == DEGREE)
	{
		cout<<this->getName()<<" on latitude = "<<this->getLatitude()<<" and on longitude = "<<this->getLongitude()<<endl;

	}
	else if(format == MMSS)
	{
		int deg;
		int mm;
		double ss;
		this->transformLatitude2degmmss(deg,mm, ss);
		this->transformLongitude2degmmss(deg, mm,ss);
	}
}

/** getName is used to return the attribute name of the class CWaypoint object created
 * @return string : Value of attribute m_name is returned
 */

string CWaypoint::getName()const
{
	string name;
	name = m_name;
	return name;
}

/** getLatitude is used to return the attribute lattitude of the class CWaypoint object created
 * @return double : Value of attribute m_latitude is returned
 */

double CWaypoint::getLatitude()const
{
	double latitude;
	latitude = m_latitude;
	return latitude;
}

/** getLongitude is used to return the attribute Longitude of the class CWaypoint object created
 * @return double : Value of attribute m_longitude is returned
 */

double CWaypoint::getLongitude()const
{
	double longitude;
	longitude = m_longitude;
	return longitude;
}

/** getAllDataByReference is used to return all the attribute
 *  of the class CWaypoint object created
 * @param string name : gets the data from the member attribute m_name
 * @param double latitude : gets the data from the member attribute m_latitude
 * @param double longitude : gets the data from the member attribute m_longitude
 * @return void
 */

void CWaypoint:: getAllDataByReference(string& name, double& latitude,
		double& longitude)const
{
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;

	/** The addresses of local variables passed in main file to get function is same as
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

/** calculateDistance calculates distance between two
 * waypoints and returns the distance.
 * Distance is calculated according to the formula
 * dist = Radius*invcos(sin (latitude_1)*sin( latitude_2)+
 *        cos(latitude_1)*cos(latitude_2)*cos(longitude_1-longitude_2))
 * where Radius is earth radius = 6378km
 * @ param const CWaypoint& wp : The reference of waypoint whose distance to be calculated from another
 * @return double : Distance between two waypoints
 */

double CWaypoint::calculateDistance(const CWaypoint& wp)
{
    double distance,invangle,tempdist1,tempdist2,tempdist3,tempdist4;
    double difference,latitude_1,latitude_2,longitude_1,longitude_2;
    latitude_1 = m_latitude;
    latitude_2 = wp.m_latitude;
    longitude_1 = m_longitude;
    longitude_2 = wp.m_longitude;

    /** Degree to radian conversion should be done before using
     * trigonometric functions sin and cos
     */
    tempdist1 = sin(latitude_1*PI/180)*sin(latitude_2*PI/180);
    tempdist2 = cos(latitude_1*PI/180)*cos(latitude_2*PI/180);
    difference = (longitude_2*PI/180) - (longitude_1*PI/180);
    tempdist3 = cos(difference);
    tempdist4 = tempdist2*tempdist3;
    invangle = tempdist1 + tempdist4;
    distance = RADIUS* acos(invangle);
    return distance;
}

/** transformLongitude2degmmss method is used to convert the geodetic data
 * from format degree to  format degmmss
 * 1 degree = 60min = 3600 sec
 *  @param int& deg : Reference to the latitude value converted in degree
 *  @param int& mm : Reference to the latitude value converted in mm
 *  @param double& ss : Reference to the latitude value converted in ss
 *  @return void
 */
void CWaypoint::transformLongitude2degmmss(int& deg, int& mm, double& ss)
{
	double mintosec,degtomin,longitude;
	longitude = m_longitude;
	degtomin = (longitude - trunc(longitude));
	deg = trunc(longitude);
	mm = trunc(degtomin *60);
	mintosec = degtomin*60.0;
	ss =(mintosec - mm)*60.0;
    cout<<"and on longitude = "<<deg<<"deg "<<mm<<"min "<<ss<<"sec"<<endl;

}


/** transformLongitude2degmmss method is used to convert the geodetic data
 * from format degree to  format degmmss
 * 1 degree = 60min = 3600 sec
 *  @param int& deg : Reference to the longitude value converted in degree
 *  @param int& mm : Reference to the longitude value converted in mm
 *  @param double& ss : Reference to the longitude value converted in ss
 *  @return void
 */

void CWaypoint::transformLatitude2degmmss(int& deg, int& mm, double& ss)
{
	double mintosec,degtomin,latitude;
	latitude = m_latitude;
	degtomin = (latitude - trunc(latitude));
	deg = trunc(latitude);
	mm = trunc(degtomin *60);
	mintosec = degtomin*60.0;
	ss =(mintosec - mm)*60.0;
    cout<<this->m_name<<" on latitude = "<<deg<<"deg "<<mm<<"min "<<ss<<"sec"<<endl;
}

CWaypoint::~CWaypoint()
{
}
