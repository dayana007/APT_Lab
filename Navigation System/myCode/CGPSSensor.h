/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGPSSENSOR.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CGPSSENSOR_H
#define CGPSSENSOR_H

#include<iostream>
#include "CWaypoint.h"
using namespace std;

class CGPSSensor
{
 public:
    CGPSSensor();
    CWaypoint getCurrentposition();
};
/********************
**  CLASS END
*********************/
#endif /* CGPSSENSOR_H */
