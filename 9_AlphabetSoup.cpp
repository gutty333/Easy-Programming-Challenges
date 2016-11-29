//  For this challenge you will be sorting characters in a string.
// take the str string parameter being passed and return the string with the letters in alphabetical order (ie. hello becomes ehllo). Assume numbers and punctuation symbols will not be included in the string. 

#include <iostream>
#include <string>
using namespace std;

string AlphabetSoup(string str) {

	bool swap;
	char temp;

	// Doing a bubble sort to implementation to compare all the characters
	do
	{
		swap = false;

		for (int x = 0; x < str.length() - 1; x++)
		{
			if (str[x] > str[x + 1])
			{
				temp = str[x];
				str[x] = str[x + 1];
				str[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	// Removing spaces
	string temp2;
	for (int y = 0; y < str.length(); y++)
	{
		if (str[y] != ' ')
		{
			temp2.push_back(str[y]);
		}
	}

	return temp2;
}

int main() {

	// keep this function call here
	cout << AlphabetSoup("test") << endl;
	cout << AlphabetSoup("hello") << endl;
	cout << AlphabetSoup("wow this is radical the a should be first") << endl;
	return 0;

}