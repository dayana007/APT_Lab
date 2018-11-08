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
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
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
      CWaypoint* m_pCWaypoint;
      unsigned int m_maxWp;
      unsigned int m_nextWp;
      CPOI** m_pPoi;
      unsigned int m_maxPoi;
      unsigned int m_nextPoi;
      /**
       * @clientCardinality 0..*
       * @supplierCardinality 1 
       */
      CPoiDatabase* m_pPoiDatabase;
    public:
        CRoute(unsigned int m_maxWp = MAXNOWP,unsigned int m_maxPoi = MAXNOPOI);
        CRoute(const CRoute& origin);
        ~ CRoute();
        void connectToPoiDatabase(CPoiDatabase* pPoiDB = NULL);
        void addPoi(string namePoi);
        double getDistanceNextPoi(const CWaypoint& Wp, CPOI& poi);
        void print();
        void addWaypoint(const CWaypoint& Wp);
};
/********************
**  CLASS END
*********************/
#endif /* CROUTE_H */
