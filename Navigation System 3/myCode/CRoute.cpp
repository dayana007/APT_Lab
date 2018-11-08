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

/**
 * Copying one route to another by using operator overloading
 * of = operator
 * @param constant refernce of the route to be equated
 * @return reference of the route to which other route
 * was copied
 */
CRoute& CRoute::operator =(const CRoute& origin)
{
	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWpDatabase = origin.m_pWpDatabase;

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

/**
 * This method is used to get the address of POI Database available
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

/**
 * This method is used to get the address of  Waypoint Database available
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
 * @param string afterWp : Name of the waypoint after which the POI should be added
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
	list<CWaypoint*>::reverse_iterator Itr;
	Itr = listRoute.rbegin();

	if(m_pPoiDatabase == NULL)
	{
		cout<<"Error: No POI database found"<<endl;
	}
	else
	{
		if(pWp == NULL )
		{
			cout<< "Could not find  Waypoint in the database"<<endl;
		}
		else if(pPOI == NULL)
		{
			cout<< "Could not find POI in the database"<<endl;
			//listRoute.push_back(pWp);
		}
		else
		{
			while(Itr != listRoute.rend())
			{
				pWpItr = *Itr;
				if(pWpItr->getName() == afterWp)
				{
					listRoute.insert(Itr.base(), m_pPoiDatabase->getPointerToPoi(namePoi) );
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
				//listRoute.push_back(pWp);
				listRoute.push_back(pPOI);
			}
			else
			{
				//cout<<"Waypoints and POI's are inserted properly in the route"<<endl;
			}
		}
	}
}

/**
 * This method calculates the distance between the current position
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
	if(m_pPoiDatabase == NULL)
	{
		cout<<"No Poi Database found"<<endl;
		return NOPOI;
	}
	else
	{
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
}

/**
 * This method prints all the Waypoints and POIs
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
    if(m_pPoiDatabase == NULL && m_pWpDatabase == NULL)
    {
    	cout<<"No databases found"<<endl;
    }
    else
    {
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
			//pWp->print(MMSS);
			cout<<(*pWp)<<endl;
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
			//cout<<(*pWp)<<endl;

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

			//dynamic_cast<CPOI*>(pWp)->print(MMSS);
			countpoi += 1;
		}
		Itr++;
	}
	cout<<"Our route has "<< countwp<< " waypoints and "<<countpoi<< " Point of interests"<<endl;
    }

}

/**
 * This method adds the Waypoints available to the route
 * by storing it in the newly allocated memory for Waypoints
 * @param string name : name of the POI to be added from database to the route
 * @return void
 */

void CRoute::addWaypoint(string name)
{
	CWaypoint* pWp;
	if(m_pWpDatabase == NULL)
    {
		cout<<"Error : Waypoint database is not found"<<endl;
    }
	else
	{
		pWp = this->m_pWpDatabase->getPointerToWaypoint(name);

		if(pWp== NULL)
		{
			cout<<"Error : Could not find Waypoint in the database"<<endl;
		}
		else
		{
			listRoute.push_back(pWp);
		}
	}
}

/**
 * Additionof a waypoint or POI to the end of the route
 * by passing its name and if it is present in the database
 * If both waypoint and POI are present , then first waypoint
 * is added and then the POI
 * @param string name: name of waypoint or POI to be added
 * @return void
 */
void CRoute::operator +=(string name)
{
	CWaypoint* pPOI;
	if(m_pWpDatabase == NULL)
    {
		cout<<"Error : Waypoint database is not found"<<endl;
    }
	else
	{
		addWaypoint( name);
	}
	if(m_pPoiDatabase == NULL)
	{
		cout<<"Error: No POI database found"<<endl;
	}
	else
	{
		pPOI = m_pPoiDatabase->getPointerToPoi(name);
		if(pPOI == NULL)
		{
			cout<< "Error : Could not find POI in the database"<<endl;
		}
		else
		{
			listRoute.push_back(pPOI);
		}
		//addPoi(name,name);
	}
}

/**
 * Operator overloading of + operator by which two routes
 * can be added to each other.
 * @param reference of the route to be added to another
 * @return refernce of the route to which another route is added
 */
CRoute CRoute::operator +( const CRoute& lhs)
{
	CRoute addRoute;
	addRoute = lhs;
	if(((lhs.m_pPoiDatabase == m_pPoiDatabase)&&(m_pPoiDatabase!=NULL))&&((lhs.m_pWpDatabase == m_pWpDatabase)&&(m_pWpDatabase!= NULL)))
	{
		if(!(lhs.listRoute.empty()&& listRoute.empty()))
		{
			addRoute.listRoute.merge(listRoute);
			return addRoute;
		}
		else
		{
			cout<<"Routes are empty hence cannot be added"<<endl;
			addRoute.listRoute.clear();
			return addRoute;


		}
	}
	else
	{
		cout<<" Routes belong to different database and hence cannot be added"<<endl;
		addRoute.listRoute.clear();
		return addRoute;
	}

}
