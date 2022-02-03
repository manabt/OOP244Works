#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;

namespace sdds {

	void Train::setSafeEmpty() {
		m_trainName[0] = 0;
		m_numPeople = -1;
		m_speed = -1;
	}

	void Train::set(const char* name, int num, double speed) {
		if (name != nullptr && strlen(name) > 0 && (num > 0 && num <= MAX_PEOPLE) && (speed > 0 && speed <= MAX_SPEED))
		{
			strncpy(m_trainName, name, MAX_NAME_LENGTH);
			m_numPeople = num;
			m_speed = speed;
		}
		else
		{
			//However, you must document your definition as comments. Otherwise you will lose marks.
			setSafeEmpty();
		}
	}

	int Train::getNumberOfPeople() const {
		return m_numPeople;
	}

	const char* Train::getName() const {
		return m_trainName;
	}

	double Train::getSpeed() const {
		return m_speed;
	}

	bool Train::isSafeEmpty() const {
		bool valid = false;
		if (strlen(m_trainName) == 0 || m_numPeople < 0 || m_speed < 0)
		{
	
			valid = true;
		}
		return valid;
	}

	void Train::display() const {
		if (!isSafeEmpty())
		{
			cout << "NAME OF THE TRAIN : " << m_trainName << endl;
			cout << "NUMBER OF PEOPLE  : " << m_numPeople << endl;
			cout << "SPEED             : " << m_speed << endl;
		}
		else
		{
			cout << "Safe Empty State!" << endl;
		}
	}
}