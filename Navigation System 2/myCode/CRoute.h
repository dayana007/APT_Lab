/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CROUTE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CROUTE_H
#define CROUTE_H

#include <iostream>
#include <string>
#include <list>
#include <limits>
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"

using namespace std;

#define MAXNOWP 4
#define NOPOI -9999

class CRoute {
    private:
      /**
       * @link aggregation 
       * @clientCardinality 1
       * @supplierCardinality 1..*
       */
      //CWaypoint* m_pCWaypoint;
//      unsigned int m_maxWp;
//      unsigned int m_nextWp;
//      CPOI** m_pPoi;
//      unsigned int m_maxPoi;
//      unsigned int m_nextPoi;
      /**
       * @clientCardinality 0..*
       * @supplierCardinality 1 
       */
	  list<CWaypoint*> listRoute;
	  CWpDatabase* m_pWpDatabase;
      CPoiDatabase* m_pPoiDatabase;
    public:
        CRoute();
        CRoute(const CRoute& origin);
        ~ CRoute();
        void connectToPoiDatabase(CPoiDatabase* pPoiDB = NULL);
        void connectToWpDatabase(CWpDatabase* pWpDB = NULL);
        void addPoi(string namePoi,string afterWp);
        void addWaypoint(string name);
        double getDistanceNextPoi(const CWaypoint& Wp, CPOI& poi);
        void print();
        void operator +=(string name);
        CRoute& operator =(const CRoute& origin);
        CRoute& operator +(CRoute& origin);
};
/********************
**  CLASS END
*********************/
#endif /* CROUTE_H */
