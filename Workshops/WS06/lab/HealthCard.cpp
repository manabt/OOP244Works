/* ------------------------------------------------------
OOP244 NAA
Workshop 6 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/06
-----------------------------------------------------------*/
//The code in this workshop is provided by my professor
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		bool valid = false;
		if (name != nullptr && name[0] != 0 && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9)
			valid = true;
		return valid;
	}
    void HealthCard::setEmpty() {
        m_name = nullptr;
        m_number = 0;
        m_vCode[3] = { };
        m_sNumber[10] = { };
    }
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else {
            deAllocate();
            setEmpty();
        }
    }
    void HealthCard::deAllocate() {
        delete[] m_name;
        m_name = nullptr;
    }
    HealthCard::HealthCard() {
        setEmpty();
    }
    HealthCard::~HealthCard() {
        deAllocate();
    }
    void HealthCard::allocateAndCopy(const char* name) {
        deAllocate();
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    void HealthCard::extractChar(istream& istr, char ch) const {
        char nextCh;
        int maxChar = 1000;
        nextCh = istr.peek();
        if (nextCh == ch) {
            istr.ignore();
        }
        else {
            istr.ignore(maxChar, ch);
            istr.setstate(ios::failbit);
        }
    }
    ostream& HealthCard::printIDInfo(ostream& ostr) const {
        return ostr << m_number << '-' << m_vCode << ", " << m_sNumber;
    }
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        set(name, number, vCode, sNumber);
    }
    HealthCard::HealthCard(const HealthCard& hc) {
        if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
            *this = hc;
        }
    }
    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this != &hc) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }

        return *this;
    }
    HealthCard::operator bool() const {
        return(m_name != nullptr);
    }
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
        if (*this) {
            if (toFile) {
                ostr << m_name << ",";
                printIDInfo(ostr) << endl;
            }
            else {
                ostr << setw(50);
                ostr.setf(ios::left);
                ostr.fill('.');
                ostr << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }
    istream& HealthCard::read(istream& istr) {
        char name[MaxNameLength];
        long long number;
        char vCode[3];
        char sNumber[10];
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');

        if (!istr.fail()){
            set(name, number, vCode, sNumber);
        }

        istr.clear();
        istr.ignore(1000, '\n');

        return istr;
    }
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }
    istream& operator>>(istream& istr, HealthCard& hc) {
        return hc.read(istr);
    }

}