// For this challenge you will be reversing a binary string.
// have the function BinaryReversal(str) take the str parameter being passed, which will be a positive integer, take its binary representation, reverse that string of bits, and then finally return the new reversed string in decimal form. For example: if str is "47" then the binary version of this integer is 00101111. Your program should reverse this binary string which then becomes: 11110100 and then finally return the decimal version of this string, which is 244. 

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

int BinaryReversal(string str) 
{
	int num;
	istringstream(str) >> num;

	// converting to a binary
	str = "";
	bool binary = false;
	while (!binary)
	{
		stringstream convert;
		convert << num % 2;
		str += convert.str();
		num /= 2;

		if (num == 0 && str.length() % 8 == 0) // Condition to make sure the result is 8 bits
		{
			binary = true;
		}
	}

	// Converting back to a decimal
	int total = 0;
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '1')
		{
			total += pow(2, (str.length() - 1) - x);
		}
	}

	return total;
}

int main()
{
	cout << BinaryReversal("47") << endl; // 244
	cout << BinaryReversal("4567") << endl; // 60296
	cout << BinaryReversal("12345") << endl; // 39948
	cout << BinaryReversal("10156") << endl; // 13796

	return 0;
}