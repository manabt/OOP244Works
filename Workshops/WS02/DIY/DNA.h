/* ------------------------------------------------------
OOP244 NAA
Workshop 2 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/31
-----------------------------------------------------------*/
#ifndef SDDS_DNA_H
#define SDDS_DNA_H

namespace sdds {
	const int MAX_STRAND = 1000 + 1;
	const int DNA_INPUT = 100 + 1;

	struct DNA {
		int id;
		char dnaStrand[MAX_STRAND];
	};

	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	int compare(const void* dna1, const void* dna2);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
}
#endif