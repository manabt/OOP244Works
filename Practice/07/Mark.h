#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>

namespace sdds {

	class Mark {
		char* m_title;
		int m_value;
		int m_max;
		Mark& setSafeEmpty();
		Mark& setTitle(const char* titleOfMark);
		void deAllocate();
	public:
		Mark();
		~Mark();
		Mark(const char* title, int markValue = 0, int maxValue = 100);
		Mark& setValue(int markValue);
		Mark& setMax(int maxValue);
		Mark& set(const char* title, int markValue, int maxValue);
		Mark& read(const char* prompt = nullptr);

		std::ostream& display(const char* message = nullptr)const;
		int markValue()const;
		int maxValue()const;
		const Mark& grade(char* grade)const;
		int percent()const;
		bool isEmpty()const;
	};

	extern int maxMarkValue;
}


#endif // !SDDS_MARK_H

