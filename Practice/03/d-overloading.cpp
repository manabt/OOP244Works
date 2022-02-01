#include <iostream>
using namespace std;

void line(char symbol, int length) {

	for (int i = 0; i < length; cout << symbol, i++);
	cout << endl;
}

void line(char symbol) {
	line(symbol, 70);
}

void line() {
	line('-');
}

void line(int length) {
	line('$', length);
}

int main() {

	line('*', 45);

	line('&');

	line();

	line(20);

	return 0;
}