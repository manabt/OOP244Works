#include <iostream>
using namespace std;

int main() {
	int val;
	char str[100];

	cout << "enter 123" << endl;
	cin.ignore(2);
	cin >> val;
	cout << val << endl;
	cout << "Enter abcdefghijklmnopqrstuvwxyz: ";
	cin.ignore(3);
	cin >> str;
	cout << str << endl;

	return 0;
}