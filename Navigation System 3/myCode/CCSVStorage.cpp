/*
 * CCSVStorage.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: dayan
 */


#include "CCSVStorage.h"

/**
 * Set the name of the media to be used for
 *  persistent storage.
 */

void CCSVStorage::setMediaName(string name)
{
	sMediaName = name;
}

/**
 * Write the data to the persistent storage.
 */

bool CCSVStorage::writeData(const CWpDatabase& waypointDb,
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
	sFilename = sMediaName + "-wp.txt";
	FileDatabase.open(sFilename.c_str(), fstream::out);
	if(!FileDatabase.is_open())
	{
		cerr <<"Waypoint File cannot be opened"<<endl;
		errCount++;
	}
	else
	{

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
	}

	/** write data from POI database to the persistent
	 * storage file which is a .csv file stored in the hard
	 * disk
	 */
	sFilename = sMediaName + "-poi.txt";
	FileDatabase.open(sFilename.c_str(), fstream::out);
	if(!FileDatabase.is_open())
	{
		cerr <<"POI File not found"<<endl;
		errCount++;
	}
	else
	{
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
	}

	/**
	 * Check whether any of the files failed to open and
	 * then return False
	 */
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

/**
 * Fill the databases with the data from persistent storage.
 * This can be filled either in Merge or Replace mode
 */

bool CCSVStorage::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
{

	bool bResultWp = false;
	bool bResultPoi = false;
	int countLineWp = 1;
	int countLinePoi = 1;
	string sFilename;
	size_t sizeOfDataString = 0;
	string sSeparator = ";";
	string data;
	string dataToken;
	t_poi typePoi;
	vector<string>WpPoiData;
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
			sFilename = sMediaName + "-wp.txt";
			FileDatabase.open(sFilename.c_str(), fstream::in);
			if(!FileDatabase.is_open())
			{
				cerr <<"Waypoint File not found"<<endl;
				bResultWp = false;
			}
			else
			{

				/** Read waypoint data from persistence storage to the
				 * Waypoint database
				 *
				 */
				while(!FileDatabase.eof())
				{
					/* Get line from file */
					getline(FileDatabase,data);
					if(data != "")
					{
						if(csvFilecheckWp(data,countLineWp)== true)
						{
							/* Break up line based on seperator, add individual tokens into vector */
							while((sizeOfDataString = data.find(sSeparator))!= string::npos)
							{
								dataToken = data.substr(0,sizeOfDataString);
								WpPoiData.push_back(dataToken);
								data.erase(0,sizeOfDataString+1);

							}
							WpPoiData.push_back(data);
							/* Store information into a way point */
							cWpObj.set(WpPoiData[0],atof(WpPoiData[1].c_str()),atof(WpPoiData[2].c_str()));
							cWpObj.setType(WAYPOINT);
							waypointDb.addWaypoint(cWpObj);
							WpPoiData.clear();
							countLineWp++;
							bResultWp = true;
						}

						else
						{
							countLineWp++;
							bResultWp = false;

						}
					}
				}
				FileDatabase.close();
				/* Print the waypoint database, this step is optional for debug purposes */
				waypointDb.print();

			}
		}
		else
		{
			bResultWp =  false;
		}



		/** Replace for POI Database
		 * Clear the existing data base for POI's
		 */
		if(poiDb.clearPoiDatabase()== true)
		{
			sFilename = sMediaName + "-poi.txt";
			FileDatabase.open(sFilename.c_str(), fstream::in);
			if(!FileDatabase.is_open())
			{
				cerr <<"POI File not found"<<endl;
				bResultPoi = false;
			}
			else
			{
				/** Read POI data from persistence storage to the
				 * POI database
				 *
				 */
				WpPoiData.clear();
				while(!FileDatabase.eof())
				{
					/* Get line from file */
					getline(FileDatabase,data);
					if(data != "")
					{

						if(csvFilecheckPoi(data,countLinePoi)== true)
						{
							/* Break up line based on seperator, add individual tokens into vector */

							while((sizeOfDataString = data.find(sSeparator))!= string::npos)
							{
								dataToken = data.substr(0,sizeOfDataString);
								WpPoiData.push_back(dataToken);
								data.erase(0,sizeOfDataString+1);

							}
							WpPoiData.push_back(data);

							/** Stor information into POI
							 *
							 */
							typePoi = cPoiObj.getTypeFromstring(WpPoiData[0]);
							cPoiObj.setAllDataByReference(typePoi,WpPoiData[1],WpPoiData[2],atof(WpPoiData[3].c_str()),atof(WpPoiData[4].c_str()));
							cPoiObj.setType(POI);
							poiDb.addPoi(cPoiObj);
							WpPoiData.clear();
							countLinePoi++;
							bResultPoi = true;
						}

						else
						{
							countLinePoi++;
							bResultPoi = false;
						}
					}
				}
				FileDatabase.close();
				/* Print the waypoint database, this step is optional for debug purposes */
				poiDb.print();

			}
		}
		else
		{
			bResultPoi = false;
		}
		break;
	}
	case MERGE:
	{
		/** Merge Waypoint database from persistent storage
		 *
		 */
		sFilename = sMediaName + "-wp.txt";
		FileDatabase.open(sFilename.c_str(), fstream::in);
		if(!FileDatabase.is_open())
		{
			cerr <<"Waypoint File not found"<<endl;
			bResultWp = false;
		}
		else
		{
			/** Read waypoint data from persistence storage to the
			 * Waypoint database
			 *
			 */
			while(!FileDatabase.eof())
			{
				/* Get line from file */
				getline(FileDatabase,data);
				if(data != "")
				{
					if(csvFilecheckWp(data,countLineWp)== true)
					{

						/* Break up line based on seperator, add individual tokens into vector */
						while((sizeOfDataString = data.find(sSeparator))!= string::npos)
						{
							dataToken = data.substr(0,sizeOfDataString);
							WpPoiData.push_back(dataToken);
							data.erase(0,sizeOfDataString+1);

						}
						WpPoiData.push_back(data);
						/**
						 * Check whether already existing in the database,
						 * if not merge the file contents with the database
						 */
						if(waypointDb.getPointerToWaypoint(WpPoiData[0])== NULL)
						{
							cWpObj.set(WpPoiData[0],atof(WpPoiData[1].c_str()),atof(WpPoiData[2].c_str()));
							cWpObj.setType(WAYPOINT);
							waypointDb.addWaypoint(cWpObj);
						}
						WpPoiData.clear();
						countLineWp++;
						bResultWp = true;
					}
					else
					{
						countLineWp++;
						bResultWp = false;
					}
				}

			}

			FileDatabase.close();
			waypointDb.print();
		}


		/** Merge for POI Database with persistent storage data
		 *
		 */
		sFilename = sMediaName + "-poi.txt";
		FileDatabase.open(sFilename.c_str(), fstream::in);
		if(!FileDatabase.is_open())
		{
			cerr <<"POI File not found"<<endl;
			bResultPoi = false;
		}
		else
		{
			/** Read POI data from persistence storage to the
			 * POI database
			 *
			 */
			WpPoiData.clear();
			while(!FileDatabase.eof())
			{
				/* Get line from file */
				getline(FileDatabase,data);
				if(data != "")
				{

					if(csvFilecheckPoi(data,countLinePoi)== true)
					{

						/* Break up line based on seperator, add individual tokens into vector */
						while((sizeOfDataString = data.find(sSeparator))!= string::npos)
						{
							dataToken = data.substr(0,sizeOfDataString);
							WpPoiData.push_back(dataToken);
							data.erase(0,sizeOfDataString+1);

						}
						WpPoiData.push_back(data);

						/**
						 * Check whether already existing in the database,
						 * if not merge the file contents with the database
						 */

						if(poiDb.getPointerToPoi(WpPoiData[1])== NULL)
						{
							typePoi = cPoiObj.getTypeFromstring(WpPoiData[0]);
							cPoiObj.setAllDataByReference(typePoi,WpPoiData[1],WpPoiData[2],atof(WpPoiData[3].c_str()),atof(WpPoiData[4].c_str()));
							cPoiObj.setType(POI);
							poiDb.addPoi(cPoiObj);
						}
						WpPoiData.clear();
						countLinePoi++;
						bResultPoi = true;
					}
					else
					{
						countLinePoi++;
						bResultPoi = false;
					}
				}
			}

			FileDatabase.close();
			poiDb.print();
		}
		break;
	}
	default:
	{
		break;
	}


	}
	/**
	 * Return true or false based on the error checks
	 */
	if(bResultWp&&bResultPoi)
	{
		return true;
	}
	else
	{
		return false;
	}

}
/**
 * Error checks and handling when data is read from csv file
 * for Waypoint
 */

