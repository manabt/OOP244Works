#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {

	struct Student  // example of putting data & behavior together (encapsulation)
	{
		char name[51]; // attributes or members of the class
		int stNo;
		double balance;
		void display(); // behavior or method of the class // class scope ( all the attributes or members of Student class are accessible to display();
	};

	extern const double intrestRate; // global varaible
}


#endif // !SDDS_STUDENT_H
