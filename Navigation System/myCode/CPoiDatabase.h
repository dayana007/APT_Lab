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
#include "CPOI.h"
using namespace std;

#define MAXNOPOI 10


class CPoiDatabase {
   private:
    /**
     * @link aggregationByValue
     * @supplierCardinality 1..*
     * @clientCardinality 1*/
    CPOI m_POI[10];
    int m_noPoi;
  public:
    CPoiDatabase();
    void addPoi(t_poi type, string name, string description,double latitude, double longitude);
    CPOI* getPointerToPoi(string name);

};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
