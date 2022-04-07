/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/22
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }
   void Utils::alocpy(char*& destination, const char* source) {
       delete[] destination;
       destination = nullptr;
       if (source != nullptr) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
   }
   int Utils::getint(const char* prompt) {
       int num;
       if (prompt) cout << prompt;
       cin >> num;
       while (cin.fail()) { // is used to test whether the preceding input succeeded
           cout << "Invalid Integer, retry: ";
           cin.clear(); //clears the error flag on cin so future iostream operations works correctly
           cin.ignore(1000, '\n'); // skips the newline in the buffer
           cin >> num;
       }
       return num;
   }
   int Utils::getint(int min, int max, const char* prompt , const char* errMes) { // modified this function for MS2 because it had some problems
       int num;
       bool valid = false;
       while (valid == false) {
           num = getint(prompt);
           if (num >= min && num <= max) {
               valid = true;
           }
           else {
               if (errMes != nullptr) {
                   cout << errMes << ", retry: " << endl;
               }
               else {
                   cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
               }
           }
       }
       return num;
   }
}