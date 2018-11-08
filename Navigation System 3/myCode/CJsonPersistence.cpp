/*
 * CJsonPersistence.cpp
 *
 *  Created on: 6 Jan 2017
 *      Author: dayan
 */

#include "CJsonPersistence.h"

CJsonPersistence::CJsonPersistence()
{


}

void CJsonPersistence::setMediaName(string name)
{
	sMediaName = name;
}

CJsonPersistence::~CJsonPersistence()
{
	// TODO Auto-generated destructor stub
}

void CJsonPersistence::writeWaypointData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb)
{
	list<CWaypoint> cWpList;
	list<CPOI> cPoiList;
	list<CWaypoint>:: iterator ItrWp;
	CWaypoint cWpObj;
	string str;

	if(!(waypointDb.traverseWPDatabase(cWpList)))
	{
		if(!poiDb.traverseDatabase(cPoiList))
		{
			cout<<"Both Waypoint and POI databases are empty hence writing of waypoints to Json not possible" <<endl;
			JsonFileDatabase<<str<<endl;
		}
		else
		{

		}

	}
	else
	{
		str = "{";
		str = str + "\n";
		str = str + "  \"waypoints\"";
		str += " :";
		str += "  [";
		str += "\n";
		ItrWp = cWpList.begin();
		while(ItrWp!= cWpList.end())
		{
			cWpObj = *ItrWp;
			str += "    {";
			str += "\n";
			JsonFileDatabase << str << "      \"name\"" << " : " << "\"" << cWpObj.getName() << "\" " << "," << endl;
			JsonFileDatabase<<"      \"latitude\""<<" : "<<cWpObj.getLatitude()<<","<<endl;
			JsonFileDatabase<<"      \"longitude\""<<" : "<<cWpObj.getLongitude()<<endl;
			str = "    } ,";
			str += "\n";
			ItrWp++;

		}
		//		if((!poiDb.traversePOIDatabase(cPoiList)))
		//		{
		//			str = "    }";
		//			str += "\n";
		//			str += "  ]"	;
		//			str += "\n";
		//			str += "}";
		//			JsonFileDatabase<<str<<endl;
		//		}
	}
}

void CJsonPersistence::writePoiData(const CPoiDatabase& poiDb,const CWpDatabase& waypointDb)
{
	list<CWaypoint> cWpList;
	list<CPOI> cPoiList;
	list<CPOI>:: iterator ItrPoi;
	CPOI cPoiObj;
	string namePoi,descriptionPoi;
	double latitudePoi,longitudePoi;
	t_poi typePoi;
	string str;
	if(!poiDb.traversePOIDatabase(cPoiList))
	{
		if(!waypointDb.traverseWPDatabase(cWpList))
		{
			cout<<"Both Waypoint and POI databases are empty hence writing of waypoints to Json not possible" <<endl;
			JsonFileDatabase<<str<<endl;
		}
		else
		{
			str = "    }";
			str += "\n";
			str += "  ]";
			str += "\n";
			str += "}";
			JsonFileDatabase<<str<<endl;
		}

	}
	else
	{
		if(!waypointDb.traverseWPDatabase(cWpList))
		{
			cout<<"Waypoint database is empty hence writing of waypoints to Json not possible" <<endl;
			str = "{";
			str += "\n";
			str = str + "  \"pois\"";
			str += " :";
			str += "  [";
			str += "\n";
		}
		else
		{
			str = "    }";
			str += "\n";
			str += "  ] ,";
			str += "\n";
			str = str + "  \"pois\"";
			str += " :";
			str += "  [";
			str += "\n";
		}
		ItrPoi = cPoiList.begin();
		while(ItrPoi!= cPoiList.end())
		{
			cPoiObj = *ItrPoi;
			str += "    {";
			str += "\n";
			cPoiObj.getAllDataByReference(namePoi,latitudePoi,longitudePoi,typePoi,descriptionPoi);
			JsonFileDatabase<<str<<"      \"name\""<<" : "<<"\""<<namePoi<<"\" "<<","<<endl;
			JsonFileDatabase<<"      \"latitude\""<<" : "<<latitudePoi<<","<<endl;
			JsonFileDatabase<<"      \"longitude\""<<" : "<<longitudePoi<<","<<endl;
			JsonFileDatabase<<"      \"type\""<<" : "<< "\""<<cPoiObj.getStringFromPoiType(typePoi)<< "\" "<<","<<endl;
			JsonFileDatabase<<"      \"description\""<<" : "<< "\""<<descriptionPoi<<"\""<<endl;
			str = "    } ,";
			str += "\n";
			ItrPoi++;

			//JsonFileDatabase<<str;
		}
		str = "    }";
		str += "\n";
		str += "  ]"	;
		str += "\n";
		str += "}";
		JsonFileDatabase<<str<<endl;
	}
}

