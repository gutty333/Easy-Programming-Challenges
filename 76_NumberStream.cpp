// For this challenge you will determine if a stream of digits occurs in a string.
/*
have the function NumberStream(str) take the str parameter being passed which will contain the numbers 2 through 9, and determine if there is a consecutive stream of digits of at least N length where N is the actual digit value. If so, return the string true, otherwise return the string false. For example: if str is "6539923335" then your program should return the string true because there is a consecutive stream of 3's of length 3. The input string will always contain at least one digit.
*/

#include <iostream>
#include <string>
using namespace std;

/*
traverse the string
have a temp string that will increase if values are consecutive
if the next value is not the same as current consecutive values
break and analyze the length of the temp string
if the length matches the digit value than return true
else continue until the string has been fully traversed
*/
string NumberStream(string str) 
{
	if (str.length() == 1)
	{
		return "false";
	}

	string temp = "";
	temp += str[0];

	for (int x = 1; x < str.length(); x++)
	{
		if (temp.empty())
		{
			temp.push_back(str[x]);
			continue;
		}

		// If values are the same than add it to temp string
		if (str[x] == temp[0])
		{
			temp += str[x];
		}
		else
		{
			// clear the temp string
			temp.clear();
		}

		// condition to analyze length of temp string
		// if length matches the consecutive values than it is valid
		if (temp.length() > 1 && char(temp.length() + 48) == temp[0])
		{
			return "true";
		}
	}

	return "false";
}

int main() 
{
	cout << NumberStream("5556293383563665") << endl; // false
	cout << NumberStream("5788888888882339999") << endl; // true
	cout << NumberStream("6539923335") << endl; // true
	return 0;
}