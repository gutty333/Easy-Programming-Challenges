// For this challenge you will be converting a string into snake case format.
/*
have the function SnakeCase(str) take the str parameter being passed and return it in proper snake case format where each word is lowercased and separated from adjacent words via an underscore. The string will only contain letters and some combination of delimiter punctuation characters separating each word.

For example: if str is "BOB loves-coding" then your program should return the string bob_loves_coding.
*/

#include <iostream>
#include <string>
using namespace std;

string SnakeCase(string str) 
{
	for (int x = 0; x < str.size(); x++)
	{
		if (int(str[x]) >= 32 && int(str[x]) <= 47)
		{
			str[x] = '_';
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
	cout << SnakeCase("BOB loves-coding") << endl; // bob_loves_coding
	cout << SnakeCase("cats AND*Dogs-are Awesome") << endl; // cats_and_dogs_are_awesome
	cout << SnakeCase("a b c d-e-f%g") << endl; // a_b_c_d_e_f_g
	return 0;
}
