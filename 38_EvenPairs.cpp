// For this challenge you will determine if a pair of even numbers exists somewhere in a string.
// have the function EvenPairs(str) take the str parameter being passed and determine if a pair of adjacent even numbers exists anywhere in the string. If a pair exists, return the string true, otherwise return false. For example: if str is "f178svg3k19k46" then there are two even numbers at the end of the string, "46" so your program should return the string true. Another example: if str is "7r5gg812" then the pair is "812" (8 and 12) so your program should return the string true. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string EvenPairs(string str)
{
	int temp, count;

	// Loop through the string parameter
	for (int x = 0; x < str.size(); x++)
	{
		string num;
		count = 0; // Keeps count of even numbers

		// Loop checking for a sequence of number characters
		for (x; x < str.size() && str[x] >= '0' && str[x] <= '9'; x++)
		{
			// Converting current sequence of number character to an int
			num += str[x];
			istringstream(num) >> temp;

			if (temp % 2 == 0) // Validate any even numbers
			{
				num = "";
				count++;
			}
		}

		if (count >= 2)
		{
			return "true";
		}
	}
	
	return "false";
}

int main() 
{
	cout << EvenPairs("f178svg3k19k46") << endl; // true
	cout << EvenPairs("7r5gg812") << endl; // true
	cout << EvenPairs("3gy41d216") << endl; // true
	cout << EvenPairs("f09r27i8e67") << endl; // false
	cout << EvenPairs("fdfs1386eretre") << endl; // true
	return 0;

}