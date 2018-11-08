//============================================================================
// Name        : CFraction.cpp
// Author      : dayana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CFraction.h"
using namespace std;

int main()
{

//   CFraction f(1,0);
//   f.print();
//   CFraction g(12,15);
//   g.print();
//  cout<< g.todouble()<<endl;
  CFraction f1;
  CFraction f2(1,3);
  CFraction f3(24, 3);
  f1.print();
  cout<< f2.todouble()<<endl;
  f3.print();
  CFraction sum;

  sum = CFraction(3, 4) + CFraction (2, 3);
  cout << "(3/4)+(2/3) = " << sum << endl;
  CFraction f(1, 3);
  CFraction g;
  g = ++f;
  cout << "++f == " << f << "; (g=++f) == " << g << endl;
  f.set(1,3);
  g = f++;
  cout << "f++ == " << f << "; (g=f++) == " << g << endl;
	return 0;
}
