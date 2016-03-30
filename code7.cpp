// For this challenge you will be determining whether or not certain characters are in correct positions.
//The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. The string will not be empty and will have at least one letter. 


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string SimpleSymbols(string str) {

	bool valid = false;
	string temp;

	// eliminate spaces from the string
	for (int y = 0; y < str.length(); y++)
	{
		if (str[y] != ' ')
		{
			temp.push_back(str[y]);
		}
	}

	cout << temp << endl;
	for (int x = 0; x < temp.length()-1; x++)
	{
		if (x == 0 && !isalpha(temp[x]))
		{
			continue;
		}
		else if (x == 0 && isalpha(temp[x]))
		{
			break;
		}
		else if (isalpha(temp[x]) && temp[x-1] == '+' && temp[x + 1] == '+')
		{
			valid = true;
		}
		else
		{
			break;
		}
	}

	if (valid)
	{
		str = "true";
	}
	else
	{
		str = "false";
	}

	return str;

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