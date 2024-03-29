/* ------------------------------------------------------
OOP244 NAA
Workshop 2 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/31
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstdlib> for qsort
#include "DNA.h"
#include "cStrTools.h"

using namespace std;

namespace sdds {
	DNA* matchDNAs = nullptr;
	FILE* ptr = nullptr;
	int dataSize = 50, expansionSize = 10, counter;


	bool beginSearch(const char* filename) {
		cout << "DNA search program" << endl;
		bool success = false;
		ptr = fopen(filename, "r");
		if (ptr != NULL) {
			success = true;
		}
		return success;
	}

	bool read(const char* subDNA) {
		DNA dnaRecord;
		bool success = false;
		matchDNAs = new DNA[dataSize];
		char subDnaTemp[DNA_INPUT];
		toLowerCaseAndCopy(subDnaTemp, subDNA);

		counter = 0;
		while (fscanf(ptr, "%d,%[^\n]", &dnaRecord.id, dnaRecord.dnaStrand) == 2)
		{
			if (strStr(dnaRecord.dnaStrand, subDnaTemp) != 0)
			{
				if (counter == dataSize)
				{
					DNA* temp = new DNA[dataSize + expansionSize];
					for (int j = 0; j < dataSize; j++)
					{
						temp[j] = matchDNAs[j];
					}
					delete[] matchDNAs;
					matchDNAs = temp;
					dataSize += expansionSize;
				}
				matchDNAs[counter].id = dnaRecord.id;
				strCpy(matchDNAs[counter].dnaStrand, dnaRecord.dnaStrand);
				counter += 1;
				success = true;
			}
		}
		rewind(ptr);
		if (counter == 0)
			deallocate();

		return success;
	}

	/*int compare(const void* dna1, const void* dna2) {
		return ((DNA*)dna1)->id - ((DNA*)dna2)->id;
	}*/

	// for the sorting part I read some articles from the internet and got familiar with the q sort function and used it for the program
	void sort() {
		DNA tempSort;
		//qsort(matchDNAs, counter, sizeof(DNA), compare);
		for (int i = 0; i < counter - 1; i++) {
			for (int j = 0; j < counter - i - 1; j++)
				if (matchDNAs[j].id > matchDNAs[j + 1].id)
				{
					tempSort = matchDNAs[j];
					matchDNAs[j] = matchDNAs[j + 1];
					matchDNAs[j + 1] = tempSort;
				}
		}

	}

	void displayMatches() {
		cout << counter << " matches found:" << endl;
		for (int i = 0; i < counter; i++)
		{
			cout << i + 1 << ") " << matchDNAs[i].id << ":" << endl;
			cout << matchDNAs[i].dnaStrand << endl;
			cout << "======================================================================" << endl;
		}
	}

	void deallocate() {
		delete[] matchDNAs;
		matchDNAs = nullptr;
	}

	void endSearch() {

		cout << "DNA Search Program Closed." << endl;
		fclose(ptr);
	}
}