#include <iostream>
#include "utils.h"
using namespace std;
using namespace sdds;

struct Person {
	char m_name[50 + 1];
	int m_age;
	void name(const char* name) {
		strCpy(m_name, name);
	}
	void age(int age) {
		m_age = age;
	}
	void display() {
		cout << "name: " << m_name << "  age: " << m_age << endl;
	}
};




int main() {
	Person P;
	char name[50 + 1];
	int age;

	cout << "enter the person's name: ";
	sdds::read(name, 50);
	cout << "enter the person age: ";
	cin >> age;
	P.name(name);
	P.age(age);
	P.display();

	return 0;
}