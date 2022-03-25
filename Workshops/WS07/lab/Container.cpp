/* ------------------------------------------------------
OOP244 NAA
Workshop 7 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 17
----------------------------------------------------------- */ 
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Container.h"
using namespace std;

namespace sdds {
	Container& Container::set(const char* content, int capacity, int contentVol) {
		strcpy(m_content, content);
		m_capacity = capacity;
		m_contentVol = contentVol;
		return *this;
	}
	void Container::setEmpty() {
		m_capacity = 0;
		m_contentVol = 0;
		m_content[0] = 0;
	}
	int Container::capacity()const {
		return m_capacity;
	}
	int Container::volume()const {
		return m_contentVol;
	}
	Container::Container(const char* content, int capacity, int contentVol) {
		if (content == nullptr && contentVol > capacity) {
			setEmpty();
		}
		else {
			set(content, capacity, contentVol);
		}
	}
	int Container::operator+=(int value) {
		int vol = m_capacity - m_contentVol;
		if (value < vol) {
			m_contentVol += value;
			return value;
		}
		else {
			m_contentVol += vol;
			return vol;
		}
	}
	int Container::operator-=(int value) {
		int amount;
		if (value <= m_contentVol) {
			m_contentVol -= value;
			amount = value;
		}
		else {
			amount = m_contentVol;
			m_contentVol = 0;
		}
		return amount;
	}
	Container::operator bool()const {
		bool state = true;
		if (m_content[0] == 0 || m_contentVol > m_capacity) {
			state = false;
		}
		return state;
	}
	Container& Container::clear(int capacity, const char* desc) {
		if (capacity > 0 && desc[0] != 0) {
			set(desc, capacity);
		}
		return *this;
	}
	ostream& Container::print(ostream& ostr) const {
		if (*this) {
			ostr << m_content << ':' << " (";
			ostr << m_contentVol << "cc" << '/';
			ostr << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}
	istream& Container::read(istream& istr) {
		int addVal, res;
		if (*this) {
			cout << "Add to ";
			print(cout) << endl;
			cout << "> ";
			addVal = getint(1, 22000);
			res = operator+=(addVal);
			cout << "Added " << res << " CCs" << endl;
		}
		else {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore();
			cin.ignore(1000, '\n');
			return istr;
		}
		return istr;
	}
	std::istream& operator>>(std::istream& istr, Container& RO) {
		return RO.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, const Container& RO) {
		return RO.print(ostr);
	}
	int getint(int min, int max) {
		int num;
		bool valid = false;
		while (!valid) {
			cin >> num;
			while (cin.fail()) { 
				cout << "Invalid Integer, retry: " << endl;
				cin.clear(); 
				cin.ignore(1000, '\n'); 
				cin >> num;
			}
			if (num < min || num > max) {
				cout << "Value out of range [" << min<< "<=val<=" << max << "]: ";
			}
			else {
				valid = true;
			}
		}
		return num;
	}
}