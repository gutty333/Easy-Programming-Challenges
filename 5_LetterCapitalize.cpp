// For this challenge you will be capitalizing certain characters in a string.
// Capitalize the first letter of each word. Words will be separated by only one space.

#include <iostream>
#include <string>
using namespace std;

string LetterCapitalize(string str) {

	for (int x = 0; x < str.length(); x++)
	{
		// Alway capitalize the first letter of the string
		if (x == 0)
		{
			str[x] = toupper(str[x]);
		}
		// If the character prior to the current character was a space
		// Capitalize the current character
		else if (str[x - 1] == ' ')
		{
			str[x] = toupper(str[x]);
		}
	}

	return str;
}

int main() 
{
	cout << LetterCapitalize("i ran there");
	return 0;
}