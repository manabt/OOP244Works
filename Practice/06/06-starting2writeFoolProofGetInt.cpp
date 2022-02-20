#include <iostream>
#include "utils.h"
using namespace std;
using namespace sdds;

int main() {
	int val;
	char str[100];

	cout << "enter 123" << endl;
	cin.ignore(2);
	val = getint();
	cout << val << endl;

	getint(val, "Enter 123: ");
	cout << val << endl;
	
	cout << "Enter abcdefghijklmnopqrstuvwxyz: ";
	cin.ignore(2);
	cin >> str;
	cout << str << endl;

	return 0;
}