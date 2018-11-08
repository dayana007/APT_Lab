/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOIDATABASE.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H

#include<iostream>
#include <string.h>
#include <map>
#include<list>
#include "CPOI.h"
#include "CDatabaseTemplate.h"


class CPoiDatabase : public CDatabaseTemplate<string, CPOI>
{

public:
	/**
	 * Default constructor is called
	 */
	CPoiDatabase();
	/**
	 * This function adds a POI to the database created
	 * @param reference of the POI object to be added to the database
	 * @return void
	 */
	void addPoi(const CPOI & poi);
	/**
	 * This function returns the address of the requested  POI from
	 * the Database
	 * @param string name : name of the POI that needs to be retreaved from database
	 * @return Address the required POI
	 */
	CPOI* getPointerToPoi(string name);
	/**
	 * Print POI in the database according to the name
	 * @return void
	 */
	void print();
	/**
	 * Copy the database from map to a list inorder
	 * to access it in persistence storage
	 * @param list of POI object
	 * @return void
	 */
	//void traversePOIDatabase( list<CPOI>& refToListOfCPoi ) const;
	bool traversePOIDatabase( list<CPOI>& refToListOfCPoi ) const;
	/**
	 * Clear the complete database inorder to replace the database
	 * with persistent storage file contents
	 * @return true if databse is properly cleared
	 */
	bool clearPoiDatabase();
	/**
	 * Destructor
	 */
	~CPoiDatabase();

};
/********************
 **  CLASS END
 *********************/
#endif /* CPOIDATABASE_H */
