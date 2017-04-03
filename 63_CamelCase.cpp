// For this challenge you will be converting a string into camel case format.
/*
have the function CamelCase(str) take the str parameter being passed and return it in proper camel case format where the first letter of each word is capitalized (excluding the first letter). The string will only contain letters and some combination of delimiter punctuation characters separating each word.

For example: if str is "BOB loves-coding" then your program should return the string bobLovesCoding.
*/

#include <iostream>
#include <string>
using namespace std;

/*
iterate through string
make the first word lowercase
locate any punctuations as a signal to Capitalize the first letter of each word
*/

string CamelCase(string str) 
{
	for (int x = 0; x < str.size(); x++)
	{
		if (x == 0)
		{
			str[x] = tolower(str[x]);
			continue;
		}

		if (int(str[x-1]) >= 32 && int(str[x-1]) <= 47)
		{
			str[x] = toupper(str[x]);
			str.erase(str.begin() + x-1);
			x--;

		}
		else
		{
			str[x] = tolower(str[x]);
		}
	}

	return str;
}

int main() 
{
	cout << CamelCase("BOB loves-coding") << endl; //bobLovesCoding
	cout << CamelCase("cats AND*Dogs-are Awesome") << endl; // catsAndDogsAreAwesome
	cout << CamelCase("a b c d-e-f%g") << endl; // aBCDEFG
	return 0;
}