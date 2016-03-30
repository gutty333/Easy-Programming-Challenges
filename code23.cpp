// For this challenge you will be swapping the case of each character in the string.
// have the function SwapCase(str) take the str parameter and swap the case of each character. For example: if str is "Hello World" the output should be hELLO wORLD. Let numbers and symbols stay the way they are. 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string SwapCase(string str) {

	for (int x = 0; x < str.length(); x++)
	{
		if (isupper(str[x]))
		{
			str[x] = tolower(str[x]);
		}
		else
		{
			str[x] = toupper(str[x]);
		}
	}

	return str;
}

int main() {

	// keep this function call here
	cout << SwapCase("hello World") << endl; // HELLO wORLD
	cout << SwapCase("Hello-LOL") << endl; // hELLO-lol
	cout << SwapCase("Sup DUDE!!?") << endl; // sUP dude!!?
	return 0;

}