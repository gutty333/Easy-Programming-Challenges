// For this challenge you will be counting how many times a specific pattern occurs in a large number.
/*
have the function OneDecremented(num) count how many times a digit appears that is exactly one less than the previous digit. For example: if num is 5655984 then your program should return 2 because 5 appears directly after 6 and 8 appears directly after 9. The input will always contain at least 1 digit.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int OneDecremented(long long num)
{
	stringstream convert;
	convert << num;
	string number = convert.str();

	int count = 0;
	for (int x = 0; x < number.size(); x++)
	{
		if (x > 0)
		{
			if (int(number[x-1]) - int(number[x]) == 1)
			{
				count++;
			}
		}
	}

	return count;
}

int main() 
{
	cout << OneDecremented(5655984) << endl; // 2
	cout << OneDecremented(9876541110) << endl; // 6
	cout << OneDecremented(56) << endl; // 0
	return 0;

}