#include <iostream>
using namespace std;

void addTen(int* ptrVar) {
	*ptrVar += 10; // (*ptrVar) += 10;
}

void addTen(int& refVar) {
	refVar += 10;
}

int main() {
	
	int a = 45;

	addTen(&a);
	cout << a << endl;

	int b = 65;

	addTen(b);
	cout << b << endl;

	return 0;
}