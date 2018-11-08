/*
 * CWaypoint.h
 *
 *  Created on: 27 Oct 2016
 *      Author: dayan
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* All # defines should be defined in the header so that
 * it can be accessed by any file if the header is included
 */
#define PI 3.14
#define RADIANCONVERSION 180

/* SHOWADDRESS is defined to turn on
 * and off verbose mode when constructor
 * is invoked to printh the addresses
 */

#define SHOWADDRESS
#undef  SHOWADDRESS
#define DEGREE 1
#define MMSS 2
#define RADIUS 6378

/**
 * enum is defined to store the types of objects available
 * either Waypoint or POI
 */
enum wp_type{WAYPOINT,POI};

class CWaypoint
{
private:

	wp_type m_type;
	/**
	 * transformLongitude2degmmss method is used to convert the geodetic data
	 * from format degree to  format degmmss
	 * 1 degree = 60min = 3600 sec
	 *  @param int& deg : Reference to the latitude value converted in degree
	 *  @param int& mm : Reference to the latitude value converted in mm
	 *  @param double& ss : Reference to the latitude value converted in ss
	 *  @return void
	 */
	void transformLongitude2degmmss(int& deg,int& mm,double& ss);
	/**
	 * transformLongitude2degmmss method is used to convert the geodetic data
	 * from format degree to  format degmmss
	 * 1 degree = 60min = 3600 sec
	 *  @param int& deg : Reference to the longitude value converted in degree
	 *  @param int& mm : Reference to the longitude value converted in mm
	 *  @param double& ss : Reference to the longitude value converted in ss
	 *  @return void
	 */
	void transformLatitude2degmmss(int& deg,int& mm,double& ss);

protected:
	double m_latitude;
	double m_longitude;
	string m_name;

public:

	/**
	 * Constructor for the CWaypoint class
	 * @param string name : initialises the member attribute m_name
	 * @param double latitude : initialises the member attribute m_latitude
	 * @param double longitude : initialises the member attribute m_longitude
	 */
	CWaypoint(string name = "DEFAULT",double latitude = 0, double longitude = 0, wp_type type = WAYPOINT);

	/**
	 * Set method is used to set the attributes of the class with parameters passed
	 * @param string name : sets the member attribute m_name
	 * @param double latitude : sets the member attribute m_latitude
	 * @param double longitude : sets the member attribute m_longitude
	 * @return void
	 */

	void set (string name, double latitude, double longitude);

	/**
	 * Set type function is used to set the type of object to
	 * waypoint or POI
	 * @param type of object whether waypoint or POI
	 * @return void
	 */
	void setType(wp_type type);
	/**
	 * getName is used to return the attribute name of the class CWaypoint object created
	 * @return string : Value of attribute m_name is returned
	 */
	string getName()const;
	/**
	 * Get type function is used to get the type of object to
	 * waypoint or POI
	 * @return type of object whether waypoint or POI
	 */
	wp_type getType()const;
	//virtual void print (int format);

	/**
	 * Print method is used to print the geodetic data in two formats either Degree or MMSS
	 *@param int format : Format of Print method either as Degree or MMSS
	 *@return void
	 */

	void print (int format);
	/**
	 * getLatitude is used to return the attribute lattitude of the class CWaypoint object created
	 * @return double : Value of attribute m_latitude is returned
	 */
	double getLatitude()const;
	/**
	 * getLongitude is used to return the attribute Longitude of the class CWaypoint object created
	 * @return double : Value of attribute m_longitude is returned
	 */
	double getLongitude()const;
	/**
	 * getAllDataByReference is used to return all the attribute
	 *  of the class CWaypoint object created
	 * @param string name : gets the data from the member attribute m_name
	 * @param double latitude : gets the data from the member attribute m_latitude
	 * @param double longitude : gets the data from the member attribute m_longitude
	 * @return void
	 */
	void  getAllDataByReference(string& name,double& latitude,double& longitude)const;
	/**
	 * calculateDistance calculates distance between two
	 * waypoints and returns the distance.
	 * Distance is calculated according to the formula
	 * dist = Radius*invcos(sin (latitude_1)*sin( latitude_2)+
	 *        cos(latitude_1)*cos(latitude_2)*cos(longitude_1-longitude_2))
	 * where Radius is earth radius = 6378km
	 * @ param const CWaypoint& wp : The reference of waypoint whose distance to be calculated from another
	 * @return double : Distance between two waypoints
	 */
	double calculateDistance(const CWaypoint& wp);
	/**
	 * Virtual destructor is used as it has a derived class
	 */
	virtual ~CWaypoint();
	/**
	 * Friend function implemented for print function with
	 * operator overloading of operator <<
	 * @param outstream object and reference of a Waypoint object
	 * @return an outstream object
	 */
	friend ostream& operator <<(ostream& out, CWaypoint& origin);

};


#endif /* CWAYPOINT_H_ */
