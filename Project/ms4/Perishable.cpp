/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 4
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/04/07
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Perishable.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Perishable::Perishable(const Perishable& source): Item(source) {
		operator=(source);
	}
	Perishable& Perishable::operator=(const Perishable& source){
		delete[] m_handling;
		m_handling = nullptr;
		if (this != &source) {
			ut.alocpy(m_handling, source.m_handling);
			m_expiry = source.m_expiry;
			Item::operator=(source);
		}
		return *this;
	}
	Perishable::~Perishable() {
		delete[] m_handling;
		m_handling = nullptr;
	}
	const Date& Perishable::expiry() const {
		return m_expiry;
	}
	int Perishable::readSku(std::istream& istr) {
		cout << "SKU: ";
		m_sku = ut.getint(10000, 39999);
		return m_sku;
	}
	std::ofstream& Perishable::save(std::ofstream& ofstr) const {
		if (this->m_state) {
			Date temp = m_expiry;
			temp.formatted(false);
			Item::save(ofstr);
			ofstr << '\t';
			if (m_handling) {
				ofstr << m_handling;
			}
			ofstr << '\t';
			ofstr << temp;
		}
		return ofstr;
	}
	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		string str;
		Item::load(ifstr);
		//ifstr.ignore(1000, '\t');
		getline(ifstr, str, '\t');
		delete[] m_handling;
		m_handling = nullptr;
		if (ifstr && !str.empty()) ut.alocpy(m_handling, str.c_str());
		ifstr >> m_expiry;
		ifstr.ignore(1000, '\n');
		if (ifstr.fail()) {
			m_state.set("Input file stream read failed!");
		}
		return ifstr;
	}
	std::ostream& Perishable::display(std::ostream& ostr) const {
		ostr.fill(' ');
		if (m_state) {
			if (Item::linear()) {
				Item::display(ostr);
				if (m_handling && m_handling[0] != '\0') { //not null and not empty 
					ostr << '*';
				}
				else {
					ostr << ' ';
				}
				ostr << m_expiry;
			}
			else {
				Date temp = m_expiry;
				temp.formatted(true);
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << endl;
				ostr << "Expiry date: " << temp << endl; // print expiray formatted
				if (m_handling) {
					ostr << "Handling Instructions: " << m_handling << endl;
				}
			}
		}
		else {
			ostr << m_state;
		}
		return ostr;
	}
	std::istream& Perishable::read(std::istream& istr) {
		string str;
		Item::read(istr);
		delete[] m_handling;
		m_handling = nullptr;
		cout << "Expiry date (YYMMDD): ";
		istr >> m_expiry;
		istr.ignore(1000, '\n');
		cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() == '\n') {
			istr.ignore(1000, '\n');
		}
		else {
			getline(istr, str, '\n');
			ut.alocpy(m_handling, str.c_str());
		}
		if (istr.fail()) {
			m_state.set("Perishable console date entry failed!");
		}
		return istr;
	}
}