void CJsonPersistence::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb)
{
	//	list<CWaypoint> cWpList;
	//	list<CWaypoint>:: iterator ItrWp;
	//	list<CPOI> cPoiList;
	//	list<CPOI>:: iterator ItrPoi;
	//	CWaypoint cWpObj;
	//	CPOI cPoiObj;
	//	string namePoi,descriptionPoi;
	//	double latitudePoi,longitudePoi;
	//	t_poi typePoi;
	//	string str;
	//	str = "{";
	//	str = str + "\n";
	//	str = str + "  \"waypoints\"";
	//	str += ":";
	//	str += "  [";
	//	str += "\n";

	//cout<<str;
	string sFilename;
	sFilename = sMediaName + ".json";
	/** write data from waypoint database to the persistent
	 * storage file which is a .csv file stored in the hard
	 * disk
	 */


	JsonFileDatabase.open(sFilename.c_str(), fstream::out);
	if(!JsonFileDatabase.is_open())
	{
		cerr <<"JSON File not found"<<endl;
	}
	else
	{
		//		waypointDb.traverseWPDatabase(cWpList);
		//		ItrWp = cWpList.begin();
		//		while(ItrWp!= cWpList.end())
		//		{
		//			cWpObj = *ItrWp;
		//			str += "    {";
		//			str += "\n";
		//			JsonFileDatabase << str << "      \"name\"" << ": " << "\"" << cWpObj.getName() << "\"" << "," << endl;
		//			JsonFileDatabase<<"      \"latitude\""<<": "<<cWpObj.getLatitude()<<","<<endl;
		//			JsonFileDatabase<<"      \"longitude\""<<": "<<cWpObj.getLongitude()<<endl;
		//			str = "    },";
		//			str += "\n";
		//			ItrWp++;
		//
		//		}

		writeWaypointData(waypointDb,poiDb);
		//		str = "    }";
		//		str += "\n";
		//		str += "  ],";
		//		str += "\n";
		//		str = str + "  \"pois\"";
		//		str += ":";
		//		str += "  [";
		//		str += "\n";

		writePoiData(poiDb,waypointDb);
		//		poiDb.traversePOIDatabase(cPoiList);
		//		ItrPoi = cPoiList.begin();
		//		while(ItrPoi!= cPoiList.end())
		//		{
		//			cPoiObj = *ItrPoi;
		//			str += "    {";
		//			str += "\n";
		//			cPoiObj.getAllDataByReference(namePoi,latitudePoi,longitudePoi,typePoi,descriptionPoi);
		//			JsonFileDatabase<<str<<"      \"name\""<<": "<<"\""<<namePoi<<"\""<<","<<endl;
		//			JsonFileDatabase<<"      \"latitude\""<<": "<<latitudePoi<<","<<endl;
		//			JsonFileDatabase<<"      \"longitude\""<<": "<<longitudePoi<<","<<endl;
		//			JsonFileDatabase<<"      \"type\""<<": "<< "\""<<cPoiObj.getStringFromPoiType(typePoi)<< "\""<<","<<endl;
		//			JsonFileDatabase<<"      \"description\""<<": "<< "\""<<descriptionPoi<<"\""<<endl;
		//			str = "    },";
		//			str += "\n";
		//			ItrPoi++;
		//
		//		//JsonFileDatabase<<str;
		//	    }
		//		str = "    }";
		//		str += "\n";
		//		str += "  ]"	;
		//		str += "\n";
		//		str += "}";
		//		JsonFileDatabase<<str<<endl;
	}
	JsonFileDatabase.close();

}

