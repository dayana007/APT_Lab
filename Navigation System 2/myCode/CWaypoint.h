/*
 * CWaypoint.h
 *
 *  Created on: 27 Oct 2016
 *      Author: dayan
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* All # defines should be defined in the header so that
 * it can be accessed by any file if the header is included
 */
#define PI 3.14
#define RADIANCONVERSION 180

/* SHOWADDRESS is defined to turn on
 * and off verbose mode when constructor
 * is invoked to printh the addresses
 */

#define SHOWADDRESS
#undef  SHOWADDRESS
#define DEGREE 1
#define MMSS 2
#define RADIUS 6378

enum wp_type{WAYPOINT,POI};

class CWaypoint
{
    private:

	     wp_type m_type;
         void transformLongitude2degmmss(int& deg,int& mm,double& ss);
         void transformLatitude2degmmss(int& deg,int& mm,double& ss);

    protected:
	     double m_latitude;
	     double m_longitude;
	     string m_name;



     public:
	      CWaypoint(string name = "DEFAULT",double latitude = 0, double longitude = 0, wp_type type = WAYPOINT);
	      void set (string name, double latitude, double longitude);
	      void setType(wp_type type);
	      string getName()const;
	      wp_type getType()const;
	      //virtual void print (int format);
	      void print (int format);
	      double getLatitude()const;
	      double getLongitude()const;
	      void  getAllDataByReference(string& name,double& latitude,double& longitude)const;
	      double calculateDistance(const CWaypoint& wp);
	      virtual ~CWaypoint();
	      friend ostream& operator <<(ostream& out, CWaypoint& origin);

};


#endif /* CWAYPOINT_H_ */
