// For this challenge you will determine if a string is written the same way forward and backwards. Palindrome

#include <iostream>
#include <string>
using namespace std;

string Palindrome(string str) {

	string temp;

	for (int y = 0; y < str.length(); y++)
	{
		if (str[y] != ' ')
		{
			temp.push_back(str[y]);
		}
	}
	int size = temp.length() - 1;

	// Compare the new string by analyzing the characters from the front and back
	for (int x = 0; x < temp.length(); x++)
	{
		if (temp[x] != temp[size])
		{
			return "false";
		}
		size--;
	}

	return "true";
}

int main() {

	// keep this function call here
	cout << Palindrome("racecar") << endl; // true
	cout << Palindrome("eye") << endl; // true
	cout << Palindrome("what is this") << endl; // false
	cout << Palindrome("never odd or even") << endl; // true

	return 0;

}