#include <iostream>
#include "utils.h"
using namespace std;
using namespace sdds;

int main() {
	int val;
	char str10[10 + 1]; // + 1 for the nullterminatior
	char str[100];

	cout << "Enter abcdefghijklmnopqrstuvwxyz: ";
	cin.get(str10, 11, '\n');
	cout << str10 << endl;
	cin >> str;
	cout << str << endl;

	return 0;
}