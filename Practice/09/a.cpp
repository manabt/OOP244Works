#include <iostream>
#include "Utils.h"
using namespace std;
using namespace sdds;

class Container{
	int m_value;
public:
	//constructer
	Container(int value = 0) {
		set(value);
	}
	//modifier
	Container& set(int value) {
		m_value = value;
		return *this;
	}
	//query
	int get()const {
		return m_value;
	}
	ostream& display(ostream& ostr = cout)const {
		ostr << "Container:[";
		ostr.width(9);
		ostr.fill('0');
		ostr.setf(ios::right);
		ostr << get();
		ostr.fill(' ');
		ostr.unsetf(ios::right);
		ostr << "]";
		return ostr;
	}
	istream& read(istream& istr = cin) {
		m_value = getint("Container value: ", istr);
		return istr;
	}
	Container& add(int value) {
		m_value += value;
		return *this;
	}
	Container& add(const Container& R) {
		this->m_value += R.m_value;
		return *this;
	}
	Container& sum(const Container& R)const {
		Container theSum(this->m_value + R.m_value);
		return theSum;
	}
	bool isEmpty()const {
		return m_value <= 0;
	}
};
void isConatinerEmpty(const Container& R) {
	if (R.isEmpty())
	{
		cout << "The Container is empty" << endl;
	}
	else {
		cout << "The Container is not empty" << endl;
	}
}

int main() {
	Container A;
	Container B(200);
	isConatinerEmpty(A);
	isConatinerEmpty(B);
	A.read();
	cout << "You Entered: ";
	A.display() << endl;
	B.add(A).display() << endl;
	return 0;
}