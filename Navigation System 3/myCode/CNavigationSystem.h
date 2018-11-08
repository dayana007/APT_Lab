/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CNAVIGATIONSYSTEM.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CNAVIGATIONSYSTEM_H
#define CNAVIGATIONSYSTEM_H

#include <iostream>
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CCSVStorage.h"
#include "CJsonPersistence.h"
using namespace std;

class CNavigationSystem
{
private:
	/**
	 * @link aggregationByValue
	 * @clientCardinality 1
	 * @supplierCardinality 1
	 */
	CGPSSensor m_GPSSensor;
	/**
	 * @link aggregationByValue
	 * @clientCardinality 1
	 * @supplierCardinality 1*/
	CRoute m_route;
	/**
	 * @link aggregationByValue
	 * @clientCardinality 1
	 * @supplierCardinality 1
	 */
	CPoiDatabase m_PoiDatabase;
    /**
     * @link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1 
     */
	CWpDatabase m_WpDatabase;
	CCSVStorage m_CPerObj;
	CJsonPersistence m_CPerJsonObj;

	/**
	 *  All Waypoints and POIs from database are added to the route  to create a trip
	 * @return void
	 */
	void enterRoute();
	/**
	 * All Waypoints and POIs available in the route are printed
	 * @return void
	 */
	void printRoute();
	/**
	 * This method calculates the distance between the current position
	 * the POIs added and determines the POI which is at the minimum distance
	 * and prints the distance and the nearest POI, it uses the method from
	 * CGPSSensor and CRoute to fulfill its functionality
	 * @return void
	 */
	void printDistanceCurPosNextPoi();
public:

	/**
	 * Default constructor of CNavigationSystem where
	 * database coonection is established
	 */
	CNavigationSystem();
	/**
	 * Run is the function which contains all testcases wherein the private functions
	 * enter route, print and printdistancenextpoi are called and executed.
	 * Database of POIs is also created here.
	 * @return void
	 */
	void run();
	/**
	 *  Read from persistence storage to database can be
	 *  invoked with this function call in the navigation system
	 * @param mode of read either replace or merge
	 * @return true if read is succesful
	 */
	bool readFromPersistentStorage(CCSVStorage::MergeMode mode);
	/**
	 * Write to persistence storage from database can be
	 *  invoked with this function call in the navigation system
	 * @return true if write is succesful
	 */
	bool writeToPersistentStorage();

	/**
	 * Set the name of the media to be used for persistent storage
	 * from navigation system.
	 * @ return void
	 */
	void setMedia(string name);


};
/********************
 **  CLASS END
 *********************/
#endif /* CNAVIGATIONSYSTEM_H */
