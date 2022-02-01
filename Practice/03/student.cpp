#include <iostream>
#include "student.h"

using namespace std;

namespace sdds {

	const double intrestRate = 0.2; // made this variable global by adding the extern keyword at the beggining of it in its headerr file

	void Student::display() {
		cout << name << ",ID: " << stNo << endl;
		cout<< " Balance: " << balance
			<< " with the intrest rate of: " << balance * intrestRate << endl;
	};
}


