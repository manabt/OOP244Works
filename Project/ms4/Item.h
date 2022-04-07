/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 4
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/04/04
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "iProduct.h"
#include "Status.h"

namespace sdds {
	class Item : public iProduct {
		double m_price{};
		int m_qty{};
		int m_qtyNeeded{};
		char* m_description{};
		bool m_linear{};
	protected:
		Status m_state{};
		int m_sku{};
		bool linear()const;
	public:
		Item();
		// Rule of three :
		Item(const Item& source);
		Item& operator=(const Item& source);
		virtual ~Item();
		Item& clear();
		// returns the number of products needed
		int qtyNeeded()const;
		// retuns the quantity on hand
		int qty()const;
		// returns the price of the produce
		operator double()const;
		// returns if the iProduct is in a good state
		operator bool()const;
		// to reduce the quantity on hand
		int operator-=(int qty);
		// to increase the quantity on hand
		int operator+=(int qty);
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		void linear(bool isLinear);
		// return true if the sku is a match to the iProduct's sku
		bool operator==(int sku)const;
		// returns true if the description is found in the iPorduct's description
		bool operator==(const char* description)const;
		// to read the Stock-Keeping Unit from console before
		// main data entry
		int readSku(std::istream& istr);
		// saves the iProduct into a file
		std::ofstream& save(std::ofstream& ofstr)const;
		// loads an iProduct from a file
		std::ifstream& load(std::ifstream& ifstr);
		// displays the iProduct on the screen
		std::ostream& display(std::ostream& ostr)const;
		// reads the iProduct from the console
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_ITEM_H
