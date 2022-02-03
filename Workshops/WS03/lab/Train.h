#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
	const int MAX_NAME_LENGTH = 20 + 1;
	const int MAX_PEOPLE = 1000 + 1;
	const int MAX_SPEED = 320 + 1;

	class Train {
		char m_trainName[MAX_NAME_LENGTH];
		int m_numPeople;
		double m_speed;
		void setSafeEmpty();
	public:
		void set(const char* name, int num, double speed);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
	};
}


#endif // !SDDS_TRAIN_H

