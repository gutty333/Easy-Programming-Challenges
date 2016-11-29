// For this challenge you will perform a bitwise operation on two binary numbers.
// have the function BitwiseOne(strArr) take the array of strings stored in strArr, which will only contain two strings of equal length that represent binary numbers, and return a final binary string that performed the bitwise OR operation on both strings. A bitwise OR operation places a 0 in the new string where there are zeroes in both binary strings, otherwise it places a 1 in that spot. For example: if strArr is ["1001", "0100"] then your program should return the string "1101" 

#include <iostream>
#include <string>
using namespace std;

string BitwiseOne(string strArr[]) {

	string temp = strArr[0];
	string temp2 = strArr[1];
	int size = temp.length();
	
	// New string to store the final binary string
	string temp3;
	
	for (int x = 0; x < size; x++)
	{
		if (temp[x] == '1' || temp2[x] == '1')
		{
			temp3.push_back('1');
		}
		else
		{
			temp3.push_back('0');
		}
	}

	return temp3;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "100", "000" };
	string B[] = { "00011", "01010" };
	string C[] = { "1001", "0100" };
	cout << BitwiseOne(A) << endl; // 100
	cout << BitwiseOne(B) << endl; // 01011
	cout << BitwiseOne(C) << endl; // 1101
	return 0;
}