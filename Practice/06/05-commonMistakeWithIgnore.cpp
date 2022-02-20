#include <iostream>
using namespace std;

int main() {
	char str[100];
	cout << "Enter abcdefghijklmnopqrstuvwxyz: ";
	cin.ignore('\n');  // igonre to the amount  of \n ascii code value which is 10
	cin >> str;
	cout << str << endl;

	return 0;
}