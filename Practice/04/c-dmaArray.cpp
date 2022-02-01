#include <iostream>
using namespace std;


int main() {

	int n;
	int* valPointer = nullptr;

	cout << "enter the number of integers you want to input:  ";
	cin >> n;

	valPointer = new int(n);
	if (valPointer == nullptr)
	{
		cout << "out of memory" << endl;
	}
	else
	{
		int i;
		cout << "Enter values: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << i + 1 << " > ";
			cin >> valPointer[i];
		}
		for (i = n - 1; i >= 0; i--)
		{
			cout << valPointer[i] << " ";
		}
		cout << endl;

		delete[] valPointer;
		valPointer = nullptr;
	}

	return 0;
}