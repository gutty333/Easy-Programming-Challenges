// For this challenge you will determine the difference between two strings.
// have the function HammingDistance(strArr) take the array of strings stored in strArr, which will only contain two strings of equal length and return the Hamming distance between them. The Hamming distance is the number of positions where the corresponding characters are different. For example: if strArr is ["coder", "codec"] then your program should return 1. The string will always be of equal length and will only contain lowercase characters from the alphabet and numbers. 

#include <iostream>
#include <string>
using namespace std;

int HammingDistance(string strArr[]) {

	string temp = strArr[0];
	string temp2 = strArr[1];
	
	int count = 0;
	for (int x = 0; x < temp.length(); x++)
	{
		if (temp[x] != temp2[x])
		{
			count++;
		}
	}

	return count;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "10011", "10100" };
	string B[] = { "helloworld", "worldhello" };
	string C[] = { "coder", "codec" };
	cout << HammingDistance(A) << endl; // 3
	cout << HammingDistance(B) << endl; // 8
	cout << HammingDistance(C) << endl; // 1
	return 0;

}