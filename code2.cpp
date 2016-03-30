// For this challenge you will be determining the factorial for a given number.

#include <iostream>
using namespace std;

int FirstFactorial(int num) {

	int multiple = 1;

	for (num; num > 0; num--)
	{
		multiple *= num;
	}

	return multiple;

}

int main() {

	// keep this function call here
	cout << FirstFactorial(4);
	return 0;

}