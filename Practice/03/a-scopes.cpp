#include <iostream>
#include "student.h"

using namespace std;

using namespace sdds;

int fileScopevar = 4; // file scope variable

int main() {

	Student s = { "Mana", 234566, 2000 };
	int i = 0; // function scope
	
	if (2 < 6) {
		int j = 6; // block scope
	}

	s.display();
	cout << "Calculated using the interest rate of : " << intrestRate << endl;

	return 0;
}