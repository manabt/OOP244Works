#include <iostream>
#include "DMAint.h"
using namespace std;

namespace sdds {
	int allocSize = 10;

	int* getDynamicInts(int& size, int initialSize) {
		int dataSize = initialSize;
		int* dataPointer = nullptr;
		dataPointer = new int[dataSize];
		bool done = false; // bool = 0;
		int i;

		cout << "Enter values : (-1 to stop)" << endl;

		for (i = 0; !done; i++)
		{
			if (i == dataSize)
			{
				int* temp = new int[dataSize + allocSize];
				for (int j = 0; j < dataSize; j++)
				{
					temp[j] = dataPointer[j];
				}

				delete[] dataPointer;
				dataSize += allocSize;
				dataPointer = temp;
			}
			cout << i+1 << " > ";
			cin >> dataPointer[i];
			if (dataPointer[i] < 0)
			{
				size = i;
				done = true;
			}
		}

		int* temp = new int[size];
		for (int j = 0; j < size; j++)
		{
			temp[j] = dataPointer[j];
		}

		delete[] dataPointer;
		dataPointer = temp;
		return dataPointer;
	}

}