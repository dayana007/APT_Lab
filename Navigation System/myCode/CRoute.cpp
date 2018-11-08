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

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi)
{
	m_maxWp        = maxWp;
	m_maxPoi       = maxPoi;
	m_nextWp       = 0;
	m_nextPoi      = 0;
	m_pPoiDatabase = NULL;
	m_pCWaypoint   = new CWaypoint[maxWp];
	m_pPoi		   = new CPOI*[maxPoi];
}

/**Copy constructor
*/
CRoute::CRoute(const CRoute& origin)
{

	/**Deep copy implemented inorder to avoid the changes done by the
	 * original constructor in the dynamic memory to the copied one
	 */
	m_pCWaypoint   = new CWaypoint[m_maxWp];
	for (unsigned int i = 0; i< m_maxWp;i++)
	{
		m_pCWaypoint[i] = origin.m_pCWaypoint[i];
	}

	/**Deep copy implemented inorder to avoid the changes done by the
	 * original constructor in the dynamic memory to the copied one
	 */
	m_pPoi         = new CPOI*[m_maxPoi];
	for (unsigned int i = 0; i< m_maxPoi;i++)
	{
		m_pPoi[i] = origin.m_pPoi[i];
	}
	m_maxWp        = origin.m_maxWp;
	m_maxPoi       = origin.m_maxPoi;
	m_nextPoi      = origin.m_nextPoi;
	m_nextWp       = origin.m_nextWp;
	m_pPoiDatabase = origin.m_pPoiDatabase;
}

/** Destructor is called and the dynamically allocated memory
 * is deleted once its done with the usecase
 */

CRoute::~CRoute()
{
	delete[]m_pCWaypoint;
	delete[]m_pPoi;
}

/** This method is used to get the address of Database available
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

/** This method adds the POIs entered from database to the route, so that a trip
 * can be created with the POIs and Waypoints available
 * @ param string namePoi : NAme of the POI to be added from database to the route
 * @return void
 */

void CRoute::addPoi(string namePoi)
{
	if(this->m_pPoiDatabase->getPointerToPoi(namePoi) == NULL)
	{
		cout<<"Error : Could not find POI something not in the pool"<<endl;
	}
	else
	{
	  if(m_nextPoi< m_maxPoi)
	  {
		   m_pPoi[m_nextPoi] = this->m_pPoiDatabase->getPointerToPoi(namePoi);
	       m_nextPoi++;
	  }
	  else
	  {
		  cout<<"Error : Maximum number of POI's possible in the route has reached" <<endl;
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
	unsigned int i,index;
	double Currdist,Mindist;

	if(m_nextPoi == 0)
	{
		Mindist = NOPOI;
	}
	else
	{

	   Mindist = m_pPoi[0]->calculateDistance(Wp);

	   for(i = 0; i< m_nextPoi;i++ )
	   {
		  Currdist = m_pPoi[i]->calculateDistance(Wp);
		  if(Currdist <= Mindist)
		  {
			  Mindist = Currdist;
			  index = i;
		  }
       }
	   poi = *(m_pPoi[index]);
	}

	return Mindist;

}

/** This method prints all the Waypoints and POIs
 * available in the route
 * @return void
 */

void CRoute::print()
{
	unsigned int iWaypoint,iPoi;

	cout<<"Our route has "<<m_nextWp<<" Waypoints and "<<m_nextPoi<< " Point of interests" <<endl;

	for(iWaypoint =0;iWaypoint<m_nextWp;iWaypoint++)
	{
		m_pCWaypoint[iWaypoint].print(MMSS);
	}

	for(iPoi=0;iPoi<m_nextPoi;iPoi++)
    {
		m_pPoi[iPoi]->print();
	}

}

/** This method adds the Waypoints available to the route
 * by storing it in the newly allocated memory for Waypoints
 * @param const CWaypoint& Wp : reference of the waypoint to be added to route
 * @return void
 */

void CRoute::addWaypoint( const CWaypoint& Wp)
{
	if(m_nextWp < m_maxWp)
	{
	   m_pCWaypoint[m_nextWp].set(Wp.getName(),Wp.getLatitude(),Wp.getLongitude());
	   m_nextWp++;
	}
	else
	{
	   cout<<"Error : Maximum number of Waypoints possible in the route has reached" <<endl;
	}

}




