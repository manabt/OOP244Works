#include <iostream>
#include "Utils.h"
using namespace std;
using namespace sdds;

class Container {
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
	/*Container& average(const Container& R)const {
		Container theAverage((this->m_value + R.m_value) / 2);
		return theAverage;
	}*/
	bool isEmpty()const {
		return m_value <= 0;
	}
};
Container& average(const Container& left, const Container& right) {
	Container theAve((left.get() + right.get()) / 2);
	return theAve;
}

void isConatinerEmpty(const Container& R) {
	if (R.isEmpty())
	{
		cout << "The Container is empty" << endl;
	}
	else {
		cout << "The Container is not empty" << endl;
	}
}
void displayAll(const char* prompt, const Container& C, const Container& D, const Container& E) {
	cout << prompt << endl;
	cout << "C: ";
	C.display();
	cout << " D: ";
	D.display();
	cout << " E: ";
	E.display() << endl;
}

int main() {
	Container A;
	Container B(200);
	Container C(300);
	displayAll("Before Sum: ", A, B, C);
	A = B.sum(C);
	displayAll("After Sum: ", A, B, C);
	A = B.add(C);
	displayAll("After Add: ", A, B, C);
	A = average(B, C);
	displayAll("After Average: ", A, B, C);
	return 0;
}