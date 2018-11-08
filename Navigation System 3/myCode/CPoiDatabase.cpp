/*
 * CPoiDatabase.cpp
 *
 *  Created on: 29 Oct 2016
 *      Author: dayan
 */

#include "CPoiDatabase.h"

/** Default constructor is called
 */

CPoiDatabase::CPoiDatabase()
{

}

/**
 * This function adds a POI to the database created
 * @param reference of the POI object to be added to the database
 * @return void
 */

void CPoiDatabase::addPoi(const CPOI& poi)
{
	string strPOIName = poi.getName();
	CDatabaseTemplate<string, CPOI>:: add(strPOIName, poi);
}

/** This function returns the address of the requested  POI from
 * the Database
 * @param string name : name of the POI that needs to be retreaved from database
 * @return Address the required POI
 */

CPOI* CPoiDatabase::getPointerToPoi(string name)
{
    return CDatabaseTemplate<string, CPOI>:: getPointerToObj(name);
}
/**
 * Print POI database
 */
void CPoiDatabase::print()
{
	CDatabaseTemplate<string, CPOI>:: print();
}
/**
 * Copy the database from map to a list
 */
//void CPoiDatabase::traversePOIDatabase( list<CPOI>& refToListOfCPoi)const
//{
//	CDatabaseTemplate<string, CPOI>:: traverseDatabase(refToListOfCPoi);
//}
bool CPoiDatabase::traversePOIDatabase( list<CPOI>& refToListOfCPoi)const
{
	if(CDatabaseTemplate<string, CPOI>:: traverseDatabase(refToListOfCPoi))
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
 * Clear the complete databse
 */
bool CPoiDatabase::clearPoiDatabase()
{
	return CDatabaseTemplate<string, CPOI>:: clearDatabase();
}
/**
 * Destructor
 */
CPoiDatabase::~CPoiDatabase()
{

}


