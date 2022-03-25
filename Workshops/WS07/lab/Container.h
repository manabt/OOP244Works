/* ------------------------------------------------------
OOP244 NAA
Workshop 7 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 17
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

namespace sdds {
	const int maxChar = 51;
	class Container {
		char m_content[maxChar];
		int m_capacity;
		int m_contentVol;
		Container& set(const char* content, int capacity, int contentVol = 0);
	protected:
		void setEmpty();
		int capacity()const;
		int volume()const;
	public:
		Container(const char* content, int capacity, int contentVol = 0);
		int operator+=(int value);
		int operator-=(int value);
		operator bool()const;
		Container& clear(int capacity, const char* desc);
		std::ostream& print(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
	std::istream& operator>>(std::istream& istr, Container& RO);
	std::ostream& operator<<(std::ostream& ostr, const Container& RO);
	int getint(int min, int max);
}
#endif // !SDDS_CONTAINER_H
