/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CROUTE.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CROUTE_H
#define CROUTE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits>
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"

using namespace std;

#define MAXNOWP 4
#define NOPOI -9999

class CRoute {
private:
	/**
	 * @link aggregation
	 * @clientCardinality 1
	 * @supplierCardinality 1..*
	 */
	//CWaypoint* m_pCWaypoint;
	//      unsigned int m_maxWp;
	//      unsigned int m_nextWp;
	//      CPOI** m_pPoi;
	//      unsigned int m_maxPoi;
	//      unsigned int m_nextPoi;
	/**
	 * @clientCardinality 0..*
	 * @supplierCardinality 1
	 */

	/**
	 * List to store the added waypoints and POI's
	 */
	list<CWaypoint*> listRoute;

	/**
	 * Pointer to the waypoint database
	 */
	CWpDatabase* m_pWpDatabase;

	/**
	 * Pointer to the POI database
	 */
	CPoiDatabase* m_pPoiDatabase;

public:
	/**
	 * Default constructor wherein the maximum number of waypoints
	 * and POIs added are passed as parameters.
	 * Since there is a dynamic memeoy needed memory is allocated to store
	 * waypoints and address of POIs from database using new operator
	 * @param unsigned int maxWp : Maximum number of Waypoints to be added in the route
	 * @param unsigned int maxPoi : Maximum number of POIs to be added in the route
	 */
	CRoute();
	/**
	 * Copy constructor, where one object can be copied to another
	 * param reference of the constructor to be copied
	 */
	CRoute(const CRoute& origin);
	/**
	 * Destructor is called and the dynamically allocated memory
	 * is deleted once its done with the usecase
	 */
	~ CRoute();

	/**
	 * This method is used to get the address of POI Database available
	 * to the pointer so that it can be accessed to add POIs to the route
	 * @ param : Address of the database is passed inorder to connect Databse
	 * @return bool: to show properly connected or not
	 */
	bool connectToPoiDatabase(CPoiDatabase* pPoiDB = NULL);

	/**
	 * This method is used to get the address of  Waypoint Database available
	 * to the pointer so that it can be accessed to add Waypoints to the route
	 * @ param : Address of the database is passed inorder to connect Databse
	 * @return bool: to show properly connected or not
	 */

	bool connectToWpDatabase(CWpDatabase* pWpDB = NULL);

	/** This method adds the POIs entered from database to the route, so that a trip
	 * can be created with the POIs and Waypoints available
	 * @ param string namePoi : NAme of the POI to be added from database to the route
	 * @param string afterWp : Name of the waypoint after which the POI should be added
	 * @return bool: to show whether adding to route was successful or not
	 */
	bool addPoi(string namePoi,string afterWp);

	/**
	 * This method adds the Waypoints available to the route
	 * by storing it in the newly allocated memory for Waypoints
	 * @param string name : name of the POI to be added from database to the route
	 * @return void
	 */
	bool addWaypoint(string name);

	/** This method calculates the distance between the current position
	 * the POIs added and determines the POI which is at the minimum distance
	 * and returns the distance between them
	 * @param const CWaypoint& Wp: reference of the Waypoint from which nearest POI should be found
	 * @param CPOI& poi : Reference of the POI in the route to find the nearest POI
	 * @return double: Minimum distance between Waypoint and POI
	 */
	//double getDistanceNextPoi(const CWaypoint& Wp, CPOI& poi);
	/**
	 * This method prints all the Waypoints and POIs
	 * available in the route
	 * @return void
	 */
	void print();
	/**
	 * Additionof a waypoint or POI to the end of the route
	 * by passing its name and if it is present in the database
	 * If both waypoint and POI are present , then first waypoint
	 * is added and then the POI
	 * @param string name: name of waypoint or POI to be added
	 * @return void
	 */
	void operator +=(string name);
	/**
	 * Copying one route to another by using operator overloading
	 * of = operator
	 * @param constant refernce of the route to be equated
	 * @return reference of the route to which other route
	 * was copied
	 */
	CRoute& operator =(const CRoute& origin);

	/**
	 * Operator overloading of + operator by which two routes
	 * can be added to each other.
	 * @param reference of the route to be added to another
	 * @return refernce of the route to which another route is added
	 */
	CRoute operator +(const CRoute& lhs);

	/**
	 * Get the contents of whole route to a constant vector of const Waypoint
	 * pointers in the order in which it is stored in the route
	 */
	const vector<const CWaypoint*> getRoute();
};
/********************
 **  CLASS END
 *********************/
#endif /* CROUTE_H */
