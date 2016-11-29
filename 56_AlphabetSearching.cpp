// For this challenge you will determine if a set of characters exists in a string.
// have the function AlphabetSearching(str) take the str parameter being passed and return the string true if every single letter of the English alphabet exists in the string, otherwise return the string false. For example: if str is "zacxyjbbkfgtbhdaielqrm45pnsowtuv" then your program should return the string true because every character in the alphabet exists in this string even though some characters appear more than once.

#include <iostream>
#include <string>
using namespace std;

// Search function
bool search(string alphabet, char value)
{
	for (int y = 0; y < alphabet.size(); y++)
	{
		if (value == alphabet[y])
		{
			return true;
		}
	}
	return false;
}


string AlphabetSearching(string str) 
{
	string alphabet;

	for (int x = 0; x < str.size(); x++)
	{
		// Only focus on analyzing letters
		if ((str[x] >= 'a' && str[x] <= 'z') || (str[x] >= 'A' && str[x] <= 'Z'))
		{
			// Condition to check for repeats
			// If is not a repeat add it to the list of alphabet letters
			if (!search(alphabet, str[x]))
			{
				alphabet += str[x];
			}
		}
	}

	if (alphabet.size() == 26)
	{
		return "true";
	}
	else
	{
		return "false";
	}	
}

int main() 
{

	cout << AlphabetSearching("zacxyjbbkfgtbhdaielqrm45pnsowtuv") << endl; // true
	cout << AlphabetSearching("abcdefghijklmnopqrstuvwxyyyy") << endl; // false
	cout << AlphabetSearching("abc123456kmo") << endl; // false

	return 0;
}