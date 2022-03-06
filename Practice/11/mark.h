#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>

namespace sdds {
	extern int maxMarkValue;

	class Mark {
		char* m_title;
		int m_value;
		int m_max;
		void setSafeEmpty();
		void deAllocate();

	public:
		//constructors (not functions)
		Mark();
		~Mark(); // rule of three (destructor)
		Mark(const char* title, int value = 0, int max = 100);
		Mark(const Mark& toCopyFrom); // rule of three (copy constructor)
		Mark& operator=(const Mark& toCopyFrom); //rule of three(copy assignment)
		Mark& set(const char* title, int value, int max);
		Mark& setValue(int value);
		Mark& setTitle(const char* markTitle);
		Mark& setMax(int max);
		std::istream& read(const char* prompt = nullptr, std::istream& istr = std::cin);

		std::ostream& display(const char* message = nullptr, std::ostream& ostr = std::cout)const;
		bool isEmpty()const;
		int markValue()const;
		int maxValue()const;
		int percent()const;
		const Mark& grade(char* grade)const;
		//operator overloads:
		bool operator==(const Mark& RO)const;
		bool operator!=(const Mark& RO)const;

		Mark operator+(const Mark& RO)const;

		Mark& operator<<(int value);
		Mark& operator<<(const char* title);
		const Mark& operator>>(int& mark)const;

		// type coversion overloads
		operator bool()const;
		operator const char* ()const;
	};
	std::ostream& operator<<(std::ostream& LO, const Mark& RO);
	std::istream& operator>>(std::istream& LO, Mark& RO);

	
}


#endif // !SDDS_MARK_H
