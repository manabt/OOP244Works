/* ------------------------------------------------------
OOP244 NAA
Workshop 1 part 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/29
-----------------------------------------------------------*/
// the cStrTools module code is compeletly provided by my professor Fardad Soleimanloo
#ifndef cStrTools_CSTRTOOLS_H_
#define cStrTools_CSTRTOOLS_H_ 

namespace sdds {


	// returns the lower case value of a character
	char toLower(char ch);

	// compares s1 and s2 cStrings and returns:
	// > 0 if s1 > s2
	// < 0 if s1 < s3
	// == 0 if s1 == s2
	int strCmp(const char* s1, const char* s2);

	// compares s1 and s2 cStrings upto len characters and returns:
	// > 0 if s1 > s2
	// < 0 if s1 < s3
	// == 0 if s1 == s2
	int strnCmp(const char* s1, const char* s2, int len);

	// copies src to des
	void strCpy(char* des, const char* src);

	// returns the length of str
	int strLen(const char* str);

	// if "find" is found in "str" it will return the addres of the match
	// if not found it will returns nullptr (zero)
	const char* strStr(const char* str, const char* find);

	// returns true if ch is alphabetical
	int isAlpha(char ch);

	// returns true if ch is a whitespace character
	int isSpace(char ch);

	// removes the non-alphabetic characters from the begining and end of a word
	void trim(char word[]);

	// copies the  lower case version of the source into des.
	void toLowerCaseAndCopy(char des[], const char source[]);

	// reads a cString upto maxSize characters or upto the delimiter character,
	// whichever comes first (skipping leading white space characters but accpting
	// spaces in the cString)

	void read(char* cString, unsigned int maxSize, char delimiter = '\n');

}
#endif
