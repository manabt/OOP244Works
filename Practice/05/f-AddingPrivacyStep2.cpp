#include <iostream>
#include "utils.h"
using namespace std;
using namespace sdds;

class Person {
	char m_name[50 + 1];
	int m_age;
	void setSafeEmpty();
public:
	void set(const char* name);
	void set(int age);
	bool isSafeEmpty()const;
	bool isValid()const;
	void display()const;
	
};




int main() {
	Person P;
	char name[50 + 1];
	int age;

	cout << "enter the person's name: ";
	sdds::read(name, 50);
	cout << "enter the person age: ";
	cin >> age;
	P.set(name);
	P.set(age);
	P.display();

	return 0;
}


void Person::setSafeEmpty() {
	m_age = -1;
	m_name[0] = 0;
}
void Person::set(const char* name) {
	if (name == nullptr || name[0] == 0 || name[1] == 0 || strLen(name) > 50)
	{
		setSafeEmpty();
	}
	else
	{
		strCpy(m_name, name);
	}
}
void Person::set(int age) {
	if (age < 0 || age > 120)
	{
		setSafeEmpty();
	}
	else
	{
		m_age = age;
	}
}
//Queries:
bool Person::isSafeEmpty()const {
	return m_age < 0 || m_name[0] == 0;
}
bool Person::isValid()const {
	return !isSafeEmpty();
}
void Person::display()const {
	if (isValid())
	{
		cout << "name: " << m_name << "  age: " << m_age << endl;
	}
	else
	{
		cout << "Invalid Person!" << endl;
	}		
}