void CJsonPersistence::readData(CPoiDatabase& poiDb,CWpDatabase& waypointDb)
{

	string sFilename,attributeName,wpName,poiName,poiType,poiDescription;
	double wpLatitude,wpLongitude;
	double poiLatitude,poiLongitude;
	string sTokenName,stringValue;
	bool endOfFile = false;
	int entryCounts = 0;
	int noEndObject = 0;
	int noEndArray = 0;
	int linenumber = 0;
	PersistentStates state = IDLE;
	PersistentStates previousState = IDLE;
	//CJsonStringToken* tokenValue;
	filebuf fb;
	CJsonToken* ptr;
	bool dataBaseType;
	CWaypoint cWpObj;
	CPOI cPoiObj;
	t_poi typePoi;
	//istream inputDataFileDatabase;
	sFilename = sMediaName + ".json";
	try{
		if (fb.open (sFilename.c_str(),std::ios::in))
		{
			std::istream File(&fb);
			//	    while (File)
			//	      std::cout << char(File.get());
			CJsonScanner CJScObj(File);
			do
			{

				ptr = CJScObj.nextToken();

				linenumber = CJScObj.scannedLine() ;

				if((ptr == NULL)&&(File.get() == EOF))
				{
					cout<<"End of file has reached "<<endl;
					endOfFile = true;
					break;
				}
				else if(ptr == NULL)
				{
					cerr<<"Unexpected character in the previously read token with the "<<linenumber<<" occurence of last token has occured "<<endl;
					throw E_INVALLID_CHARACTER;

				}

				CJsonToken::TokenType token = ptr->getType();
				sTokenName = ptr->str();
				//			cout<<sTokenName<<endl;
				//			cout<<token<<endl;
				switch(state)
				{
				case IDLE:
					if(token == CJsonToken::BEGIN_OBJECT)
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state = W_DBNAME;
						noEndObject++;
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Expecting an opening brace { with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_MISSING_BEGIN_OBJECT;
					}
					break;
				case W_DBNAME:
					if((token == CJsonToken::STRING)&&((dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "waypoints")    \
							||(dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "pois")))
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						attributeName = dynamic_cast<CJsonStringToken*>(ptr)->getValue();
						state = W_NAMESEP;
						if(attributeName == "waypoints")
						{
							dataBaseType = false;
						}
						else if(attributeName == "pois")
						{
							dataBaseType = true;
						}
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Unexpected Db name with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_DB_NAME;
					}
					break;
				case W_ATTRNAME:
					if((token == CJsonToken::STRING)&&((dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "name") \
							||(dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "latitude")						\
							||(dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "longitude")
							||(dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "type")
							||(dynamic_cast<CJsonStringToken*>(ptr)->getValue() == "description")))
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						attributeName = dynamic_cast<CJsonStringToken*>(ptr)->getValue();
						state = W_NAMESEP;
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Unexpected attribute name with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_ATTR_NAME;
					}
					break;
				case W_NAMESEP:
					if(token == CJsonToken::NAME_SEPARATOR)
					{
						linenumber = CJScObj.scannedLine() ;
						if((attributeName == "waypoints")||(attributeName == "pois"))
						{
							previousState = state;
							state = W_BEGARRAY;
						}
						else
						{
							previousState = state;
							state = W_VALUE;
						}
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Expecting a name separator with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_NAME_SEPARATOR;
					}
					break;
				case W_BEGARRAY:
					if(token == CJsonToken::BEGIN_ARRAY)
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state = W_DBOBJ_BEG;
						noEndArray++;
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Expecting a begin array with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_BEG_ARRAY;
					}
					break;
				case W_DBOBJ_BEG:
					if(token == CJsonToken::BEGIN_OBJECT)
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state = W_ATTRNAME;
						noEndObject++;
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Expecting an opening brace { with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_MISSING_BEGIN_OBJECT;
					}
					break;
				case W_VALUE:

					if(token == CJsonToken::STRING)
					{
						linenumber = CJScObj.scannedLine() ;
						if((attributeName == "name")&&(dataBaseType == false))
						{
							wpName = dynamic_cast<CJsonStringToken*>(ptr)->getValue();
							cout<<wpName<<endl;

						}else if((attributeName == "name")&&(dataBaseType == true))
						{
							poiName = dynamic_cast<CJsonStringToken*>(ptr)->getValue();
							cout<<poiName<<endl;
						}else if((attributeName == "type")&&(dataBaseType == true))
						{
							poiType = dynamic_cast<CJsonStringToken*>(ptr)->getValue();
							cout<<poiType<<endl;
						}else if((attributeName == "description")&&(dataBaseType == true))
						{
							poiDescription = dynamic_cast<CJsonStringToken*>(ptr)->getValue();
							cout<<poiDescription<<endl;
						}
					}
					else if(token == CJsonToken::NUMBER)
					{
						linenumber = CJScObj.scannedLine() ;
						if((attributeName == "latitude")&&(dataBaseType == false))
						{
							wpLatitude = dynamic_cast<CJsonNumberToken*>(ptr)->getValue();
							cout<<wpLatitude<<endl;
						}
						else if((attributeName == "longitude")&&(dataBaseType == false))
						{
							wpLongitude = dynamic_cast<CJsonNumberToken*>(ptr)->getValue();
							cout<<wpLongitude<<endl;

						}else if((attributeName == "latitude")&&(dataBaseType == true))
						{
							poiLatitude = dynamic_cast<CJsonNumberToken*>(ptr)->getValue();
							cout<<poiLatitude<<endl;
						}else if((attributeName == "longitude")&&(dataBaseType == true))
						{
							poiLongitude = dynamic_cast<CJsonNumberToken*>(ptr)->getValue();
							cout<<poiLongitude<<endl;
						}

					}else if(token == CJsonToken::BOOL)
					{
						linenumber = CJScObj.scannedLine() ;
						cout<<dynamic_cast<CJsonBoolToken*>(ptr)->getValue()<<endl;

					}else if(token == CJsonToken::JSON_NULL)
					{
						linenumber = CJScObj.scannedLine() ;
						cout<<"JSON_NULL"<<endl;
					}
					else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<< "Unexpected value type with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_VALUE;

					}
					entryCounts++;
					if(((dataBaseType == false)&&(entryCounts >= 3)))
					{
						entryCounts = 0;
						cWpObj.set(wpName,wpLatitude,wpLongitude);
						waypointDb.addWaypoint(cWpObj);
						waypointDb.print();
						previousState = state;
						state = W_DBOBJ_END;
					}else if(((dataBaseType == true)&&(entryCounts >= 5)))
					{
						entryCounts = 0;
						typePoi = cPoiObj.getTypeFromstring(poiType);
						cPoiObj.setAllDataByReference(typePoi,poiName,poiDescription,poiLatitude,poiLongitude);
						poiDb.addPoi(cPoiObj);
						poiDb.print();
						previousState = state;
						state = W_DBOBJ_END;
					}
					else
					{
						previousState = state;
						state = W_VALSEP;
					}
					break;
				case W_VALSEP:
					if(token == CJsonToken::VALUE_SEPARATOR)
					{
						linenumber = CJScObj.scannedLine() ;
						if(previousState == W_VALUE)
						{
							previousState = state;
							state        = W_ATTRNAME;
						}
						else if(previousState == W_DBOBJ_END)
						{
							previousState = state;
							state        = W_DBOBJ_BEG;
						}
						else if((previousState == S_ENDARRAY)&&(dataBaseType == false))
						{
							dataBaseType = true;
							previousState = state;
							state        = W_DBNAME;
						}
						else if((previousState == S_ENDARRAY)&&(dataBaseType == true))
						{
							dataBaseType = false;
							previousState = state;
							state        = W_DBNAME;
						}

					}else if(token == CJsonToken::END_ARRAY)
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state        = S_ENDARRAY;
						noEndArray--;
					}else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Unexpected character instead of , or ] with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_VALUE_SEP;
					}
					break;
				case W_DBOBJ_END:
					if((token == CJsonToken::END_OBJECT)&&(previousState== W_VALUE))
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state        = W_VALSEP;
						noEndObject--;
					}else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Unexpected character at the end of object with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_MISSING_END_OBJECT;
					}
					break;
				case S_ENDARRAY:
					if(token == CJsonToken::VALUE_SEPARATOR)
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state        = W_DBNAME;
					}
					else if(token == CJsonToken::END_OBJECT)
					{
						previousState = state;
						linenumber = CJScObj.scannedLine() ;
						state        = S_ENDOBJ;
						noEndObject--;

					}else
					{
						linenumber = CJScObj.scannedLine() ;
						cerr<<"Unexpected character after the end of array with the "<<linenumber<< " occurence of last token "<<endl;
						throw E_MISSING_END_ARRAY;
					}
					break;
				case S_ENDOBJ:

				break;
				}
			}while(File.get() != EOF);

			if(endOfFile&&((noEndObject != 0)||(noEndArray!=0)))
			{
				cerr<<"No end of object at the end of file "<<endl;
				throw E_MISSING_END_OBJECT;
			}

			fb.close();
		}
		else
		{
			cerr<<"File not found "<<endl;
			throw E_NO_FILE;
		}
	}
	catch(int& errCode)
	{
       cout<<"Error Occured "<<errCode<<endl;
	}

}

