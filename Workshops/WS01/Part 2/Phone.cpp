/* ------------------------------------------------------
OOP244 NAA
Workshop 1 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/23
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;

namespace sdds {

	void phoneDir(const char* programTitle, const char* fileName)
    {

        FILE* fptr = fopen(fileName, "r");

        if (fptr == NULL)
        {
            cout << "Broken Phone Book phone direcotry search" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using Broken Phone Book directory." << endl;
        }
        else if (fptr != NULL)
        {
            Phone phoneRecord;
            char userInput[MAX_NAME + 1];
            char temp[MAX_NAME + 1];
            char temp2[MAX_NAME + 1];
            const char* match = 0;
            int valid = 0;

            cout << programTitle << " phone direcotry search" << endl <<
                "-------------------------------------------------------" << endl;
            
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n> ";
            cin >> userInput;
            
            while (valid == 0)
            {
                if (strCmp("!", userInput) != 0)
                {
                    valid = 0;
                    toLowerCaseAndCopy(temp, userInput);
                    

                    while (!feof(fptr))
                    {
                        fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", phoneRecord.fullName, phoneRecord.areaCode, phoneRecord.prefix, phoneRecord.number);
                        toLowerCaseAndCopy(temp2, phoneRecord.fullName);
                        match = strStr(temp2, temp);

                        if (match != nullptr)
                        {
                            cout << phoneRecord.fullName << ": (" << phoneRecord.areaCode << ") " << phoneRecord.prefix << "-" << phoneRecord.number << endl;
                        }
                    }
                    rewind(fptr);
                    cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n> ";
                    cin >> userInput;
                }
                else if (strCmp("!", userInput) == 0)
                {
                    cout << "Thank you for using " << programTitle << " directory." << endl;
                    valid = 1;

                }
            }
            fclose(fptr);
        }
    }
}
