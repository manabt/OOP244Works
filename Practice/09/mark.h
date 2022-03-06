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
		Mark& setTitle(const char* markTitle);

	public:
		Mark();
		~Mark();
		Mark(const char* title, int value = 0, int max = 100);
		Mark(const Mark& toCopyFrom);
		Mark& set(const char* title, int value, int max);
		Mark& setValue(int value);
		Mark& setMax(int max);
		Mark& read(const char* prompt = nullptr);
		std::ostream& display(const char* message = nullptr)const;

		bool isEmpty()const;
		int markValue()const;
		int maxValue()const;
		int percent()const;
		const Mark& grade(char* grade)const;
	};

}



#endif // !SDDS_MARK_H
