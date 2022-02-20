#include <iostream>
using namespace std;

int getInt() {
	int val;
	cin >> val;
	return val;
}

void getInt(int& val) {
	cin >> val;
}

int main() {
	int value;
	cout << "enter an integer value :" << endl;
	value = getInt();
	cout << "Number is: " << value << endl;
	cout << "enter an integer value :" << endl;
	getInt(value);
	cout << "Number is: " << value << endl;
	return 0;
}