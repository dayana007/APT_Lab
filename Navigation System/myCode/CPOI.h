/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOI.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CPOI_H
#define CPOI_H

#include <iostream>
#include <string>
#include "CWaypoint.h"
using namespace std;

/* enum is defined to store the types of POI's available*/

enum t_poi { POI,RESTAURANT,SIGHTSEEING,AIRPORT,UNIVERSITY};

/* CPOI is a derived class of the base class CWaypoint*/

class CPOI : public CWaypoint
	{
    private:
        /**
         * @link aggregationByValue
         * @supplierCardinality 1
         * @clientCardinality 1 
         */
        t_poi m_type;
        string m_description;
    public:
        void print();
        CPOI(t_poi type = POI , string name = "name",string description = "Description",double latitude = 0 ,double longitude = 0);
        void getAllDataByReference(string& name,double& latitude,double& longitude,t_poi& type,string& description);
};
/********************
**  CLASS END
*********************/
#endif /* CPOI_H */
