//  For this challenge you will be determining whether or not a number is a power of two.
// have the function PowersofTwo(num) take the num parameter being passed which will be an integer and return the string true if it's a power of two. If it's not return the string false. For example if the input is 16 then your program should return the string true but if the input is 22 then the output should be the string false.

#include <iostream>
#include <cmath>
#include <string>
#include <climits>
using namespace std;


string PowersofTwo(int num) {

	for (int x = 0; x < INT_MAX; x++)
	{
		if (pow(2, x) == num)
		{
			return "true";
		}
		else if (pow(2, x) > num)
		{
			break;
		}
	}

	return "false";
}

int main() {

	// keep this function call here
	cout << PowersofTwo(4) << endl; // True
	cout << PowersofTwo(124) << endl; // False
	cout << PowersofTwo(16) << endl; // True
	cout << PowersofTwo(22) << endl; // False
	return 0;

}