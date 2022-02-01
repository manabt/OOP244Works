#include <iostream>
#include "DMAint.h"
using namespace std;
using namespace sdds;

int main() {

	int* values;
	int size;
	int allocSize = 5;

	values = getDynamicInts(size, 10);

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " : " << values[i] << endl;
	}

	delete[] values;
	return 0;
}