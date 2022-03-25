/* ------------------------------------------------------
OOP244 NAA
Workshop 7 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 17
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Pack.h"
using namespace std;

namespace sdds {
	Pack::Pack(const char* content, int maxSize, int unitSize, int numUnits): Container(content, (maxSize* unitSize), (numUnits * unitSize)) {
		if (unitSize > 0)
			m_unitSize = unitSize;
		else
			setEmpty();
	}
	int Pack::operator+=(const int val) {
		return Container::operator+=(val * m_unitSize) / m_unitSize;
	}
	int Pack::operator-=(const int val) {
		return Container::operator-=(val * m_unitSize) / m_unitSize;
	}
	int Pack::unit()const {
		return m_unitSize;
	}
	int Pack::noOfUnits()const {
		return volume() / m_unitSize;
	}
	int Pack::size()const {
		return capacity() / m_unitSize;
	}
	void Pack::clear(int size, int unitSize, const char* content) {
		if (unitSize > 0) {
			m_unitSize = unitSize;
			Container::clear((size * unitSize), content);
		}
	}
	std::ostream& Pack::print(std::ostream& ostr)const {
		if (*this) {
			Container::print(ostr);
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}
	std::istream& Pack::read(std::istream& istr) {
		if (*this) {
			if (noOfUnits() < size()) {
				cout << "Add to ";
				print(cout) << endl;
				cout << "> ";
				int max = size() - noOfUnits();
				int addVal = getint(1, max);
				int res = operator+=(addVal);
				cout << "Added " << res << endl;
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue..." << endl;
			}
		}
		else {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore();
			cin.ignore(1000, '\n');
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Pack& RO) {
		return RO.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Pack& RO){
		return RO.read(istr);
	}
}