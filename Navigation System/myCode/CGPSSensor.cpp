/*
 * CGPSSensor.cpp
 *
 *  Created on: 29 Oct 2016
 *      Author: dayan
 */


#include "CGPSSensor.h"

/** Constructor Function
 *
 */
CGPSSensor::CGPSSensor()
{

}

/** getCurrentposition is used to get the current position from user so that
 * it is returned as an object of class CWaypoint which can be accessed by other objects
 * to calculate the nearest POI's
 * @return CWaypoint currPos : Returns the current position from GPS Sensor
 */
CWaypoint CGPSSensor::getCurrentposition()
{
  double latitude,longitude;
  string name;
  cout<<"GPS Sensor"<<endl;
  cout<<"   Enter latitude : ";
  cin>>latitude;
  cout<<"   Enter longitude : ";
  cin>>longitude;
  CWaypoint currPos;
  currPos.set(name,latitude,longitude);
  return currPos;
}





