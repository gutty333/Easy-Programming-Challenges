// For this challenge you will be manipulating characters in a string based off their positions in the alphabet.
// Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a). Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string.

#include <iostream>
#include <string>
using namespace std;

string LetterChanges(string str) {

	int code;

	// Traverse the string
	for (int x = 0; x < str.length(); x++)
	{
		code = int(str[x]);// Keep track of the ascii code of the current character

		// If the current character is z (lower or upper)
		// Trace back to the beginning of the alphabet
		if (code == 122)
		{
			str[x] = char(97);
		}
		else if (code == 90)
		{
			str[x] = char(65);
		}
		else if (code >= 65 && code <= 90 || code >= 97 && code <= 122)
		{
			// If the range is fine, just replace the char with the next letter
			str[x] = char(code + 1);
		}
		// If the character is a vowel, make it uppercase
		if (toupper(str[x]) == 'A' || toupper(str[x]) == 'E' || toupper(str[x]) == 'I' || toupper(str[x]) == 'O' || toupper(str[x]) == 'U')
		{
			str[x] = toupper(str[x]);
		}
	}

	return str;
}

int main() {

	// keep this function call here
	cout << LetterChanges("fun times!");
	return 0;

}