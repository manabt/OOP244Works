#include <iostream>
using namespace std;

void line(char fill = '-', int size = 50);


int main() {

	line();
	line('*');
	line('#', 20);

	return 0;
}


void line(char fill, int size) {

	for (int i = 0; i < size; cout << fill, i++);
	cout << endl;
}