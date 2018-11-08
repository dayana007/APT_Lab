/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOIDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H

#include<iostream>
#include <string.h>
#include <map>
#include<list>
#include "CPOI.h"
using namespace std;


class CPoiDatabase {
   private:
    /**
     * @link aggregationByValue
     * @supplierCardinality 1..*
     * @clientCardinality 1*/

	map<string,CPOI> m_POIDatabase;

  public:
    CPoiDatabase();
    void addPoi(const CPOI & poi);
    CPOI* getPointerToPoi(string name);
    void print();
	void traversePOIDatabase( list<CPOI>& refToListOfCPoi ) const;
	bool clearPoiDatabase();
    ~CPoiDatabase();

};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
