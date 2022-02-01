#include <iostream>
using namespace std;

int main() {
	//int& m; gives compiler error, references must be initilized;
	int value = 23;
	int& v = value;

	cout << v << endl;

	v = 30;

	cout << v << "   " << value << endl;

	cout << unsigned(&v) << "   " << unsigned(&value) << endl;

	return 0;
}