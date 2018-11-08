/*
 * CPersistentStorage.cpp
 *
 *  Created on: 3 Dec 2016
 *      Author: dayan
 */

#include "CPersistentStorage.h"

void CStorage::setMediaName(string name)
{
	sMediaName = name;
}

bool CStorage::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb)
{
	bool bResult = false;
	CWaypoint cWpObj;
	CPOI cPoiObj;
	int errCount = 0;
	string namePoi,descriptionPoi;
	double latitudePoi,longitudePoi;
	t_poi typePoi;
	list<CWaypoint> cWpList;
	list<CWaypoint>:: iterator ItrWp;
	list<CPOI> cPoiList;
	list<CPOI>:: iterator ItrPoi;

	/** Setting the file in proper format in the sstorage
	 * and opening the file inorder to write data into it
	 */

	string sFilename;
	sFilename = sMediaName + "-wp.csv";
	FileDatabase.open(sFilename.c_str(), fstream::out);
	if(!FileDatabase.is_open())
	{
		cerr <<"File cannot be opened"<<endl;
		errCount++;
	}

	/** write data from waypoint database to the persistent
	 * storage file which is a .csv file stored in the hard
	 * disk
	 */
	waypointDb.traverseWPDatabase(cWpList);
	ItrWp = cWpList.begin();
	while(ItrWp!= cWpList.end())
	{
		cWpObj = *ItrWp;
		FileDatabase<<cWpObj.getName()<<";"<<cWpObj.getLatitude()<<";"<<cWpObj.getLongitude()<<endl;
		ItrWp++;

	}

	FileDatabase.close();

	/** write data from waypoint database to the persistent
	 * storage file which is a .csv file stored in the hard
	 * disk
	 */
	sFilename = sMediaName + "-poi.csv";
	FileDatabase.open(sFilename.c_str(), fstream::out);
	if(!FileDatabase.is_open())
	{
		cerr <<"File not found"<<endl;
		errCount++;
	}

	poiDb.traversePOIDatabase(cPoiList);
	ItrPoi = cPoiList.begin();
	while(ItrPoi!= cPoiList.end())
	{
		cPoiObj = *ItrPoi;
		cPoiObj.getAllDataByReference(namePoi,latitudePoi,longitudePoi,typePoi,descriptionPoi);
		FileDatabase<<cPoiObj.getStringFromPoiType(typePoi)<<";"<<namePoi<<";"<<descriptionPoi<<";"<<latitudePoi<<";"<<longitudePoi<<endl;
		ItrPoi++;

	}

	FileDatabase.close();
	if(errCount != 0)
	{
		bResult = false;
	}
	else
	{
		bResult = true;
	}

	return bResult;


}


