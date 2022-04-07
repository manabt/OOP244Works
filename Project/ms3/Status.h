/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 3
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/04/03
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds {
	class Status {
		char* m_status{};
		int m_statusCode;
	public:
		Status(const char* status = nullptr);
		Status(const Status& toCopyFrom);
		~Status();
		Status& operator=(const Status& toCopyFrom);
		Status& set(const char* status = nullptr, int code = 0);
		Status& operator=(const char* status);
		Status& operator=(int code);
		Status& clear();
		operator const char* ()const;
		operator const int() const;
		operator bool() const;
		std::ostream& display(std::ostream& ostr)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& RO);
}
#endif // !_SDDS_STATUS_H
