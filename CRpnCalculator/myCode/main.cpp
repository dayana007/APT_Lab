// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
 #include <string>

using namespace std;	// Erspart den scope vor Objekte der
						// C++-Standard-Bibliothek zu schreiben
						// z.B. statt "std::cout" kann man "cout" schreiben

// Inkludieren Sie hier die Header-Files Ihrer Klassen, z.B.
#include "CRpnCalculator.h"


// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main (void)
{
    // TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "CRpnCalculator gestarted." << endl << endl;
	CLifoBuffer buff(5);
	CFraction f(3,1);
	CFraction g(2,1);
	CFraction e(5,2);
	CFraction i(10,1);
	CFraction j(1,1);
	buff.push(f);
	buff.push(g);
	buff.push(e);
	buff.push(i);
	buff.push(j);
	buff.print();
	buff.pop(j);
	buff.pop(i);
	buff.pop(e);
	buff.pop(g);
	buff.pop(f);
	buff.print();

	CRpnCalculator calc;
	CFraction num1(5,2);
	CFraction num2(6,5);
	calc.pushValue(num1);
	calc.pushValue(num2);
	calc.multiply();
	CFraction num3(1,2);
	calc.pushValue(num3);
	calc.add();
	CFraction num4(1,3);
	calc.pushValue(num4);
	CFraction result;
	result = calc.subtract();
	calc.popResult(result);
	calc.print();




	return 0;
}
