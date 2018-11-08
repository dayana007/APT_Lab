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
#include "CWaypoint.h"

class CWpDatabase
{
private:
	map <string, CWaypoint> WpDatabase;

public:
	CWpDatabase();
	void addWaypoint(const CWaypoint&);
	CWaypoint* getPointerToWaypoint(string name);
	void print();
	void traverseWPDatabase( list<CWaypoint>& refToListOfCWp ) const;
	bool clearWpDatabase();
	virtual ~CWpDatabase();
};

#endif /* CWPDATABASE_H_ */
