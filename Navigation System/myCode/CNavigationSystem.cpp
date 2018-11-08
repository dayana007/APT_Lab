/*
 * CNavigationSystem.cpp
 *
 *  Created on: 29 Oct 2016
 *      Author: dayan
 */


#include "CNavigationSystem.h"


/** Default constructor of CNavigationSystem where
 * database coonection is established*/

CNavigationSystem::CNavigationSystem()
{
	this->m_route.connectToPoiDatabase(&this->m_PoiDatabase );
}

/** Run is the function which contains all testcases wherein the private functions
 * enter route, print and printdistancenextpoi are called and executed.
 * Database of POIs is also created here.
 * @return void
 */

void CNavigationSystem::run()
{
	this->m_PoiDatabase.addPoi(RESTAURANT,"MENSA","Best Mensa in the world",49.866,8.6384);
	this->m_PoiDatabase.addPoi(RESTAURANT,"Sitte","More Expensive but also good",49.869,8.656);
	this->m_PoiDatabase.addPoi(SIGHTSEEING,"Schloss","History of Darmstadt",59.983,8.633);
	this->m_PoiDatabase.addPoi(SIGHTSEEING,"Tulip Gardens","Nature",52.271,4.546);
	this->m_PoiDatabase.addPoi(UNIVERSITY,"University Of Amsterdam","Academia",52.355,4.955);
	this->m_PoiDatabase.addPoi(SIGHTSEEING,"Madame Tussads","Wax Museum",52.372,4.892);
	this->m_PoiDatabase.addPoi(SIGHTSEEING,"Berlin Wall","German Unification",52.535,13.390);
	this->m_PoiDatabase.addPoi(UNIVERSITY,"TU Berlin","Academia",52.512,13.326);
	this->m_PoiDatabase.addPoi(SIGHTSEEING,"Mount Fuji","Nature",35.360,138.727);
	this->m_PoiDatabase.addPoi(AIRPORT,"Haneda Airport","International transit",35.549,139.779);
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}

/** All Waypoints and POIs from database are added to the route  to create a trip
 * @return void
 */

void CNavigationSystem::enterRoute()
{

	CWaypoint CWaPo1("AMSTERDAM",52.3702,4.8952);
	CWaypoint CWaPo2("DARMSTADT",49.8728,8.6512);
	CWaypoint CWaPo3("BERLIN",52.5166,13.4);
	CWaypoint CWaPo4("TOKYO",35.6895,139.6917);

	this->m_route.addWaypoint( CWaPo1 );
	this->m_route.addWaypoint( CWaPo2 );
	this->m_route.addWaypoint( CWaPo3 );
	this->m_route.addWaypoint( CWaPo4 );
	this->m_route.addPoi("MENSA");
	this->m_route.addPoi("Sitte");
	this->m_route.addPoi("Tulip Gardens");
	this->m_route.addPoi("Madame Tussads");
	this->m_route.addPoi("Berlin Wall");
	this->m_route.addPoi("TU Berlin");
	this->m_route.addPoi("Mount Fuji");
	this->m_route.addPoi("Haneda Airport");
	this->m_route.addPoi("Berliner Allee");
}

/** All Waypoints and POIs available in the route are printed
 * @return void
 */

void CNavigationSystem::printRoute()
{

	this->m_route.print();

}

/** This method calculates the distance between the current position
 * the POIs added and determines the POI which is at the minimum distance
 * and prints the distance and the nearest POI, it uses the method from
 * CGPSSensor and CRoute to fulfill its functionality
 * @return void
 */

void CNavigationSystem::printDistanceCurPosNextPoi()
{
    CWaypoint Cobj;
    CPOI POI;
    double distance;
    Cobj = m_GPSSensor.getCurrentposition();
    distance = this->m_route.getDistanceNextPoi(Cobj,POI);
    if(distance == NOPOI)
    {
    	cout<<" Note : No POIS are found in the route"<<endl;
    }
    else
    {
        cout<<"Distance to next POI "<< distance<<endl;
        POI.print();
    }

}





