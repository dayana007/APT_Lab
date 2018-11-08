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

	/** Constructor Function
	 *
	 */
	CGPSSensor();

	/** getCurrentposition is used to get the current position from user so that
	 * it is returned as an object of class CWaypoint which can be accessed by other objects
	 * to calculate the nearest POI's
	 * @return CWaypoint currPos : Returns the current position from GPS Sensor
	 */
	CWaypoint getCurrentposition();
};
/********************
 **  CLASS END
 *********************/
#endif /* CGPSSENSOR_H */
