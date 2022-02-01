#include <iostream>
using namespace std;

int foo(int a, int b) {
	return (a + b) * 10;
}

int main()
{
	int x = 6;

	cout << foo(x, 2) << endl; // call will be done as foo( int a = 6, int b = 2 );

	cout << foo(5, 2) << endl; // call will be done as foo( int a = 5, int b = 2 );

	return 0;
}