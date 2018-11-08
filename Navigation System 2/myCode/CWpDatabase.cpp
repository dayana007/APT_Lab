/*
 * CWpDatabase.cpp
 *
 *  Created on: 26 Nov 2016
 *      Author: dayan
 */

#include "CWpDatabase.h"

CWpDatabase::CWpDatabase()
{
	// TODO Auto-generated constructor stub

}

void CWpDatabase::addWaypoint(const CWaypoint& wp)
{
	string strWPName = wp.getName();
	//WpDatabase.insert( make_pair( strWPName, wp) );
	WpDatabase.insert( pair<string, CWaypoint>(strWPName, wp));

}

void CWpDatabase::print()
{
	map< string, CWaypoint >::iterator Itr;

    Itr = WpDatabase.begin();
    while(Itr != WpDatabase.end())
    {
        /* Print added way points */
        cout <<Itr->first<<endl;
        Itr->second.print(MMSS);
        Itr++;
    }

}

CWaypoint* CWpDatabase::getPointerToWaypoint(string name)
{
    map< string, CWaypoint >::iterator Itr;

//    Itr = WpDatabase.find(name);
//
//    return &(Itr->second);
    bool flag = 0;
    for(Itr = WpDatabase.begin(); Itr != WpDatabase.end(); ++Itr)
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
    	cout<<"No POI's in the database "<<endl;
    	return NULL;
    }
    else
    {
    	return &(Itr->second);
    }

}

void CWpDatabase::traverseWPDatabase(list<CWaypoint>& refToListOfCWp)const
{
	map< string, CWaypoint >::const_iterator Itr;
	Itr = WpDatabase.begin();
	while(Itr != WpDatabase.end())
	{
		refToListOfCWp.push_back(Itr->second);
		Itr++;
	}

}

bool CWpDatabase::clearWpDatabase()
{
	WpDatabase.clear();
	return WpDatabase.empty();
}

CWpDatabase::~CWpDatabase()
{
	// TODO Auto-generated destructor stub
}


