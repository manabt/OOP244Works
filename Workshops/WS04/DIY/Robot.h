/* ------------------------------------------------------
OOP244 NAA
Workshop 4 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/13
-----------------------------------------------------------*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds {
	/*extern const int num_Robot;
	extern Robot robot[6];*/
	class Robot {
		char* m_name;
		char* m_location;
		double m_weight;
		double m_width;
		double m_height;
		double m_speed;
		bool m_deployed;
		void setSafeEmpty();
		void deAllocate();
		Robot& setLocation(const char* location);
	public:
		// Counstructors
		Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment);
		// Destructor
		~Robot();
		// Modifiers member functions
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment);
		
		bool setDeployed(bool status);
		// Queries member functions
		const char* getname()const;
		const char* getLocation()const;
		bool isDeployed()const;
		bool isValid()const;
		double speed()const;
		std::ostream& display(const char* message = nullptr)const;
		};
	int conrtolRooomReport(const Robot robot[], int num_Robot);
	void summary(const Robot robot[], int num_Robot);
	void displayTableHeader();
}

#endif // !SDDS_ROBOT_H
