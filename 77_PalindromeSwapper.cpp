// For this challenge you will determine if a palindrome can be created in a string.
/*
have the function PalindromeSwapper(str) take the str parameter being passed and determine if a palindrome can be created by swapping two adjacent characters in the string. If it is possible to create a palindrome, then your program should return the palindrome, if not then return the string -1. The input string will only contain alphabetic characters. For example: if str is "rcaecar" then you can create a palindrome by swapping the second and third characters, so your program should return the string racecar which is the final palindromic string.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
traverse the string 
continue to swap adjacent characters and check if string is a palindrome
*/
bool palindrome(string value)
{
	string temp = value;

	reverse(temp.begin(), temp.end());

	if (temp == value)
	{
		return true;
	}

	return false;
}

string PalindromeSwapper(string str) 
{
	// in case original input is already a palindrome
	if (palindrome(str))
	{
		return str;
	}

	// traversing the string
	for (int x = 0; x < str.length()-1; x++)
	{
		// swap current adjacent characters
		swap(str[x], str[x + 1]);

		// check if string is now a palindrome
		if (palindrome(str))
		{
			return str;
		}
		else
		{
			// if not valid swap again to set back to the original
			swap(str[x], str[x + 1]);
		}
	}

	return "-1";
}

int main() 
{
	cout << PalindromeSwapper("anna") << endl; // anna
	cout << PalindromeSwapper("kyaak") << endl; // kayak
	cout << PalindromeSwapper("rcaecar") << endl; // racecar
	cout << PalindromeSwapper("madam") << endl; // madam
	return 0;
}