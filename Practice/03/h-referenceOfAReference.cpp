#include <iostream>
using namespace std;

int main() {

	int a = 23;
	int& b = a;
	int& c = b;

	cout << c << endl;

	c = 40;

	cout << a << endl;

	return 0;
}