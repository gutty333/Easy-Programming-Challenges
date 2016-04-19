// For this challenge you will traverse a string and determine if there is an equal amount of certain characters.
//  take the str parameter being passed and return the string true if there is an equal number of x's and o's, otherwise return the string false. Only these two letters will be entered in the string, no punctuation or numbers. For example: if str is "xooxxxxooxo" then the output should return false because there are 6 x's and 5 o's. 

#include <iostream>
#include <string>
using namespace std;

string ExOh(string str) {

	int xCount = 0, oCount = 0;

	// Simple iteration to keep count on how many characters are either x or o
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == 'x')
			xCount++;

		if (str[x] == 'o')
			oCount++;
	}

	if (xCount == oCount)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}

int main() {

	// keep this function call here
	cout << ExOh("x") << endl; // false
	cout << ExOh("xxooxxoo") << endl; //true
	cout << ExOh("xooxxo") << endl; // true
	return 0;

}
