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
#include "CPersistentStorage.h"

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
//	CWpDatabase Wp;
//	CPoiDatabase POIw;
//	CWaypoint CWaPo1("AMSTERDAM",52.3702,4.8952);
//	CWaypoint CWaPo2("DARMSTADT",49.8728,8.6512);
//	CWaypoint CWaPo3("BERLIN",52.5166,13.4);
//	CWaypoint CWaPo4("TOKYO",35.6895,139.6917);

//	// TODO: Fügen Sie ab hier Ihren Programmcode ein
//	cout << "Navigation System 2 gestarted." << endl << endl;
//	Wp.addWaypoint(CWaPo1);
//	Wp.addWaypoint(CWaPo2);
//	Wp.addWaypoint(CWaPo3);
//	Wp.addWaypoint(CWaPo4);
//  //Wp.print();
//////
//////	CWaypoint* pWp;
//////	pWp = Wp.getPointerToWaypoint("AMSTERDAM");
//////	cout<<pWp->getName()<<endl;
//////	//Wp.getPointerToWaypoint("INDIA")->getName();
	//CPOI POI1(RESTAURANT,"MENSA","Best Mensa in the world",49.866,8.6384);
//	POI1.setType(POI);
//	CPOI POI2(RESTAURANT,"Sitte","More Expensive but also good",49.869,8.656);
//	POI2.setType(POI);
//	CPOI POI3(SIGHTSEEING,"Schloss","History of Darmstadt",59.983,8.633);
//	POI3.setType(POI);
//	CPOI POI4(SIGHTSEEING,"Tulip Gardens","Nature",52.271,4.546);
//	POI4.setType(POI);
//	CPOI POI5(UNIVERSITY,"University Of Amsterdam","Academia",52.355,4.955);
//	POI5.setType(POI);
//	CPOI POI6(SIGHTSEEING,"Madame Tussads","Wax Museum",52.372,4.892);
//	POI6.setType(POI);
////	CPOI POI7(SIGHTSEEING,"Berlin Wall","German Unification",52.535,13.390);
////	CPOI POI8(UNIVERSITY,"TU Berlin","Academia",52.512,13.326);
////	CPOI POI9(SIGHTSEEING,"Mount Fuji","Nature",35.360,138.727);
////	CPOI POI10(AIRPORT,"Haneda Airport","International transit",35.549,139.779);
//	POIw.addPoi(POI1);
//	POIw.addPoi(POI2);
//	POIw.addPoi(POI3);
//	POIw.addPoi(POI4);
//	POIw.addPoi(POI5);
//	POIw.addPoi(POI6);
////	POI.addPoi(POI7);
////	POI.addPoi(POI8);
////	POI.addPoi(POI9);
////	POI.addPoi(POI10);
////	POI.print();
////	cout<<POI.getPointerToPoi("MENSA")->getName()<<endl;
//	CRoute R1;
//	R1.connectToWpDatabase(&Wp);
//	R1.connectToPoiDatabase(&POIw);
//	R1.addWaypoint("DARMSTADT");
//	R1.addPoi("MENSA","DARMSTADT");
//	R1.addPoi("Tulip Gardens","AMSTERDAM");

	//R1.print();
//
//
//	CRoute R2;
//	R2.connectToWpDatabase(&Wp);
//	R2.connectToPoiDatabase(&POIw);
//	R2.addWaypoint("AMSTERDAM");
//	R2.addPoi("University Of Amsterdam","AMSTERDAM");
//	R2.print();
//	R2 + R1;
    //R2.print();
	//cout<<CWaPo1<<CWaPo2<<endl;


 CNavigationSystem Obj;
 Obj.setMedia("DISK");
 Obj.run();
 Obj.writeToPersistentStorage();
 Obj.readFromPersistentStorage(CStorage::MERGE);

return 0;
}
