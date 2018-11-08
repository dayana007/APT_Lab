/*
 * CJsonPersistence.h
 *
 *  Created on: 6 Jan 2017
 *      Author: dayan
 */

#ifndef CJSONPERSISTENCE_H_
#define CJSONPERSISTENCE_H_

#include <string>
#include <iostream>
#include <fstream>
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CJsonScanner.h"
using namespace std;
using namespace APT;

#define E_NO_ERROR 0
#define E_MISSING_BEGIN_OBJECT -1
#define E_DB_NAME -2
#define E_ATTR_NAME -3
#define E_NAME_SEPARATOR -4
#define E_BEG_ARRAY -5
#define E_VALUE     -6
#define E_VALUE_SEP -7
#define E_MISSING_END_OBJECT -8
#define E_MISSING_END_ARRAY -9
#define E_NO_FILE -10
#define E_INVALLID_CHARACTER -11
#define E_EMPTY_FILE -12

enum PersistentStates{ IDLE,
					   W_DBNAME,
					   W_BEGARRAY,
					   W_DBOBJ_BEG,
					   W_ATTRNAME,
					   W_NAMESEP,
					   W_VALUE,
					   W_VALSEP,
	                   S_ENDOBJ,
	                   W_DBOBJ_END,
	                   S_ENDARRAY};
class CJsonPersistence
{
private:
	string sMediaName;
	fstream JsonFileDatabase;
	void writeWaypointData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb);
	void writePoiData(const CPoiDatabase& poiDb,const CWpDatabase& waypointDb);
public:
	CJsonPersistence();
	virtual ~CJsonPersistence();
	void setMediaName(string name);
	void writeData( const CWpDatabase& waypointDb,  const CPoiDatabase& poiDb );
	void readData( CPoiDatabase& poiDb, CWpDatabase& waypointDb);
};

#endif /* CJSONPERSISTENCE_H_ */
