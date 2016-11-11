// For this challenge you will be determining the least amount of digits needed to produce a number.
// have the function ProductDigits(num) take the num parameter being passed which will be a positive integer, and determine the least amount of digits you need to multiply to produce it. For example: if num is 24 then you can multiply 8 by 3 which produces 24, so your program should return 2 because there is a total of only 2 digits that are needed. Another example: if num is 90, you can multiply 10 * 9, so in this case your program should output 3 because you cannot reach 90 without using a total of 3 digits in your multiplication. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int ProductDigits(int num) 
{
	int result = 10000;

	for (int x = 1; x <= num; x++)
	{
		for (int y = 1; y <= num; y++)
		{
			// Find which numbers multiply to our input
			if (x*y == num)
			{
				// Convert to a string to later find the amount of digits
				stringstream convert;
				convert << x << y;

				// Keep track of the calculation with lowest amount of digits
				if (convert.str().length() < result)
				{
					result = convert.str().length();
				}
			}
		}
	}
	
	return result;
}

int main()
{
	cout << ProductDigits(24) << endl; // 2
	cout << ProductDigits(90) << endl; // 3
	cout << ProductDigits(6) << endl; // 2
	cout << ProductDigits(23) << endl; // 3
	cout << ProductDigits(1) << endl; // 2
	cout << ProductDigits(5000) << endl; // 4
	cout << ProductDigits(72) << endl; // 2
	return 0;
}