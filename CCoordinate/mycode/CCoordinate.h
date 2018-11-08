/*
 * CCoordinate.h
 *
 *  Created on: 23 Oct 2016
 *      Author: dayan
 */

#ifndef CCOORDINATE_H_
#define CCOORDINATE_H_


#include <cmath>
#define PI 22/7

enum t_coordinate {CARTESIAN,CYLINDER,POLAR};

class CCoordinate
{
	private:
		float m_x;
		float m_y;
		float m_z;

	public:
		~CCoordinate();
		 CCoordinate();
		 CCoordinate(float x);
		 CCoordinate(float x, float y, float z);
		 /* Have to pass arguments by reference because pass by value
		  * will act on the local copy of the variable in the calle function
		  * which looses its existence outside the function
		  */
		 void getCartesian(float& x, float& y, float& z);
         /* Parameters passed to this function should be passed by reference
          * as constants are passed which cannot be referred*
          */
		 void setCartesian(float x, float y, float z);

		 /*Add operator
		  * it is different from set operator
		  * in a way that set operator can be passed by value whereas
		  * add operation can only be passed by referance as it involves
		  * objects
		  */

		 void add(const CCoordinate& c);

         /* Get cylindrical coordinates
          * r = root(x*x + y*y)
          * phi = { arctan y/x , if x>0;
          *         arctan y/x + 3.14, if x<0,y>=0
          *         arctan y/x - 3.14 , if x<0, y<0
          *         + 3.14/2  x = 0,y>0
          *         + 3.14/2  x = 0,y<0
          * h = z
         */

		 void getCylinder(float& r, float& phi, float& h);

         /* Get polar coordinates
          * r = root(x*x + y*y + z*z)
          * phi = arctan2 y/x
          * theeta = PI /2 - arctan (z/root(x*x + y*y))
         */
		 void getPolar(float& r, float& phi, float& theta);

		 /* Print Polar and cylindrical coordinates*/

		void print(t_coordinate style);



};





#endif /* CCOORDINATE_H_ */
