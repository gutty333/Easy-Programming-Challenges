// For this challenge you will need to find the smallest repeating substring.
/*
have the function StringPeriods(str) take the str parameter being passed and determine if there is some substring K that can be repeated N > 1 times to produce the input string exactly as it appears. Your program should return the longest substring K, and if there is none it should return the string -1.

For example: if str is "abcababcababcab" then your program should return abcab because that is the longest substring that is repeated 3 times to create the final string. Another example: if str is "abababababab" then your program should return ababab because it is the longest substring. If the input string contains only a single character, your program should return the string -1.
*/

#include <iostream>
#include <string>
using namespace std;

/*
traverse the string
extract a substring from the string starting from the beginning
keep count of its length only if the substring can produce the input string after being repeated
iterate again but increasing the substring length
*/
string StringPeriods(string str) 
{
	if (str.length() == 1)
	{
		return "-1";
	}

	string substring = "";
	string result = "";
	int current = 0;

	// Loop to traverse input string and compare substring
	while (current < str.length() / 2)
	{
		bool valid = true; // signal checking if the substring can complete the input string after repetitions
		substring += str[current]; // With each iteration the substring to check will increase

		for (int x = current + 1; x < str.length(); x+=substring.length())
		{
			// condition comparing the current substring to substring in our input string
			// If is not equal than this current substring is invalid
			if (substring != str.substr(x, substring.length()))
			{
				valid = false;
				break;
			}
		}

		// Will update the largest substring that is valid
		if (valid && substring.length() > result.length())
		{
			result = substring;
		}

		current++;
	}

	if (result.length() >= 1)
	{
		return result;
	}
	else
	{
		return "-1";
	}
}

int main() 
{
	cout << StringPeriods("abcababcababcab") << endl; // abcab
	cout << StringPeriods("abcxabc") << endl; // -1
	cout << StringPeriods("affedaaffed") << endl; // -1
	cout << StringPeriods("abababababab") << endl; // ababab
	cout << StringPeriods("gg") << endl; // g
	return 0;
}