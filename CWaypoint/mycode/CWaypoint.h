/*
 * CWaypoint.h
 *
 *  Created on: 27 Oct 2016
 *      Author: dayan
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_


#include <string>
#include <cmath>

using namespace std;

/* All # defines should be defined in the header so that
 * it can be accessed by any file if the header is included
 */
#define PI 3.14
#define RADIANCONVERSION 180
#define SHOWADDRESS 1
#define DEGREE 1
#define MMSS 2
#define RADIUS 6378



class CWaypoint
{

    protected:
	     double m_latitude;
	     double m_longitude;
	     string m_name;

     public:
	      //CWaypoint();
	      CWaypoint(double latitude = 0, double longitude = 0,string name = "DEFAULT");
	      //CWaypoint(string name, double latitude, double longitude);
	      void set (string name, double latitude, double longitude);
	      void transformLongitude2degmmss(int& deg,int& mm,double& ss);
	      void transformLatitude2degmmss(int& deg,int& mm,double& ss);
	      void print (int format);
	      string getName();
	      double getLatitude();
	      double getLongitude();
	      void  getAllDataByReference(string& name,double& latitude,double& longitude);
	      double calculateDistance(const CWaypoint& wp);
	      virtual ~CWaypoint();

};


#endif /* CWAYPOINT_H_ */
