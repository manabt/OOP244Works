/* ------------------------------------------------------
OOP244 NAA
Workshop 4 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/10
-----------------------------------------------------------*/
#ifndef SDDS_CARINVENTORY_H_
#define SDDS_CARINVENTORY_H_

namespace sdds {

	class CarInventory {
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
		void deAllocate();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		bool isValid()const;
		void printInfo() const;
		bool isSimilarTo(const CarInventory& car) const;		
	};
	bool find_similar(CarInventory car[], const int num_cars);
}
#endif // !SDDS_CARINVENTORY_H_
