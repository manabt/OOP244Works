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
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	bool Item::linear() const {
		return m_linear;
	}
	Item::Item() = default;
	Item::Item(const Item& source) {
		operator=(source);
	}
	Item& Item::operator=(const Item& source) {
		if (this != &source) {
			if (source.m_sku != 0) {
				ut.alocpy(m_description, source.m_description);
				m_price = source.m_price;
				m_qty = source.m_qty;
				m_qtyNeeded = source.m_qtyNeeded;
				m_linear = source.m_linear;
				m_state = source.m_state;
				m_sku = source.m_sku;
			}
			else {
				m_state.set("Empty");
			}
		}
		return *this;
	}
	Item::~Item() {
		clear();
		delete[] m_description;
		m_description = nullptr;
	}
	int Item::qtyNeeded() const {
		return m_qtyNeeded;
	}
	int Item::qty() const {
		return m_qty;
	}
	Item::operator double() const {
		return m_price;
	}
	Item::operator bool() const {
		return m_state;
	}
	int Item::operator-=(int qty) {
		if (qty) {
			m_qty -= qty;
		}
		return m_qty;
	}
	int Item::operator+=(int qty) {
		if (qty) {
			m_qty += qty;
		}
		return m_qty;
	}
	void Item::linear(bool isLinear) {
		m_linear = isLinear;
	}
	Item& Item::clear() {
		m_state.clear();
		return *this;
	}
	bool Item::operator==(int sku) const {
		return m_sku == sku;
	}
	bool Item::operator==(const char* description) const {
		bool state = false;
		if (strstr(m_description, description) != nullptr && description != nullptr) {
			state = true;
		}
		return state;
	}
	int Item::readSku(std::istream& istr) {
		cout << "SKU: ";
		m_sku = ut.getint(40000,99999);
		return m_sku;
	}
	std::ofstream& Item::save(std::ofstream& ofstr) const {
		if (m_state) {
			ofstr << m_sku << '\t';
			ofstr << m_description << '\t';
			ofstr << m_qty << '\t';
			ofstr << m_qtyNeeded << '\t';
			ofstr.setf(ios::fixed);
			ofstr.precision(2);
			ofstr << m_price; // no newline added
		}
		return ofstr;
	}
	std::ifstream& Item::load(std::ifstream& ifstr) {
		string str;
		clear();
		ifstr >> m_sku;
		ifstr.ignore(1000, '\t');
		getline(ifstr, str, '\t');
		if (ifstr) ut.alocpy(m_description, str.c_str());
		//m_description = ut.getDynCstr(ifstr,'\t');
		ifstr >> m_qty;
		ifstr.ignore(1000, '\t');
		ifstr >> m_qtyNeeded;
		ifstr.ignore(1000, '\t');
		ifstr >> m_price;
		ifstr.ignore();
		if (!ifstr) {
			m_state.set("Input file stream read failed!");
		}
		return ifstr;
	}
	std::ostream& Item::display(std::ostream& ostr) const {
		if (m_state) {
			if (m_linear == true) {
				ostr.width(5);
				ostr << m_sku << " | ";
				ostr.setf(ios::left);
				if (strlen(m_description) > 35) {
					for (int i = 0; i < 35; i++) {
						ostr << m_description[i];
					}
				}
				else {
					ostr.width(35);
					ostr << m_description;
				}
				ostr << " | ";
				ostr.unsetf(ios::left);
				ostr.width(4);
				ostr << m_qty << " | ";
				ostr.width(4);
				ostr << m_qtyNeeded << " | ";
				ostr.unsetf(ios::scientific);
				ostr.setf(ios::fixed);
				ostr.width(7);
				ostr.precision(2);
				ostr << m_price << " |";
			}
			else {
				double fund;
				fund = (double)(m_price * (double)(m_qtyNeeded - (double)m_qty));
				ostr << "AMA Item:" << endl;
				ostr << m_sku << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << "Unit Price: $" << m_price << endl;
				ostr << "Needed Purchase Fund: $" << fund;
			}
		}
		else {
			ostr << m_state;
		}
		return ostr;
	}
	std::istream& Item::read(std::istream& istr) {
		string str;
		clear();
		cout << "AMA Item:" << endl;
		cout << "SKU: " << m_sku << endl;
		istr.ignore(1000, '\n');
		cout << "Description: ";
		getline(istr, str, '\n');
		if (istr) ut.alocpy(m_description, str.c_str());
		cout << "Quantity Needed: ";
		m_qtyNeeded = ut.getint(1, 9999);
		cout << "Quantity On Hand: ";
		m_qty = ut.getint(0, m_qtyNeeded);
		cout << "Unit Price: $";
		m_price = ut.getdouble(0.0, 9999.0);
		if (istr.fail()) {
			m_state.set("Console entry failed!");
		}
		return istr;
	}
}
