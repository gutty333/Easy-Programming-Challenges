//  For this challenge you will be adding up all the numbers from 1 to a certain argument.

#include <iostream>
using namespace std;

int SimpleAdding(int num) {

	int total = 0;

	for (int x = 1; x <= num; x++)
	{
		total += x;
	}
	return total;
}

int main() {

	// keep this function call here
	cout << SimpleAdding(12);
	return 0;
}