#include <iostream>
using namespace std;

int& ref(int& R) {
	return R += 10;
}


int main() {

	int x = 4;
	cout << x << endl;

	cout << ref(x) << endl;

	cout << x << endl;

	return 0;
}