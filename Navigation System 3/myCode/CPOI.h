/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOI.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CPOI_H
#define CPOI_H

#include <iostream>
#include <string>
#include "CWaypoint.h"
using namespace std;

/**
 * enum is defined to store the types of POI's available
 */

enum t_poi { DEFAULT,RESTAURANT,SIGHTSEEING,AIRPORT,UNIVERSITY};

/**
 *  CPOI is a derived class of the base class CWaypoint
 */

class CPOI : public CWaypoint
{
private:
	/**
	 * @link aggregationByValue
	 * @supplierCardinality 1
	 * @clientCardinality 1
	 */
	t_poi m_type;
	string m_description;
public:

	/**
	 * Used to print all the information about a particular POI
	 * in degmmss format
	 * @return void
	 */
	void print(int format);
	/**
	 * Constructor is called
	 * @param t_poi type : initialises the member attribute m_type
	 * @param string name : initialises the member attribute m_name
	 * @param string description : initialises the member attribute m_description
	 * @param double latitude : initialises the member attribute m_latitude
	 * @param double longitude : initialises the member attribute m_longitude
	 */
	CPOI(t_poi type = DEFAULT , string name = "name",string description = "Description",double latitude = 0 ,double longitude = 0);
	/**
	 * All data of the POI is accessed with this function
	 * @param t_poi type : gets the data from the member attribute m_type
	 * @param string name : gets the data from the member attribute m_name
	 * @param string description : gets the data from the member attribute m_description
	 * @param double latitude : gets the data from the member attribute m_latitude
	 * @param double longitude : gets the data from the member attribute m_longitude
	 */
	void getAllDataByReference(string& name,double& latitude,double& longitude,t_poi& type,string& description);
	/**
	 * Conversion of POI type to corresponding string
	 * @ param POI type
	 * @return the appropriate string for the type
	 */
	string getStringFromPoiType(t_poi& type);
	/**
	 * Set all attributes of the object with the parameters passed
	 * @param t_poi type
	 * @param string name
	 * @param string description
	 * @param double latitude
	 * @param double longitude
	 * @return void
	 */
	void setAllDataByReference(t_poi type,string name,string description,double latitude,double longitude);
	/**
	 * Conversion of string to corresponding POI type
	 * @ param string
	 * @return the appropriate POI type
	 */
	t_poi getTypeFromstring(string type);

	/**
	 * Friend function which is the operator overloading of
	 * << and used for print
	 * @param outstream object and reference of a POI object
	 * @return an outstream object
	 */
	friend ostream& operator <<(ostream& out, CPOI& c);
};
/********************
 **  CLASS END
 *********************/
#endif /* CPOI_H */
