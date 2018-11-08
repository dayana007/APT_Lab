/*
 * CRoute.cpp
 *
 *  Created on: 29 Oct 2016
 *      Author: dayan
 */

#include "CRoute.h"

/** Default constructor wherein the maximum number of waypoints
 * and POIs added are passed as parameters.
 * Since there is a dynamic memeoy needed memory is allocated to store
 * waypoints and address of POIs from database using new operator
 * @param unsigned int maxWp : Maximum number of Waypoints to be added in the route
 * @param unsigned int maxPoi : Maximum number of POIs to be added in the route
 */

CRoute::CRoute()
{

	m_pPoiDatabase = NULL;
	m_pWpDatabase = NULL;

}

/**Copy constructor
*/
CRoute::CRoute(const CRoute& origin)
{

	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWpDatabase = origin.m_pWpDatabase;
	//listRoute = origin.listRoute;

	/** Deep copy implemented
	 *
	 */
	list<CWaypoint*>::const_iterator Itr;
	Itr = origin.listRoute.begin();
    while(Itr != origin.listRoute.end())
    {
    	listRoute.push_back(*Itr);
    	Itr++;
    }


}

CRoute& CRoute::operator =(const CRoute& origin)
{
	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWpDatabase = origin.m_pWpDatabase;
	//listRoute = origin.listRoute;

	/** Deep copy implemented
	 *
	 */
	list<CWaypoint*>::const_iterator Itr;
	Itr = origin.listRoute.begin();
    while(Itr != origin.listRoute.end())
    {
    	listRoute.push_back(*Itr);
    	Itr++;
    }
	return *this;

}

/** Destructor is called and the dynamically allocated memory
 * is deleted once its done with the usecase
 */

CRoute::~CRoute()
{

}

/** This method is used to get the address of POI Database available
 * to the pointer so that it can be accessed to add POIs to the route
 * @ param : Address of the database is passed inorder to connect Databse
 * @return void
 */

void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB)
{
	if(pPoiDB == NULL)
	{
		cout<<" Error : No Database in the project "<<endl;
	}
	else
	{
	    this->m_pPoiDatabase = pPoiDB;
	}
}

/** This method is used to get the address of  Waypoint Database available
 * to the pointer so that it can be accessed to add Waypoints to the route
 * @ param : Address of the database is passed inorder to connect Databse
 * @return void
 */

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB)
{
	if(pWpDB== NULL)
	{
		cout<<" Error : No Database in the project "<<endl;
	}
	else
	{
	    this->m_pWpDatabase = pWpDB;
	}
}

/** This method adds the POIs entered from database to the route, so that a trip
 * can be created with the POIs and Waypoints available
 * @ param string namePoi : NAme of the POI to be added from database to the route
 * @return void
 */

void CRoute::addPoi(string namePoi,string afterWp)
{
    CWaypoint* pWpItr;
    CWaypoint* pWp;
    CWaypoint* pPOI;
    bool flag = 0;
    pWp = m_pWpDatabase->getPointerToWaypoint(afterWp);
    pPOI = m_pPoiDatabase->getPointerToPoi(namePoi);
    list<CWaypoint*>::iterator Itr;
    Itr = listRoute.begin();
    if(pWp == NULL )
    {
    	cout<< "Could not find  Waypoint in the database"<<endl;
    }
    else if(pPOI == NULL)
    {
    	cout<< "Could not find POI in the database"<<endl;
    	listRoute.push_back(pWp);
    }
    else
    {
        while(Itr != listRoute.end())
        {
    	   pWpItr = *Itr;
           if(pWpItr->getName() == afterWp)
           {
        	  listRoute.insert( ++Itr, m_pPoiDatabase->getPointerToPoi(namePoi) );
        	  flag = 1;
              break;
           }
           else
           {
        	   Itr++;
           }

        }
        if(flag == 0)
        {
        	listRoute.push_back(pWp);
        	listRoute.push_back(pPOI);
        }
        else
        {
        	cout<<"Waypoints and POI's are inserted properly in the route"<<endl;
        }
    }

}

