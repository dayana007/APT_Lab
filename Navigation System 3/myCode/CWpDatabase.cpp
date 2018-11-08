/*
 * CWpDatabase.cpp
 *
 *  Created on: 26 Nov 2016
 *      Author: dayan
 */

#include "CWpDatabase.h"

/**
 * Default constructor is called
 */
CWpDatabase::CWpDatabase()
{
	// TODO Auto-generated constructor stub

}
/**
 * This function adds a waypoint to the database created
 * @param reference of the waypoint object to be added to the database
 * @return void
 */
void CWpDatabase::addWaypoint(const CWaypoint& wp)
{
	string strWPName = wp.getName();
	CDatabaseTemplate<string, CWaypoint>:: add(strWPName, wp);

}
/**
 * Print Waypoint in the database according to the name
 * @return void
 */
void CWpDatabase::print()
{
	CDatabaseTemplate<string, CWaypoint>:: print();
}
/**
 * This function returns the address of the requested  Waypoint from
 * the Database
 * @param string name : name of the  Waypoint that needs to be retreaved from database
 * @return Address the required  Waypoint
 */
CWaypoint* CWpDatabase::getPointerToWaypoint(string name)
{
    return CDatabaseTemplate<string, CWaypoint>:: getPointerToObj(name);
}
/**
 * Copy the database from map to a list inorder
 * to access it in persistence storage
 * @param list of Waypoint object
 * @return void
 */
//void CWpDatabase::traverseWPDatabase(list<CWaypoint>& refToListOfCWp)const
//{
//	CDatabaseTemplate<string, CWaypoint>:: traverseDatabase(refToListOfCWp);
//}
bool CWpDatabase::traverseWPDatabase(list<CWaypoint>& refToListOfCWp)const
{
	if(CDatabaseTemplate<string, CWaypoint>:: traverseDatabase(refToListOfCWp))
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
 * Clear the complete database inorder to replace the database
 * with persistent storage file contents
 * @return true if databse is properly cleared
 */
bool CWpDatabase::clearWpDatabase()
{
	return CDatabaseTemplate<string, CWaypoint>:: clearDatabase();
}
/**
 * Destructor
 */
CWpDatabase::~CWpDatabase()
{
	// TODO Auto-generated destructor stub
}