bool CStorage::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
{

	bool bResult = false;
	int errCount = 0;
    static int countLine = 0;
    string sFilename;
    size_t sizeOfDataString = 0;
    string sSeparator = ";";
    string data;
    string dataToken;
    t_poi typePoi;
    vector<string>WpPoiData;
    //vector<string>POIData;
    CWaypoint cWpObj;
    CPOI cPoiObj;
	switch(mode)
	{
	     case REPLACE:
	     {

	    	 /** Replace for Waypoint database
	    	  * Clear the existing data base for waypoint
	    	  */
	    	 if(waypointDb.clearWpDatabase()== true)
	    	 {
	    		sFilename = sMediaName + "-wp.csv";
	    		FileDatabase.open(sFilename.c_str(), fstream::in);
	    		if(!FileDatabase.is_open())
	    		{
	    			cerr <<"File not found"<<endl;
	    			errCount++;
	    		}
	    		/** Read waypoint data from persistence storage to the
	    		 * Waypoint database
	    		 *
	    		 */
	    		while(!FileDatabase.eof())
	    		{
	    			 /* Get line from file */
	    			getline(FileDatabase,data);
	    			countLine++;
	    			/* Print for debug purposes */
	    			//cout<<data<<endl;
	    			 /* Break up line based on seperator, add individual tokens into vector */
	    			while((sizeOfDataString = data.find(sSeparator))!= string::npos)
	    			{
	    				dataToken = data.substr(0,sizeOfDataString);
	    				WpPoiData.push_back(dataToken);
	    				data.erase(0,sizeOfDataString+1);

	    			}
	    			if(data != "")
	    			{
	    				WpPoiData.push_back(data);
		    			/* Store information into a way point */
		    			cWpObj.set(WpPoiData[0],atof(WpPoiData[1].c_str()),atof(WpPoiData[2].c_str()));
		    			cWpObj.setType(WAYPOINT);
		    			waypointDb.addWaypoint(cWpObj);
	    			}
	    			/* Print all tokens , just for debug purposes */
//	    			for(unsigned int index = 0; index < wpData.size(); index++)
//	    			{
//	    				cout<<wpData[index]<<endl;
//	    			}

	    			WpPoiData.clear();

	    		}
	    		FileDatabase.close();
	    		/* Print the waypoint database, this step is optional for debug purposes */
	    		waypointDb.print();
	    		bResult = true;

	    	 }
	    	 else
	    	 {
	    		 bResult =  false;
	    	 }



	    	 /** Replace for POI Database
	    	  * Clear the existing data base for POI's
	    	  */
	    	 if(poiDb.clearPoiDatabase()== true)
	    	 {
	    		sFilename = sMediaName + "-poi.csv";
	    		FileDatabase.open(sFilename.c_str(), fstream::in);
	    		if(!FileDatabase.is_open())
	    		{
	    			cerr <<"File not found"<<endl;
	    			errCount++;
	    		}
	    		/** Read waypoint data from persistence storage to the
	    		 * Waypoint database
	    		 *
	    		 */
	    		WpPoiData.clear();
	    		while(!FileDatabase.eof())
	    		{
	    			 /* Get line from file */
	    			getline(FileDatabase,data);

	    			 /* Break up line based on seperator, add individual tokens into vector */

	    			while((sizeOfDataString = data.find(sSeparator))!= string::npos)
	    			{
	    				dataToken = data.substr(0,sizeOfDataString);
	    				WpPoiData.push_back(dataToken);
	    				data.erase(0,sizeOfDataString+1);

	    			}
	    			if(data != "")
	    			{
	    				WpPoiData.push_back(data);

	    				/** Stor information into POI
	    				 *
	    				 */
		    			typePoi = cPoiObj.getTypeFromstring(WpPoiData[0]);
		    			cPoiObj.setAllDataByReference(typePoi,WpPoiData[1],WpPoiData[2],atof(WpPoiData[3].c_str()),atof(WpPoiData[4].c_str()));
		    			cPoiObj.setType(POI);
		    			poiDb.addPoi(cPoiObj);
	    			}
	    			/* Print all tokens , just for debug purposes */
//	    			for(unsigned int index = 0; index < WpPoiData.size(); index++)
//	    			{
//	    				cout<<WpPoiData[index]<<endl;
//	    			}
	    			/* Store information into a way point */


	    			WpPoiData.clear();

	    		}
	    		FileDatabase.close();
	    		/* Print the waypoint database, this step is optional for debug purposes */
	    		poiDb.print();

	    	 }
	    	 else
	    	 {
	    		 errCount++;
	    	 }
	    	 break;
	     }
	     case MERGE:
	     {
	    	 /** Merge Waypoint database from persistent storage
	    	  *
	    	  */
	    		sFilename = sMediaName + "-wp.csv";
	    		FileDatabase.open(sFilename.c_str(), fstream::in);
	    		if(!FileDatabase.is_open())
	    		{
	    			cerr <<"File not found"<<endl;
	    			errCount++;
	    		}
	    		/** Read waypoint data from persistence storage to the
	    		 * Waypoint database
	    		 *
	    		 */
	    		while(!FileDatabase.eof())
	    		{
	    			 /* Get line from file */
	    			getline(FileDatabase,data);

	    			 /* Break up line based on seperator, add individual tokens into vector */
	    			while((sizeOfDataString = data.find(sSeparator))!= string::npos)
	    			{
	    				dataToken = data.substr(0,sizeOfDataString);
	    				WpPoiData.push_back(dataToken);
	    				data.erase(0,sizeOfDataString+1);

	    			}
	    			if(data != "")
	    			{
	    				WpPoiData.push_back(data);
	    				if(waypointDb.getPointerToWaypoint(WpPoiData[0])== NULL)
	    				{
			    			cWpObj.set(WpPoiData[0],atof(WpPoiData[1].c_str()),atof(WpPoiData[2].c_str()));
			    			cWpObj.setType(WAYPOINT);
			    			waypointDb.addWaypoint(cWpObj);
	    				}

	    			}
	    			WpPoiData.clear();
	    		}


	    		/* Print all tokens , just for debug purposes */
//	    		for(unsigned int index = 0; index < WpPoiData.size(); index++)
//	    		{
//    			   cout<<WpPoiData[index]<<endl;
//	    		}

	    		FileDatabase.close();
	    		waypointDb.print();


	    		/** Merge for POI Database with persistent storage data
		    	  *
		    	  */
	    		sFilename = sMediaName + "-poi.csv";
	    		FileDatabase.open(sFilename.c_str(), fstream::in);
	    		if(!FileDatabase.is_open())
	    		{
	    			cerr <<"File not found"<<endl;
	    			errCount++;
	    		}
	    		/** Read waypoint data from persistence storage to the
	    		 * Waypoint database
	    		 *
	    		 */
	    		while(!FileDatabase.eof())
	    		{
	    			 /* Get line from file */
	    			getline(FileDatabase,data);

	    			 /* Break up line based on seperator, add individual tokens into vector */
	    			while((sizeOfDataString = data.find(sSeparator))!= string::npos)
	    			{
	    				dataToken = data.substr(0,sizeOfDataString);
	    				WpPoiData.push_back(dataToken);
	    				data.erase(0,sizeOfDataString+1);

	    			}
	    			if(data != "")
	    			{
	    				WpPoiData.push_back(data);
	    				if(poiDb.getPointerToPoi(WpPoiData[1])== NULL)
	    				{
			    			typePoi = cPoiObj.getTypeFromstring(WpPoiData[0]);
			    			cPoiObj.setAllDataByReference(typePoi,WpPoiData[1],WpPoiData[2],atof(WpPoiData[3].c_str()),atof(WpPoiData[4].c_str()));
			    			cPoiObj.setType(POI);
			    			poiDb.addPoi(cPoiObj);
	    				}

	    			}
	    			WpPoiData.clear();
	    		}


	    		/* Print all tokens , just for debug purposes */
//	    		for(unsigned int index = 0; index < WpPoiData.size(); index++)
//	    		{
//    			   cout<<WpPoiData[index]<<endl;
//	    		}

	    		FileDatabase.close();
	    		poiDb.print();

             break;
	       }
	     default:
	     {
	    	 break;
	     }


	}

   if(errCount != 0)
   {
	   bResult =  false;
   }
   else
   {
	   bResult =  true;
   }
	return bResult;
}

CPersistentStorage::~CPersistentStorage()
{

}

CStorage::~CStorage()
{

}
