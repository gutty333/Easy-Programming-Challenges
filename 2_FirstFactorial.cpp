// For this challenge you will be determining the factorial for a given number.

#include <iostream>
using namespace std;

int FirstFactorial(int num) {

	int multiple = 1;

	// Multiply all the numbers descending from the argument
	// Example if 5 (5,4,3,2,1)
	for (num; num > 0; num--)
	{
		multiple *= num;
	}

	return multiple;
}

int main() 
{
	cout << FirstFactorial(4);
	return 0;
}