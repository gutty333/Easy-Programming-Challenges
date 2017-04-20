// For this challenge you will be determining if a string produces a valid serial number.
/*
have the function SerialNumber(str) take the str parameter being passed and determine if it is a valid serial number with the following constraints:

1. It needs to contain three sets each with three digits (1 through 9) separated by a period.
2. The first set of digits must add up to an even number.
3. The second set of digits must add up to an odd number.
4. The last digit in each set must be larger than the two previous digits in the same set.

If all the above constraints are met within the string, the your program should return the string true, otherwise your program should return the string false. For example: if str is "224.315.218" then your program should return "true".
*/

#include <iostream>
#include <string>
using namespace std;

/*
check that the size is correct
check that only 1-9 are included
add the first 3 digits
add the second set 
check the last digit of each set
*/

string SerialNumber(string str) 
{
	int first, second;

	if (str.size() < 11)
	{
		return "false";
	}

	for (int x = 0; x < str.size(); x++)
	{
		if (str[x] == '0')
		{
			return "false";
		}
	}

	first = int(str[0]) + int(str[1]) + int(str[2]);
	second = int(str[4]) + int(str[5]) + int(str[6]);

	if (first % 2 != 0 || second % 2 == 0)
	{
		return "false";
	}

	if (str[2] < str[1] || str[2] < str[0] || str[6] < str[5] || str[6] < str[4] || str[10] < str[8] || str[10] < str[9])
	{
		return "false";
	}
	else
	{
		return "true";
	}
}

int main() 
{
	cout << SerialNumber("224.315.218") << endl; // true
	cout << SerialNumber("11.124.667") << endl; // false
	cout << SerialNumber("114.568.112") << endl; // true
	return 0;
}