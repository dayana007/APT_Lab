/*
 * CCSVStorage.h
 *
 *  Created on: 5 Dec 2016
 *      Author: dayan
 */

#ifndef CCSVSTORAGE_H_
#define CCSVSTORAGE_H_

#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>
#include <sstream>
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CPersistentStorage.h"

using namespace std;

/**
 * Derived class from the base class CPersistentStorage
 * which acts as an interface for the persistent storage
 * component
 */

class CCSVStorage: public CPersistentStorage
{
private:
	/**
	 * The name of the media for persistence storage
	 */
	string sMediaName;

	/**
	 *The filestream object for reading and writing
	 */
	fstream FileDatabase;
	/**
	 * Error checks and handling when data is read from csv file
	 * for waypoints
	 * @param line the string that is read from csv file
	 * @param linecount the number of lines of strings read
	 * from csv file
	 * @return true if there are no errors detected
	 */
	bool csvFilecheckWp(string& line,int& linecount);
	/**
	 * Error checks and handling when data is read from csv file
	 * for Point of interests
	 * @param line the string that is read from csv file
	 * @param linecount the number of lines of strings read
	 * from csv file
	 * @return true if there are no errors detected
	 */
	bool csvFilecheckPoi(string& line,int& linecount);

public:

	/**
	 * Set the name of the media to be used for persistent storage.
	 * The exact interpretation of the name depends on the implementation
	 * of the component.
	 *
	 * @param name the media to be used
	 */
	void setMediaName(string name);

	/**
	 * Write the data to the persistent storage.
	 *
	 * @param waypointDb the data base with way points
	 * @param poiDb the database with points of interest
	 * @return true if the data could be saved successfully
	 */
	bool writeData (const CWpDatabase& waypointDb,  const CPoiDatabase& poiDb);
	/**
	 * Fill the databases with the data from persistent storage. If
	 * merge mode is MERGE, the content in the persistent storage
	 * will be merged with any content already existing in the data
	 * bases. If merge mode is REPLACE, already existing content
	 * will be removed before inserting the content from the persistent
	 * storage.
	 *
	 * @param waypointDb the the data base with way points
	 * @param poiDb the database with points of interest
	 * @param mode the merge mode
	 * @return true if the data could be read successfully
	 */
	bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb, MergeMode mode);

	/**
	 * Destructor
	 */

	~CCSVStorage();
};


#endif /* CCSVSTORAGE_H_ */
