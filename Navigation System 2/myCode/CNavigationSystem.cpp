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
	this->m_route.connectToWpDatabase(&this->m_WpDatabase);
	this->m_route.connectToPoiDatabase(&this->m_PoiDatabase );
}

/** Run is the function which contains all testcases wherein the private functions
 * enter route, print and printdistancenextpoi are called and executed.
 * Database of POIs is also created here.
 * @return void
 */

void CNavigationSystem::run()
{
	CWaypoint CWaPo1("AMSTERDAM",52.3702,4.8952,WAYPOINT);
	CWaypoint CWaPo2("DARMSTADT",49.8728,8.6512,WAYPOINT);
	CWaypoint CWaPo3("BERLIN",52.5166,13.4,WAYPOINT);
	CWaypoint CWaPo4("TOKYO",35.6895,139.6917,WAYPOINT);
	this->m_WpDatabase.addWaypoint(CWaPo1);
	this->m_WpDatabase.addWaypoint(CWaPo2);
	this->m_WpDatabase.addWaypoint(CWaPo3);
	this->m_WpDatabase.addWaypoint(CWaPo4);
	CPOI POI1(RESTAURANT,"MENSA","Best Mensa in the world",49.866,8.6384);
	POI1.setType(POI);
	CPOI POI2(RESTAURANT,"Sitte","More Expensive but also good",49.869,8.656);
	POI2.setType(POI);
	CPOI POI3(SIGHTSEEING,"Schloss","History of Darmstadt",59.983,8.633);
	POI3.setType(POI);
	CPOI POI4(SIGHTSEEING,"Tulip Gardens","Nature",52.271,4.546);
	POI4.setType(POI);
	CPOI POI5(UNIVERSITY,"University Of Amsterdam","Academia",52.355,4.955);
	POI5.setType(POI);
	CPOI POI6(SIGHTSEEING,"Madame Tussads","Wax Museum",52.372,4.892);
	POI6.setType(POI);
	CPOI POI7(SIGHTSEEING,"Berlin Wall","German Unification",52.535,13.390);
	POI7.setType(POI);
	CPOI POI8(UNIVERSITY,"TU Berlin","Academia",52.512,13.326);
	POI8.setType(POI);
	CPOI POI9(SIGHTSEEING,"Mount Fuji","Nature",35.360,138.727);
	POI9.setType(POI);
	CPOI POI10(AIRPORT,"Haneda Airport","International transit",35.549,139.779);
	POI10.setType(POI);
	this->m_PoiDatabase.addPoi(POI1);
	this->m_PoiDatabase.addPoi(POI2);
	this->m_PoiDatabase.addPoi(POI3);
	this->m_PoiDatabase.addPoi(POI4);
	this->m_PoiDatabase.addPoi(POI5);
	this->m_PoiDatabase.addPoi(POI6);
	this->m_PoiDatabase.addPoi(POI7);
	this->m_PoiDatabase.addPoi(POI8);
	this->m_PoiDatabase.addPoi(POI9);
	this->m_PoiDatabase.addPoi(POI10);
//	enterRoute();
//	printRoute();
//	printDistanceCurPosNextPoi();
}

/** All Waypoints and POIs from database are added to the route  to create a trip
 * @return void
 */

void CNavigationSystem::enterRoute()
{
   this->m_route.addWaypoint("AMSTERDAM");
   this->m_route.addWaypoint("DARMSTADT");
   this->m_route.addWaypoint("BERLIN");
   this->m_route.addWaypoint("TOKYO");

	this->m_route.addPoi("MENSA","DARMSTADT");
	this->m_route.addPoi("Sitte","DARMSTADT");
	this->m_route.addPoi("Madame Tussads","AMSTERDAM");
	this->m_route.addPoi("Berlin Wall","BERLIN");
	this->m_route.addPoi("TU Berlin","BERLIN");
	this->m_route.addPoi("Mount Fuji","TOKYO");
	this->m_route.addPoi("Haneda Airport","TOKYO");
	this->m_route.addPoi("Berliner Allee","DARMSTADT");
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
        POI.print(MMSS);
    }

}

bool CNavigationSystem::readFromPersistentStorage(CStorage::MergeMode mode)
{
    bool bResult = false;
    bResult = m_CPerObj.readData(m_WpDatabase,m_PoiDatabase,CStorage::REPLACE);
    return bResult;
}

bool CNavigationSystem::writeToPersistentStorage()
{
	bool bResult = false;
	bResult = m_CPerObj.writeData(m_WpDatabase,m_PoiDatabase);
	return bResult;
}

void CNavigationSystem::setMedia(string name)
{
	m_CPerObj.setMediaName(name);
}
