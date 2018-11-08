//============================================================================
// Name        : CWaypoint.cpp
// Author      : dayana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CWaypoint.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CNavigationSystem.h"

/** used to enable the testcases for classes like
 * CWaypoint,CPOI,CPOIDatabases etc
 */
#define TESTSTUB
//#undef TESTSTUB

int main()
{

	/** Testcases for all other classes CWaypoint,CPOI,CDatabase
	 * are tested below
	 */
   #ifdef TESTSTUB
	 string name,description;
	 double latitude,longitude;
	 t_poi type;
     cout<<"Testcases for CWaypoint "<<endl;
     cout<<"========================"<<endl;
	 CWaypoint CWaPo1("AMSTERDAM",52.3702,4.8952);
	 CWaypoint CWaPo2("DARMSTADT",49.8728,8.6512);
	 CWaypoint CWaPo3("BERLIN",52.5166,13.4);
	 CWaypoint CWaPo4("TOKYO",35.6895,139.6917);
	 CWaypoint newWayPoint;
	 cout<<"Print Method"<<endl;
	 cout<<"================="<<endl;
	 CWaPo1.print(1);
	 CWaPo2.print(2);
	 cout<< "Name as return value : "<<CWaPo3.getName()<<endl;
	 cout<< "Latitude as return value : "<<CWaPo4.getLatitude()<<endl;
	 cout<< "Longitude as return value : "<<newWayPoint.getLongitude()<<endl;
	/** The addresses of local variables passed in main file to get function is same as
	 * addresses of the parameters used inside the function as the parameters are passed
	 * by reference to the function
	 */
	cout<<"Address of local variable name "<<&name<<endl;
	cout<<"Address of local variable latitude "<<&latitude<<endl;
	cout<<"Address of local variable longitude "<<&longitude<<endl;
	CWaPo1.getAllDataByReference(name,latitude,longitude);
	cout<<" and a first real method "<<endl;
	cout<<" ======================="<<endl;
	cout<< "Distance between "<< CWaPo1.getName()<<" and "<<CWaPo4.getName()<<" is "<<CWaPo1.calculateDistance(CWaPo4)<<endl;
	cout<< "Distance between "<< CWaPo3.getName()<<" and "<<CWaPo4.getName()<<" is "<<CWaPo3.calculateDistance(CWaPo4)<<endl;

    cout<<"Testcases for CPOI "<<endl;
    cout<<"=================="<<endl;
	CPOI POI1(RESTAURANT,"MENSA","Best Mensa in the world",52.16,34.00);
	CPOI POI2(RESTAURANT,"Sitte","More Expensive but also good",22.16,14.01);
	CPOI POI3(SIGHTSEEING,"Schloss","History of Darmstadt",32.16,20.01);
	POI1.print();
	POI2.getAllDataByReference(name,latitude,longitude,type,description);

    cout<<"Testcases for CPOIDatabase"<<endl;
    cout<<"=========================="<<endl;
    CPOI* pCPOI;
	CPoiDatabase POIDATABASE;
	POIDATABASE.addPoi(RESTAURANT,"MENSA","Best Mensa in the world",52.16,34.00);
	POIDATABASE.addPoi(RESTAURANT,"Sitte","More Expensive but also good",22.16,14.01);
	POIDATABASE.addPoi(SIGHTSEEING,"Schloss","History of Darmstadt",32.16,20.01);
	pCPOI = POIDATABASE.getPointerToPoi(name);
	cout<<"Enter the POI to be searched "<<endl;
	cin>>name;
	pCPOI = POIDATABASE.getPointerToPoi(name);
	if(pCPOI == NULL)
	{
	   cout<<"Error : Could not find POI something not in the pool"<<endl;		;
	}
	else
	{
		pCPOI->print();
	}

  #endif

	cout<<" Welcome to Navigation System "<<endl;
	cout<<" ============================="<<endl;
	/** Object for NavigationSystem class is created
	*/
	CNavigationSystem naviSys;
	/*Testcases for CGPSSensor,CRoute, CNAvigation Systemare executed
	 */
	naviSys.run();
	return 0;
}
