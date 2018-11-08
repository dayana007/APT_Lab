//============================================================================
// Name        : CComplex.cpp
// Author      : dayana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CComplex.h"



int main()
{
  CComplex c1;
//  c1.print();
  CComplex c2(1,3);
  c2.print();
  CComplex c3(5,7);
//  c3.print();
//  CComplex c4(c3);
//  c4.print();
  (c2++).print();
  (++c2).print();
  c2 =c2+c3;
  c2.print();
  c2 =c2 + CComplex(7.0);
  c2.print();
  c2 = CComplex(5.0)+c2;
  c2.print();
  c2 = CComplex(5.0)-c2;
  c2.print();
  c2 =c2-c3;
  c2.print();
  c2 =c2 - CComplex(7.0);
  c2.print();
  c2 = c2 * c3;
  c2.print();
  c2 = c2 / c3;
  c2.print();
  cout<< "c2 : "<< c2 <<endl;
  float x = 3.14;
  c1 = c3+x;
  cout << "c1: " << c1 << endl;
  CComplex c;

  CComplex d;
  d = ++c;
  cout << "++c = " << c << "; d=++c = " << d << endl;
  d.set(0,0);
  d = c++;
  cout << "c++ = " << c << "; d=c++ = " << d << endl;


}
