// For this challenge you will determine if a string contains some number of distinct characters.
/*
have the function DistinctCharacters(str) take the str parameter being passed and determine if it contains at least 10 distinct characters, if so, then your program should return the string true, otherwise it should return the string false. For example: if str is "abc123kkmmmm?" then your program should return the string false because this string contains only 9 distinct characters: a, b, c, 1, 2, 3, k, m, ? adds up to 9.
*/

#include <iostream>
#include <string>
using namespace std;

string DistinctCharacters(string str)
{
	string temp;
	temp.push_back(str[0]);

	for (int x = 1; x < str.size(); x++)
	{
		if (temp.find(str[x]) == -1)
		{
			temp.push_back(str[x]);
		}
	}

	if (temp.size() >= 10)
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
	cout << DistinctCharacters("abc123kkmmmm?") << endl; // false
	cout << DistinctCharacters("12334bbmma:=6") << endl; // true
	cout << DistinctCharacters("eeeemmmmmmmmm1000") << endl; // false
	return 0;
}
