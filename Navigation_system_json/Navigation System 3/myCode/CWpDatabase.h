/*
 * CWpDatabase.h
 *
 *  Created on: 26 Nov 2016
 *      Author: dayan
 */

#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_

#include <iostream>
#include <map>
#include <list>
#include "CDatabaseTemplate.h"

class CWpDatabase : public CDatabaseTemplate<string, CWaypoint>
{

public:

	/**
	 * Default constructor is called
	 */
	CWpDatabase();
	/**
	 * This function adds a waypoint to the database created
	 * @param reference of the waypoint object to be added to the database
	 * @return void
	 */
	void addWaypoint(const CWaypoint&);
	/**
	 * This function returns the address of the requested  Waypoint from
	 * the Database
	 * @param string name : name of the  Waypoint that needs to be retreaved from database
	 * @return Address the required  Waypoint
	 */
	CWaypoint* getPointerToWaypoint(string name);
	/**
	 * Print Waypoint in the database according to the name
	 * @return void
	 */
	void print();
	/**
	 * Copy the database from map to a list inorder
	 * to access it in persistence storage
	 * @param list of Waypoint object
	 * @return void
	 */
	//void traverseWPDatabase( list<CWaypoint>& refToListOfCWp ) const;
	bool traverseWPDatabase( list<CWaypoint>& refToListOfCWp ) const;
	/**
	 * Clear the complete database inorder to replace the database
	 * with persistent storage file contents
	 * @return true if databse is properly cleared
	 */
	bool clearWpDatabase();
	/**
	 * Destructor
	 */
	~CWpDatabase();
};

#endif /* CWPDATABASE_H_ */
