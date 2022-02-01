#include <iostream>
using namespace std;

struct Employee{
	int id;
	double salary;
	int shifts[7];
	char image[5000];
};

int main() {
	
	Employee* ptr;
	ptr = new Employee;

	if (ptr != nullptr)
	{
		// do stuff

		delete ptr; // will delete ptr if only it is not nullptr
	}
	else
	{
		cout << "out of memory!!" << endl;
	}

	return 0;
}