/* ------------------------------------------------------
OOP244 NAA
Workshop 4 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/13
-----------------------------------------------------------*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Robot.h"

using namespace std;

namespace sdds {

	void Robot::setSafeEmpty() {
		m_name = nullptr;
		m_location = nullptr;
		m_weight = 0;
		m_width = 0;
		m_height = 0;
		m_speed = 0;
		m_deployed = -1;
	}
	void Robot::deAllocate() {
		delete[] m_name;
		m_name = nullptr;
		delete[] m_location;
		m_location = nullptr;
	}
	Robot::Robot() {
		setSafeEmpty();
	}
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment) {
		m_name = nullptr, m_location = nullptr;
		set(name, location, weight, width, height, speed, deployment);
	}
	// Destructor
	Robot::~Robot() {
		//summary(robot, num_Robot);
		deAllocate();
	}
	// Modifiers member functions
	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment) {
		deAllocate();
		if (name != nullptr && location != nullptr)
		{
			setLocation(location);
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_weight = weight;
			m_width = width;
			m_height = height;
			m_speed = speed;
			setDeployed(deployment);
		}
		else
		{
			setSafeEmpty();
		}
		return *this;
	}
	Robot& Robot::setLocation(const char* location) {
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
		return *this;
	}
	bool Robot::setDeployed(bool status) {
		m_deployed = status;
		return m_deployed;
	}
	// Queries member functions
	const char* Robot::getname()const {

		return m_name;
	}
	const char* Robot::getLocation()const {
		return m_location;
	}
	bool Robot::isDeployed()const {
		return m_deployed;
	}
	bool Robot::isValid()const {
		bool valid = false;
		if (getname() != nullptr && getLocation() != nullptr && m_weight > 0 && m_width > 0 && m_height > 0 && speed() > 0 && (isDeployed() == true || isDeployed() == false))
		{
			valid = true;
		}
		return valid;
	}
	double Robot::speed()const {
		return m_speed;
	}
	std::ostream& Robot::display(const char* message)const {
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.setf(ios::left);
		cout << "| " << setw(10) << m_name;
		cout << " | " << setw(15) << m_location << " | ";
		cout.unsetf(ios::left);
		cout.width(6);
		cout << m_weight << " |  ";
		cout.width(5);
		cout << m_width << " |  ";
		cout.width(5);
		cout << m_height << " |  ";
		cout.width(5);
		cout << m_speed << " | ";
		cout.setf(ios::left);
		cout << setw(8) << (m_deployed == 0 ? "NO" : "YES") << " |" << endl;;

		return cout;
	}

	int conrtolRooomReport(const Robot robot[], int num_Robot) {
		bool keepLooping = 1;
		int index = -1;
		displayTableHeader();
		for (int i = 0; i < num_Robot && keepLooping; i++)
		{
			if (robot[i].isValid()) {
				robot[i].display();
				//index = -1;

			}
			else
			{
				index = i;
				keepLooping = 0;
			}
		}
		if (index == -1)
		{
			summary(robot, num_Robot);
			return -1;
		}
		return index;
		
	}

	void summary(const Robot robot[], int num_Robot) {
		int count = 0;
		int fastestIndex = 0;
		cout << "|=============================================================================|" << endl;
		cout << "| SUMMARY:                                                                    |" << endl;
		for (int i = 0; i < num_Robot; i++)
		{
			if (robot[i].isDeployed() == 0)
			{
				count++;
			}
			for (int j = i + 1; j < num_Robot; j++) {
				if (robot[i].speed() > robot[j].speed())
					fastestIndex = i;
			}
		}
		cout << "| " << count << "  robots are deployed.                                                     |" << endl;
		cout << "| The fastest robot is:                                                       |" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		robot[fastestIndex].display();
		cout << "|=============================================================================|" << endl;
	}

	void displayTableHeader() {

		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
	}
}