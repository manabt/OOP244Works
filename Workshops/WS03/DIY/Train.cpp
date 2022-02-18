/* ------------------------------------------------------
OOP244 NAA
Workshop 3 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/05
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;

namespace sdds {
	Train* trainDyn;
	void Train::setSafeEmpty() {
		m_trainName[0] = 0; // setting the name of the train to no name
		m_numPeople = -1; // -1 number of people is not valid so can be used to set a safe empty state
		m_speed = -1.00; // -1.00 is not a valid speed for number
	}
	void Train::set(const char* name, int num, double speed) {
		if (name != nullptr && strlen(name) > 0 && (num > 0 && num <= MAX_PEOPLE) && (speed > 0 && speed <= MAX_SPEED)) {
			strncpy(m_trainName, name, MAX_NAME_LENGTH);
			m_numPeople = num;
			m_speed = speed;
		}
		else {
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
		if (strlen(m_trainName) == 0 || m_numPeople < 0 || m_speed < 0) {
			valid = true;
		}
		return valid;
	}
	void Train::display() const {
		if (!isSafeEmpty()) {
			cout << "NAME OF THE TRAIN : " << m_trainName << endl;
			cout << "NUMBER OF PEOPLE  : " << m_numPeople << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "SPEED             : " << m_speed << " km/h" << endl;
		}
	}
	bool Train::loadPeople(int num) {
		bool success = false;
		if (!isSafeEmpty()) {
			m_numPeople += num;
			if (m_numPeople < 0) {
				m_numPeople = 0;
			}
			else if (m_numPeople > MAX_PEOPLE) {
				m_numPeople = MAX_PEOPLE;
			}
			success = true;
		}
		return success;
	}
	bool Train::changeSpeed(double num) {
		bool success = false;
		if (!isSafeEmpty()) {
			m_speed += num;
			if (m_speed < 0){
				m_speed = 0;
			}
			else if (m_speed > MAX_SPEED) {
				m_speed = MAX_SPEED;
			}
			success = true;
		}
		return success;
	}
	int transfer(Train& first, Train& second) {
		int count = 0, temp1;
		temp1 = first.getNumberOfPeople();
		count = MAX_PEOPLE - temp1;
		if (first.isSafeEmpty() || second.isSafeEmpty()) {
			count = - 1;
		}
		else if (temp1 < MAX_PEOPLE && temp1 > -1)
		{
			first.loadPeople(count);
			second.loadPeople(-count);
		}
		return count;
	}
}