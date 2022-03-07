/* ------------------------------------------------------
OOP244 NAA
Workshop 4 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/10
-----------------------------------------------------------*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CarInventory.h"
using namespace std;

namespace sdds {
	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_model = nullptr;
		m_brand = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}
	void CarInventory::deAllocate() {
		delete[] m_type;
		m_type = nullptr;
		delete[] m_model;
		m_model = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
	}
	CarInventory::CarInventory() {
		resetInfo();
	}
	CarInventory::~CarInventory() {
		deAllocate();
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		m_type = m_model = m_brand = nullptr;
		setInfo(type, brand, model, year, code, price);
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		deAllocate();
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && (code < 1000 && code >= 100) && price > 0) {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
		return *this;
	}
	void CarInventory::printInfo() const {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.setf(ios::left);
		cout << "| " << setw(10) << m_type;
		cout << " | " << setw(16) << m_brand;
		cout << " | " << setw(16) << m_model;
		cout << " | ";
		cout.width(4);
		cout << m_year;
		cout << " |  ";
		cout.unsetf(ios::left);
		cout.width(3);
		cout << m_code;
		cout << " | ";
		cout.width(9);
		cout << m_price << " |" << endl;
	}
	bool CarInventory::isValid() const {
		bool success = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && (m_code < 1000 && m_code >= 100) && m_price > 0)
			success = true;
		return success;
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		//if (m_year == car.m_year && strcmp(m_type, car.m_type) == 0 && strcmp(m_model, car.m_model) == 0 && strcmp(m_brand, car.m_brand) == 0)
		bool success = false;
		if (m_year == car.m_year && m_code == car.m_code && m_price == car.m_price) {
			success = true;
		}
		return success;
	}
	bool find_similar(CarInventory car[], const int num_cars) {
		bool match = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					match = true;
				}
			}
		}
		return match;
	}
}
