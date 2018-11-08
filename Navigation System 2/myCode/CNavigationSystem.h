/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CNAVIGATIONSYSTEM.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CNAVIGATIONSYSTEM_H
#define CNAVIGATIONSYSTEM_H

#include <iostream>
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CPersistentStorage.h"
using namespace std;

class CNavigationSystem
{
    private:
        /**
         * @link aggregationByValue 
         * @clientCardinality 1
         * @supplierCardinality 1
         */
        CGPSSensor m_GPSSensor;
        /**
         * @link aggregationByValue 
         * @clientCardinality 1
         * @supplierCardinality 1*/
        CRoute m_route;
        /**
         * @link aggregationByValue 
         * @clientCardinality 1
         * @supplierCardinality 1
         */
        CPoiDatabase m_PoiDatabase;
        CWpDatabase m_WpDatabase;
        CStorage m_CPerObj;
        void enterRoute();
        void printRoute();
        void printDistanceCurPosNextPoi();
    public:
        CNavigationSystem();
        void run();
        bool readFromPersistentStorage(CStorage::MergeMode mode);
        bool writeToPersistentStorage();
        void setMedia(string name);


};
/********************
**  CLASS END
*********************/
#endif /* CNAVIGATIONSYSTEM_H */
