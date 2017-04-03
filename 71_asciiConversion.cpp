//  For this challenge you will be replacing certain characters in a string.
/*
have the function ASCIIConversion(str) take the str parameter being passed and return a new string where every character, aside from the space character, is replaced with its corresponding decimal character code. For example: if str is "dog" then your program should return the string 100111103 because d = 100, o = 111, g = 103.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string ASCIIConversion(string str) 
{
	string result;

	for (int x = 0; x < str.size(); x++)
	{
		if (int(str[x]) != 32)
		{
			stringstream convert;
			convert << int(str[x]);
			result += convert.str();
		}
		else
		{
			result += " ";
		}
	}

	return result;
}

int main() 
{
	cout << ASCIIConversion("dog") << endl; // 100111103
	cout << ASCIIConversion("hello world") << endl; // 104101108108111 119111114108100
	cout << ASCIIConversion("abc **") << endl; // 979899 4242
	return 0;
}