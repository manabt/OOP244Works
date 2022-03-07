/* ------------------------------------------------------
OOP244 NAA
Workshop 6 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/06
-----------------------------------------------------------*/
//The code in this workshop is provided by my professor
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name;
      long long m_number;
      char m_vCode[3 + 1];
      char m_sNumber[10 + 1];

      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
      void setEmpty();
      void allocateAndCopy(const char* name);
      void extractChar(std::istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr) const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
      void deAllocate();
   public:
       HealthCard();
       ~HealthCard();
       HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]);
       HealthCard(const HealthCard& hc);
       HealthCard& operator=(const HealthCard& hc);
       operator bool() const;
       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       std::istream& read(std::istream& istr);

   };

   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
   std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


