// For this challenge you will be determining if you can create a palindrome from a list of numbers.
// have the function PalindromeCreator(str) take the str parameter being passed and determine if it is possible to create a palindromic string of at least 3 characters by removing 1 or 2 characters. For example: if str is "abjchba" then you can remove the characters jc to produce "abhba" which is a palindrome. For this example your program should return the two characters that were removed with no delimiter and in the order they appear in the string, so jc. If 1 or 2 characters cannot be removed to produce a palindrome, then return the string not possible. If the input string is already a palindrome, your program should return the string palindrome.  The input will only contain lowercase alphabetic characters.Your program should always attempt to create the longest palindromic substring by removing 1 or 2 characters(see second sample test case as an example).The 2 characters you remove do not have to be adjacent in the string.

#include <iostream>
#include <string>
using namespace std;

bool palindromeCheck(string str)
{
	string temp;
	for (int x = str.length() - 1; x >= 0; x--)
	{
		temp.push_back(str[x]);
	}
	if (temp == str)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string PalindromeCreator(string str) 
{
	// First check if original input is palindrome
	if (palindromeCheck(str) && str.length() >= 3)
	{
		return "palindrome";
	}

	// Check if we can remove 1 character
	string temp;
	for (int x = 0; x < str.length(); x++)
	{
		temp = str;
		temp.erase(temp.begin() + x);
		if (palindromeCheck(temp) && temp.length() >= 3)
		{
			temp = str[x];
			return temp;
		}
	}

	// Check for removing 2 characters
	for (int x = 0; x < str.length() - 1; x++)
	{
		for (int y = x + 1; y < str.length(); y++)
		{
			temp = str;
			temp.erase(temp.begin() + x);
			temp.erase(temp.begin() + (y-1));
			if (palindromeCheck(temp) && temp.length() >= 3)
			{
				temp = str[x];
				temp += str[y];
				return temp;
			}
		}
	}

	return "not possible";
}

int main() 
{
	cout << PalindromeCreator("abjchba") << endl; // jc
	cout << PalindromeCreator("mmop") << endl; // not possible
	cout << PalindromeCreator("kjjjhjjj") << endl; // k
	cout << PalindromeCreator("lolkm") << endl; // km
	return 0;
}

