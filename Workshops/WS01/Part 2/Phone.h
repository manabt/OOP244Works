/* ------------------------------------------------------
OOP244 NAA
Workshop 1 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/23
-----------------------------------------------------------*/
#ifndef SDDS_PHONE_H 
#define SDDS_PHONE_H

namespace sdds {

	const int MAX_NAME = 30 + 1;
	const int AREA = 3 + 1;
	const int PREFIX = 3 + 1;
	const int NUMBER = 4 + 1;

	struct Phone {
		char fullName[MAX_NAME + 1];
		char areaCode[AREA + 1];
		char prefix[PREFIX + 1];
		char number[NUMBER + 1];
	};

	void phoneDir(const char* programTitle, const char* fileName);

}


#endif