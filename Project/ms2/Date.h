/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/22
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"

namespace sdds {
	const int maxYearValue = 2030;
	class Date {
		int m_year;
		int m_month;
		int m_day;
		Status m_state;
		bool m_formatted = true;
		bool validate();
		int uniqDate()const;
	public:
		Date();
		Date(int year, int month, int day);
		Date& set(int year, int month, int day);
		bool operator==(const Date& date)const;
		bool operator!=(const Date& date)const;
		bool operator<(const Date& date)const;
		bool operator>(const Date& date)const;
		bool operator<=(const Date& date)const;
		bool operator>=(const Date& date)const;
		const Status& state()const;
		Date& formatted(bool condition);
		operator bool()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};
	std::ostream& operator<<(std::ostream& os, const Date& RO);
	std::istream& operator>>(std::istream& is, Date& RO);
}

#endif // !SDDS_DATE_H
