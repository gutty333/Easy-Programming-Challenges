// For this challenge you will be determining whether or not certain characters are in correct positions.
//The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. The string will not be empty and will have at least one letter. 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string SimpleSymbols(string str) {

	bool valid;
	string temp;

	// eliminate spaces and non letters from the string
	// We only care about the symbols and letters to determine correct positions
	for (int y = 0; y < str.length(); y++)
	{
		if ((str[y] >= 'A' && str[y] <= 'Z') || (str[y] >= 'a' && str[y] <= 'z') || str[y] == '=' || str[y] == '+')
		{
			temp.push_back(str[y]);
		}
	}

	if (temp.length() > 1)
	{
		valid = true;
	}
	else
	{
		valid = false;
	}

	for (int x = 0; x < temp.length()-1 && valid; x++)
	{
		valid = false;
		// Checking the first character of the string
		if (x == 0 && !isalpha(temp[x]))
		{
			valid = true;
		}
		// In the case that the starting character is a letter it will result in false
		else if (x == 0 && isalpha(temp[x]))
		{
			break;
		}
		// If the current character is a symbol ignore and continue searching for letters
		else if (!isalpha(temp[x]))
		{
			valid = true;
		}
		// If a letter is found analyze that the rules are followed
		else if (isalpha(temp[x]) && temp[x-1] == '+' && temp[x + 1] == '+')
		{
			valid = true;
		}
	}

	if (valid)
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
	cout << SimpleSymbols("+d += 3 = +s +") << endl; // true
	cout << SimpleSymbols("f++d+") << endl; //  false
	cout << SimpleSymbols("+d===+a+") << endl; //  false
	cout << SimpleSymbols("+z+z+z+") << endl; //  true
	cout << SimpleSymbols("2+a+a+") << endl; //  true
	cout << SimpleSymbols("+z+z+==+a+") << endl; //  true
	cout << SimpleSymbols("==a+") << endl; //  false
	cout << SimpleSymbols("a") << endl; //  false
	return 0;
}