/** This method calculates the distance between the current position
 * the POIs added and determines the POI which is at the minimum distance
 * and returns the distance between them
 * @param const CWaypoint& Wp: reference of the Waypoint from which nearest POI should be found
 * @param CPOI& poi : Reference of the POI in the route to find the nearest POI
 * @return double: Minimum distance between Waypoint and POI
 */

double CRoute::getDistanceNextPoi(const CWaypoint& Wp, CPOI& poi)
{
    bool flag = 0;
    double Currdist,Mindist;
    CPOI* ptrPOI;
    list<CWaypoint*>:: iterator Itr;
    Itr = listRoute.begin();
    Mindist = numeric_limits<double>::max();
    while(Itr != listRoute.end())
    {
    	if ((*Itr)->getType()== POI)
    	{
    		ptrPOI = dynamic_cast<CPOI*>(*Itr);
    		Currdist = ptrPOI->calculateDistance(Wp);
    		flag = 1;
    	   	if(Currdist <= Mindist)
    	    {
    	    	Mindist = Currdist;
    	    	poi = *ptrPOI;
    	    }
    	   	Itr++;
    	}
    	else
    	{
    		Itr++;
    	}


    }

	if(flag == 0)
	{
		return NOPOI;
	}
	else
	{
       return Mindist;
	}
}

/** This method prints all the Waypoints and POIs
 * available in the route
 * @return void
 */

void CRoute::print()
{
	int countwp,countpoi;
    countwp = 0;
    countpoi = 0;
    list<CWaypoint*>::iterator Itr;
    CWaypoint* pWp;

    Itr = listRoute.begin();
    while(Itr != listRoute.end())
    {
        /* Print added way points */
        pWp = *Itr;
        if(pWp->getType()==WAYPOINT)
        {
        	/** Normal print without overloaded operators
        	 *
        	 */
        	pWp->print(MMSS);
        	countwp += 1;
        }
        else
        {
        	/** Overloaded operator without dynamic cast,
        	 * here since no virtual keyword is used in base class
        	 * print method compiler is not able to distinguish the print methods
        	 * in base class and derived class and hence it prints
        	 * with base class method
        	 *
        	 */
        	//pWp->print(MMSS);
            cout<<(*pWp)<<endl;

            /** Overloaded operator to print by using dynamic cast so that
             * the print method of POI (derived class) is called not
             * from the base class(Cwaypoint).Dynamic cast returns the address
             * of the casted object if the cast succeeds else NULL will be returned.
             * Dereferencing gives the object
             */

            cout<<(*dynamic_cast<CPOI*>(pWp))<<endl;

            /** Normal print method without overloading using dynamic cast
             *
             */

        	dynamic_cast<CPOI*>(pWp)->print(MMSS);
        	countpoi += 1;
        }
        Itr++;
    }
    cout<<"Our route has "<< countwp<< " waypoints and "<<countpoi<< " Point of interests"<<endl;

}

/** This method adds the Waypoints available to the route
 * by storing it in the newly allocated memory for Waypoints
 * @param const CWaypoint& Wp : reference of the waypoint to be added to route
 * @return void
 */

void CRoute::addWaypoint(string name)
{
	CWaypoint* pWp;
	pWp = this->m_pWpDatabase->getPointerToWaypoint(name);

    if(pWp== NULL)
    {
         cout<<"Error : Could not find Waypoint something not in the pool"<<endl;
    }
    else
    {
    	listRoute.push_back(pWp);
    }
}

void CRoute::operator +=(string name)
{
//	CWaypoint* pPOI;
//	addWaypoint( name);
//	pPOI = m_pPoiDatabase->getPointerToPoi(name);
//	if(pPOI == NULL)
//    {
//    	cout<< "Could not find POI in the database"<<endl;
//    }
//	else
//	{
//		listRoute.push_back(pPOI);
//	}
	addPoi(name,name);
}

CRoute& CRoute::operator + (CRoute& origin)
{
	if((m_pPoiDatabase == origin.m_pPoiDatabase)&&(m_pWpDatabase == origin.m_pWpDatabase))
	{
		listRoute.merge(origin.listRoute);
		return *this;
	}
	else
	{
		cout<<" Routes belong to different database and hence cannot be added"<<endl;
		listRoute.clear();
		return *this;
	}

}
