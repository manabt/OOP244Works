/* ------------------------------------------------------
OOP244 NAA
Workshop 6 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/06
-----------------------------------------------------------*/
//The code in this workshop is provided by my professor
#ifndef SDDS_NAME_H
#define SDDS_NAME_H

namespace sdds {
	class Name {
		char* m_firstName{};
		char* m_middleName{};
		char* m_lastName{};
		void setEmpty();
		void deAllocate();
		bool m_short{};
	public:
		Name();
		Name(const char* firstName);
		Name(const char* firstName, const char* lastName);
		Name(const char* firstName, const char* lastName, const char* middleName);
		// Copy constructor
		Name(const Name& toCopyFrom);
		// Destructor
		~Name();
		Name& operator=(const Name& toCopyFrom);
		Name& set(const char* first, const char* middle = nullptr, const char* last = nullptr);
		Name& setFirst(const char* first);
		Name& setLast(const char* last);
		Name& setMiddle(const char* middle);
		Name& setShort(bool state);
		Name& operator+=(const char* add);
		bool isEmpty(const char* name = nullptr)const;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& display(std::ostream& ostr = std::cout)const;
		operator bool()const;
	};
	std::istream& operator>>(std::istream& istr, Name& RO);
	std::ostream& operator<<(std::ostream& ostr, const Name& RO);
}

#endif // !SDDS_NAME_H