bool CCSVStorage::csvFilecheckWp(string & line, int& linecount)
{
	bool bResult = false;
	int errCount = 0;
	string cell;
	int separatorCount = -1;
	size_t strposlatplus;
	size_t strposlongplus;
	size_t strposlatminus;
	size_t strposlongminus;
	vector<string> result;

	/** Error check for Waypoint csv file read
	 *
	 */

	stringstream lineStream(line);
	while(getline(lineStream,cell, ';'))
	{
		result.push_back(cell);
		separatorCount++;
		/**
		 * Check whether strings are entered
		 */
		if((cell.size() <= 1)||(cell.find("  ")<string::npos))
		{
			errCount++;
			cerr<<" Error : in file Wp.txt strings are not entered in line "<<linecount<< ":"<<line<<endl;
		}
		else
		{

		}
	}
	/**
	 * Check whether strings are separated with ; in a line
	 */
	if(separatorCount != 2)
	{
		errCount++;
		cerr<<" Error : In file Wp.txt separators are not proper in line "<<linecount<< ":"<<line<<endl;
	}
	/**
	 * Check whether texts are present in the appropriate fields
	 */
	else if((result[0].find_first_not_of("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzABCCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos ))
	{
		errCount++;
		cerr<<" Error : In file Wp.txt text is expected in the line "<<linecount<< ":"<<line<<endl;

	}
	/**
	 * Check whether numbers are present in the appropriate fields and decimal point is present
	 * in the numbers
	 */
	else if((result[1].find_first_not_of("0123456789.+-") != string::npos )||(result[2].find_first_not_of("0123456789.+-") != string::npos ))
	{
		errCount++;
		cerr<<" Error : In file Wp.txt number is expected in the line and decimal point is expected between digits in line "<<linecount<< ":"<<line<<endl;
	}
	else
	{
		strposlatplus = result[1].find_first_of("+");
		strposlongplus = result[2].find_first_of("+");
		strposlatminus = result[1].find_first_of("-");
		strposlongminus = result[2].find_first_of("-");
		if(((strposlatplus!=0)&&(strposlatplus!=string::npos))||((strposlatminus!=0)&&(strposlatminus!=string::npos))||
				((strposlongplus!=0)&&(strposlongplus!=string::npos))||((strposlongminus!=0)&&(strposlongminus!=string::npos)))
		{
			errCount++;
			cerr<<" Error : In file Wp.txt + / - sign found in a non relevant position in line "<<linecount<< ":"<<line<<endl;
		}
		if((result[1].find_first_of(".") != result[1].find_last_of("."))||(result[2].find_first_of(".") != result[2].find_last_of(".")))
		{
			cerr<<" Error : In file Wp.txt decimal points are found more than once in line "<<linecount<< ":"<<line<<endl;
		}

	}

	separatorCount = -1;
	result.clear();
	if(errCount == 0)
	{
		bResult = true;
	}
	else
	{
		bResult = false;
	}
	return bResult;
}

bool CCSVStorage::csvFilecheckPoi(string & line, int& linecount)
{
	bool bResult = false;
	int errCount = 0;
	string cell;
	int separatorCount = -1;
	size_t strposlatplus;
	size_t strposlongplus;
	size_t strposlatminus;
	size_t strposlongminus;
	vector<string> result;
	/** Error check for Poi csv file read
	 *
	 */
	stringstream lineStream(line);

	while((void*)0 != getline(lineStream,cell, ';'))
	{

		result.push_back(cell);
		separatorCount++;
		/**
		 * Check whether strings are entered
		 */
		if((cell.size() <= 1)||(cell.find("  ")<string::npos))
		{
			errCount++;
			cerr<<" Error : In file Poi.txt strings are not entered in line "<<linecount<< ":"<<line<<endl;
		}
		else
		{

		}
	}
	/**
	 * Check whether strings are separated with ; in a line
	 */
	if(separatorCount!= 4)
	{
		errCount++;
		cerr<<" Error : In file Poi.txt separators are not proper in line "<<linecount<< ":"<<line<<endl;
	}
	/**
	 * Check whether numbers are present in the appropriate fields and decimal point is present
	 * in the numbers
	 */
	else if((result[0].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos )||(result[1].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos)||(result[2].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos))
	{
		errCount++;
		cerr<<" Error :In file Poi.txt text is expected in the line "<<linecount<< ":"<<line<<endl;

	}
	/**
	 * Check whether numbers are present in the appropriate fields and decimal point is present
	 * in the numbers
	 */
	else if((result[3].find_first_not_of("0123456789.+-") != string::npos )||(result[4].find_first_not_of("0123456789.+-") != string::npos ))
	{
		errCount++;
		cerr<<" Error : In file Poi.txt number is expected in the line and decimal point is expected between digits in line "<<linecount<< ":"<<line<<endl;

	}
	else
	{
		strposlatplus = result[3].find_first_of("+");
		strposlongplus = result[4].find_first_of("+");
		strposlatminus = result[3].find_first_of("-");
		strposlongminus = result[4].find_first_of("-");
		if(((strposlatplus!=0)&&(strposlatplus!=string::npos))||((strposlatminus!=0)&&(strposlatminus!=string::npos))||
				((strposlongplus!=0)&&(strposlongplus!=string::npos))||((strposlongminus!=0)&&(strposlongminus!=string::npos)))
		{
			errCount++;
			cerr<<" Error : In file Poi.txt + / - sign found in a non relevant position in line "<<linecount<< ":"<<line<<endl;
		}
		if((result[3].find_first_of(".") != result[3].find_last_of("."))||(result[4].find_first_of(".") != result[4].find_last_of(".")))
		{
			cerr<<" Error : In file Poi.txt decimal points are found more than once in line "<<linecount<< ":"<<line<<endl;
		}
	}

	separatorCount = -1;
	result.clear();
	if(errCount == 0)
	{
		bResult = true;
	}
	else
	{
		bResult = false;
	}
	return bResult;	
}

/**
 * Destructor
 */

CCSVStorage::~CCSVStorage()
{

}
