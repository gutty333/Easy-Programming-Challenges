// For this challenge you will find the first non-repeating character in a string.
// have the function NonrepeatingCharacter(str) take the str parameter being passed, which will contain only alphabetic characters and spaces, and return the first non-repeating character. For example: if str is "agettkgaeee" then your program should return k. The string will always contain at least one character and there will always be at least one non-repeating character. 

#include <iostream>
#include <string>
using namespace std;

// Search function to see if characters repeat
bool search(string str,char val, int pos)
{
	for (int x = 0; x < str.length(); x++)
	{
		if (x == pos)
		{
			continue;
		}

		if (str[x] == val)
		{
			return true;
		}
	}
	return false;
}

char NonrepeatingCharacter(string str) 
{

	int index = str.length();
	char current;

	// traverse the string and check if the characters repeat
	for (int x = 0; x < str.length(); x++)
	{
		if (!search(str, str[x], x) && x < index)
		{
			index = x;
			current = str[x];
		}
	}

	return current;
}

int main() 
{
	cout << NonrepeatingCharacter("agettkgaeee") << endl; // k
	cout << NonrepeatingCharacter("abcdef") << endl; // a
	cout << NonrepeatingCharacter("hello world hi hey") << endl; // w
	return 0;

}