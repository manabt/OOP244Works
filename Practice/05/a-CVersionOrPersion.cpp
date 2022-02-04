#include <iostream>
#include "utils.h"
using namespace std;
using namespace sdds;

struct Person {
	char name[50 + 1];
	int age;
};

void setPersonName(Person* person, const char* name) {
	strCpy(person->name, name);
}

void setPersonAge(Person* person, int age) {
	person->age = age;
}

void displayPerson(Person* person) {
	cout << "name: " << person->name << "  age: " << person->age << endl;
}


int main() {
	Person P;
	char name[50 + 1];
	int age;

	cout << "enter the person's name: ";
	sdds::read(name, 50);
	cout << "enter the person age: ";
	cin >> age;
	setPersonName(&P, name);
	setPersonAge(&P, age);
	displayPerson(&P);

	return 0;
}