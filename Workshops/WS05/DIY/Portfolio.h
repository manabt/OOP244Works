/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
/* ------------------------------------------------------
OOP244 NAA
Workshop 4 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/22
-----------------------------------------------------------*/
//The code in this workshop is provided by my professor
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;
   public:
       Portfolio();
       void emptyPortfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       operator const char* ()const;
       operator const double()const;
       operator const char()const;
       operator bool()const;
       Portfolio& operator+=(const double val);
       Portfolio& operator-=(const double val);
       bool operator~()const;
       Portfolio& operator<< (Portfolio& port);
       Portfolio& operator>> (Portfolio& port);
   };
   double operator+=(double& val, const Portfolio& portfolio);
   double operator+(const Portfolio& leftPortfolio, const Portfolio& rightPortfolio);
  
}
#endif // SDDS_Portfolio_H_