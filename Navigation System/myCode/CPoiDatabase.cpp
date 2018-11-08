/*
 * CPoiDatabase.cpp
 *
 *  Created on: 29 Oct 2016
 *      Author: dayan
 */

#include "CPoiDatabase.h"

/** Default constructor is called
*/

CPoiDatabase::CPoiDatabase()
{
	m_noPoi= 0;

}

/** This function adds a number of POI's to the database created
 * @param t_poi type : adds the member attribute m_type of object POI to the database
 * @param string name : adds the member attribute m_name of object POI to the database
 * @param string description : adds the member attribute m_description of object POI to the database
 * @param double latitude : adds the member attribute m_latitude of object POI to the database
 * @param double longitude : adds the member attribute m_longitude of object POI to the database
 * @return void
 */

void CPoiDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude)
{
    m_POI[m_noPoi] = CPOI(type,name,description,latitude,longitude);
   	if(m_noPoi < MAXNOPOI)
   	{
   		m_noPoi++;
   	}
   	else
   	{
       cout<<"The limit of database has reached "<<endl;
   	}
}

/** This function returns the address of the requested  POI from
 * the Database
 * @param string name : name of the POI that needs to be retreaved from database
 * @return Address the required POI
 */

CPOI* CPoiDatabase::getPointerToPoi(string name)
{
	int i;
	bool flag = 0;
	for(i=0;i<m_noPoi;i++)
	{
	   string namepassed;
	   namepassed = m_POI[i].getName();
	   if(!(strcmpi(namepassed.c_str(),name.c_str())))
	   {
		 flag = 1;
		 break;
	   }

	}
	if(flag == 0)
	{
		return NULL;

	}
	else
	{
		return &m_POI[i];
	}

}





