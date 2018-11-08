// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
#include "CWaypoint.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CNavigationSystem.h"
#include "CCSVStorage.h"

#define TESTSTUB
#undef TESTSTUB
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>

using namespace std;	// Erspart den scope vor Objekte der
// C++-Standard-Bibliothek zu schreiben
// z.B. statt "std::cout" kann man "cout" schreiben

// Inkludieren Sie hier die Header-Files Ihrer Klassen, z.B.
// #include "CFraction.h"


// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main (void)
{
	/** Testcases for all other classes CWaypoint,CPOI,CWpDatabase,
	 * CPOIDatabase,CRoute are tested below
	 */
#ifdef TESTSTUB
	CWpDatabase WayPo;
	CPoiDatabase PoiInt;
	CWaypoint CWaPo1("AMSTERDAM",52.3702,4.8952);
	CWaypoint CWaPo2("DARMSTADT",49.8728,8.6512);
	CWaypoint CWaPo3("BERLIN",52.5166,13.4);
	CWaypoint CWaPo4("TOKYO",35.6895,139.6917);

	// TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "Navigation System 3 gestarted." << endl << endl;
	/**
	 *Testcase for Addition of waypoints to database
	 */
	WayPo.addWaypoint(CWaPo1);
	WayPo.addWaypoint(CWaPo2);
	WayPo.addWaypoint(CWaPo3);
	WayPo.addWaypoint(CWaPo4);
	WayPo.print();

	CWaypoint* pWp;
	pWp = WayPo.getPointerToWaypoint("AMSTERDAM");
	cout<<pWp->getName()<<endl;
	//WayPo.getPointerToWaypoint("INDIA")->getName();
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
	CPOI POI8(UNIVERSITY,"TU Berlin","Academia",52.512,13.326);
	CPOI POI9(SIGHTSEEING,"Mount Fuji","Nature",35.360,138.727);
	CPOI POI10(AIRPORT,"Haneda Airport","International transit",35.549,139.779);
	/**
	 *Testcase for Addition of POI's to database
	 */
	PoiInt.addPoi(POI1);
	PoiInt.addPoi(POI2);
	PoiInt.addPoi(POI3);
	PoiInt.addPoi(POI4);
	PoiInt.addPoi(POI5);
	PoiInt.addPoi(POI6);
	PoiInt.addPoi(POI7);
	PoiInt.addPoi(POI8);
	PoiInt.addPoi(POI9);
	PoiInt.addPoi(POI10);
	PoiInt.print();
	cout<<PoiInt.getPointerToPoi("MENSA")->getName()<<endl;
	CRoute R1;
	/**
	 * Testcase for connecting to waypoint and POI
	 * database
	 */
	R1.connectToWpDatabase(&WayPo);
	R1.connectToPoiDatabase(&PoiInt);
	/**
	 *Testcase for Addition of POI's and waypoints to
	 *the route
	 */
	R1.addWaypoint("DARMSTADT");
	R1.addPoi("MENSA","DARMSTADT");
	R1.addPoi("Tulip Gardens","AMSTERDAM");
	/**
	 * Testcase for ading POI or Waypoint
	 * with operator overloading
	 */
	R1 += ("India");
	R1.print();


	CRoute R2;
	R2.connectToWpDatabase(&WayPo);
	R2.connectToPoiDatabase(&PoiInt);
	R2.addWaypoint("AMSTERDAM");
	R2.addPoi("University Of Amsterdam","AMSTERDAM");
	R2.print();
	/**
	 * Testcase for ading two routes
	 * with operator overloading
	 */
	R2 + R1;
	R2.print();
	CRoute R3;
	R2 + R3;
	R3.print();
	/**
	 * Testcase for printing
	 * with operator overloading
	 */
	cout<<CWaPo1<<CWaPo2<<endl;
	/**
	 * Test cases for checking read and write operations from
	 * and to persistent storage and database
	 */
	CCSVStorage Obj1;
	Obj1.setMediaName("DISK");
	Obj1.writeData(WayPo,PoiInt);
	Obj1.readData(WayPo,PoiInt,CCSVStorage::REPLACE);
	Obj1.readData(WayPo,PoiInt,CCSVStorage::MERGE);
	Obj1.writeData(WayPo,PoiInt);
	cout<<WayPo.getCreatedObjectCount()<<endl;
	cout<<PoiInt.getCreatedObjectCount()<<endl;
	cout<<WayPo.getAliveObjectCount()<<endl;
	cout<<PoiInt.getAliveObjectCount()<<endl;

#endif

	/**
	 * Test cases for checking read and write operations from
	 * and to persistent storage and database from navigation system
	 */
	CNavigationSystem Obj;
	Obj.setMedia("DISK");
	/**
	 * For testing purpose this can be uncommented
	 * and line 156 and  157 can be commented
	 */
//  Obj.run();
//	Obj.writeToPersistentStorage();
	Obj.readFromPersistentStorage(CCSVStorage::REPLACE);
//	Obj.run();
	//Obj.writeToPersistentStorage();


	return 0;
}
