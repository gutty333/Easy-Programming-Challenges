// For this challenge you will perform a bitwise operation on two binary numbers.
// have the function BitwiseTwo(strArr) take the array of strings stored in strArr, which will only contain two strings of equal length that represent binary numbers, and return a final binary string that performed the bitwise AND operation on both strings. A bitwise AND operation places a 1 in the new string where there is a 1 in both locations in the binary strings, otherwise it places a 0 in that spot. For example: if strArr is ["10111", "01101"] then your program should return the string "00101" 

#include <iostream>
#include <string>
using namespace std;

string BitwiseTwo(string strArr[]) 
{
	string result;

	for (int x = 0; x < strArr[0].length(); x++)
	{
		if (strArr[0][x] == '1'&& strArr[1][x] == '1')
		{
			result.push_back('1');
		}
		else
		{
			result.push_back('0');
		}
	}

	return result;
}

int main() 
{
	string A[] = { "10111", "01101" };
	string B[] = { "10100", "11100" };
	cout << BitwiseTwo(A) << endl; // 00101
	cout << BitwiseTwo(B) << endl; // 10100
	return 0;
}