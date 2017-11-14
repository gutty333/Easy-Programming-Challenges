//  For this challenge you will be parsing a command line string and counting its characters.
/*
have the function CommandLine(str) take the str parameter being passed which represents the parameters given to a command in an old PDP system. The parameters are alphanumeric tokens (without spaces) followed by an equal sign and by their corresponding value. Multiple parameters/value pairs can be placed on the command line with a single space between each pair. Parameter tokens and values cannot contain equal signs but values can contain spaces. The purpose of the function is to isolate the parameters and values to return a list of parameter and value lengths. It must provide its result in the same format and in the same order by replacing each entry (tokens and values) by its corresponding length.

For example, if str is: "SampleNumber=3234 provider=Dr. M. Welby patient=John Smith priority=High" then your function should return the string "12=4 8=12 7=10 8=4" because "SampleNumber" is a 12 character token with a 4 character value ("3234") followed by "provider" which is an 8 character token followed by a 12 character value ("Dr. M. Welby"), etc.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
One approach is to use the equal sings as a break point to split it into substrings

We can extract the first token by taking all characters prior to the first equal sign
We can extract the last value by taking all characters after the last equal sign

To collect the tokens and values in the middle we can reach a break point
check the characters prior that are not a space and those will result in our token
for the value we can subtract the current equal sign index by the start of the previous equal sign and the length of token 
*/

// method to collect the length of both the token and the value
void analyzeToken(int previousBreak, int currentBreak, string str, string& result)
{
	string temp;
	stringstream convert;

	// loop will backtrack from the breakpoint and collect the token
	// if we reach a space than a the token has been finalized
	for (int x = currentBreak-1; x >= 0; x--)
	{
		if (str[x] == ' ')
		{
			break;
		}
		else
		{
			temp.push_back(str[x]);
		}
	}

	// get the length of the current token
	int currentTokenLength = temp.length();

	if (previousBreak != 0)
	{
		// get the length of the previous value
		int previousValueLength = currentBreak - currentTokenLength - previousBreak -2;

		// converting the value length to string and adding to our final result
		convert << previousValueLength;
		result+=convert.str();
		result.push_back(' ');
		convert.str("");
	}
	
	// converting the token length to a string
	convert << currentTokenLength;
	result+=convert.str();
	result.push_back('=');
}

string CommandLine(string str)
{
	string result="";

	// setting the break points
	int breakPoint1 = str.find('=');
	int breakPoint2 = 0;

	// first step to analyze the first token
	analyzeToken(breakPoint2, breakPoint1, str, result);
	

	// loop to continue to check the string base on the amount of tokens found
	while (str.find('=', breakPoint1 + 1) >= 0 && str.find('=', breakPoint1 + 1) <= str.length() - 1)
	{
		// updating the break points based on the current string
		breakPoint2 = breakPoint1;
		breakPoint1 = str.find('=',breakPoint1+1);

		analyzeToken(breakPoint2, breakPoint1, str, result);
	}

	// last step to analyze the last value if any are found
	string temp ="";
	for (int x = breakPoint1 + 1; x < str.length(); x++)
	{
		temp.push_back(str[x]);
	}

	// getting the length and converting back to a string
	int valueLength = temp.length();
	stringstream convert;
	convert << valueLength;
	result+=convert.str();

	return result;
}

int main() 
{
	cout << CommandLine("SampleNumber=3234 provider=Dr. M. Welby patient=John Smith priority=High") << endl; // 12=4 8=12 7=10 8=4
	cout << CommandLine("letters=A B Z T numbers=1 2 26 20 combine=true") << endl; // 7=7 7=9 7=4
	cout << CommandLine("a=3 b=4 a=23 b=a 4 23 c=") << endl; // 1=1 1=1 1=2 1=6 1=0 

	return 0;
}