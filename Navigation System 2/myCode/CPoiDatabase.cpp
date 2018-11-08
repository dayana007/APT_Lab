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

/** This function adds a number of POI's to the database created
 * @param t_poi type : adds the member attribute m_type of object POI to the database
 * @param string name : adds the member attribute m_name of object POI to the database
 * @param string description : adds the member attribute m_description of object POI to the database
 * @param double latitude : adds the member attribute m_latitude of object POI to the database
 * @param double longitude : adds the member attribute m_longitude of object POI to the database
 * @return void
 */

void CPoiDatabase::addPoi(const CPOI& poi)
{

	string strPOIName = poi.getName();
	//m_POIDatabase.insert( make_pair( strPOIName, poi) );
	m_POIDatabase.insert( pair<string, CPOI>(strPOIName, poi));
}

/** This function returns the address of the requested  POI from
 * the Database
 * @param string name : name of the POI that needs to be retreaved from database
 * @return Address the required POI
 */

CPOI* CPoiDatabase::getPointerToPoi(string name)
{
    map< string, CPOI >::iterator Itr;

//    Itr = m_POIDatabase.find(name);
//
//    return &(Itr->second);
    bool flag = 0;
    for(Itr = m_POIDatabase.begin(); Itr != m_POIDatabase.end(); ++Itr )
    {
    	if(Itr->first == name )
    	{
    		flag = 1;
    		break;
    	}
    	else
    	{

    	}
    }

    if(flag == 0)
    {
    	return NULL;
    }
    else
    {
    	return &(Itr->second);
    }

}
void CPoiDatabase::print()
{
	map< string, CPOI >::iterator Itr;

    Itr = m_POIDatabase.begin();
    while(Itr != m_POIDatabase.end())
    {
        /* Print added way points */
        cout <<Itr->first <<endl;
        Itr->second.print(MMSS);
        Itr++;
    }
}

void CPoiDatabase::traversePOIDatabase(list<CPOI>& refToListOfCPoi) const
{
	map< string, CPOI >::const_iterator Itr;
	Itr = m_POIDatabase.begin();
	while(Itr != m_POIDatabase.end())
	{
		refToListOfCPoi.push_back(Itr->second);
		Itr++;
	}
}

bool CPoiDatabase::clearPoiDatabase()
{
	bool bResult;
	m_POIDatabase.clear();
	bResult = m_POIDatabase.empty();
	return bResult;
}

CPoiDatabase::~CPoiDatabase()
{

}


