//  For this challenge you will determine the largest double digit number.
// have the function LargestPair(num) take the num parameter being passed and determine the largest double digit number within the whole number. For example: if num is 4759472 then your program should return 94 because that is the largest double digit number. The input will always contain at least two positive digits. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int LargestPair(long long num) 
{
	// Convert the int number to a string for comparing the pairs
	stringstream convert;
	convert << num;
	string temp = convert.str();
	int current, large = 0;

	// Loop through the numbers
	for (int x = 0; x < temp.length() - 1; x++)
	{
		// Isolate all the pairs of the number
		string temp2;
		temp2.push_back(temp[x]);
		temp2.push_back(temp[x + 1]);

		istringstream(temp2) >> current;
		if (current > large) // Compare and find the largest pair
		{
			large = current;
		}
	}

	return large;
}

int main() 
{
	cout << LargestPair(4759472) << endl; // 94
	cout << LargestPair(453857) << endl; // 85
	cout << LargestPair(363223311) << endl; // 63
	cout << LargestPair(5673536634) << endl; // 73 

	return 0;

}