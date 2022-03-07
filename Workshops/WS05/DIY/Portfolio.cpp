/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds {
    Portfolio::Portfolio() {
       emptyPortfolio();
    }
    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }
    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    Portfolio::operator const double() const {
        return (const double)m_value;
    }
    Portfolio::operator const char* ()const {
        return (const char*)m_stock;
    }
    Portfolio::operator const char()const {
        return (const char)m_type;
    }
    Portfolio::operator bool() const {
        bool success = false;
        if (m_type == 'V' || m_type == 'G' || m_type == 'I')
            success = true;
        return success;
    }
    Portfolio& Portfolio::operator+=(const double val) {
        if (Portfolio::operator bool() && val >= 0)
            m_value += val;
        return *this;
    }
    Portfolio& Portfolio::operator-=(const double val) {
        if (Portfolio::operator bool() && val >= 0)
            m_value -= val;
        return *this;
    }
    bool Portfolio::operator~()const {
        bool success = false;
        if (m_value < 0)
            success = true;
        return success;
    }
    Portfolio& Portfolio::operator<< (Portfolio& port) {
        if (Portfolio::operator bool())
            m_value += port.m_value;
            port.m_value = 0;
            port.m_stock[0] = 0;
            port.m_type = 'E';
        return *this;
    }
    Portfolio& Portfolio::operator>> (Portfolio& port) {
        if (Portfolio::operator bool())
        {
            port.m_value += m_value;

            emptyPortfolio();
        }
        return *this;
    }
    double operator+(const Portfolio& leftPortfolio, const Portfolio& rightPortfolio) {
        if (leftPortfolio.operator bool() && rightPortfolio.operator bool())
        {
            return leftPortfolio.operator const double() + rightPortfolio.operator const double();
        }
        return 0;
    }
    double operator+=(double& val, const Portfolio& portfolio) {
        return val += portfolio.operator const double();
    }
}