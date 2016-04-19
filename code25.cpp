// For this challenge you will determine the third largest string within an array.
// have the function ThirdGreatest(strArr) take the array of strings stored in strArr and return the third largest word within in. So for example: if strArr is ["hello", "world", "before", "all"] your output should be world because "before" is 6 letters long, and "hello" and "world" are both 5, but the output should be world because it appeared as the last 5 letter word in the array. If strArr was ["hello", "world", "after", "all"] the output should be after because the first three words are all 5 letters long, so return the last one. The array will have at least three strings and each string will only contain letters. 

#include <iostream>
#include <string>
using namespace std;

string ThirdGreatest(string strArr[], int size) {

	int temp, temp2, temp3, index, index2, index3;
	temp = temp2 = temp3 = 0;

	// Find the largest word in the string
	for (int y = 0; y < size; y++)
	{
		if (strArr[y].length() > temp)
		{
			temp = strArr[y].length();
			index = y;
		}
	}
	// Find the second largest word in the string
	for (int z = 0; z < size; z++)
	{
		if (strArr[z].length() >= temp2 && z != index)
		{
			temp2 = strArr[z].length();
			index2 = z;
		}
	}
	// Find the third largest word
	for (int x = 0; x < size; x++)
	{
		if (strArr[x].length() >= temp3 && x != index && x != index2)
		{
			temp3 = strArr[x].length();
			index3 = x;
		}
	}

	if (temp2 == temp3)
	{
		return strArr[index2];
	}
	else
	{
		return strArr[index3];
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "coder", "byte", "code" };
	string B[] = { "abc", "defg", "z", "hijk" };
	string C[] = { "hello", "world", "before", "all" };
	string D[] = { "hello", "world", "after", "all" };
	cout << ThirdGreatest(A,sizeof(A)/sizeof(A[0])) << endl; // code
	cout << ThirdGreatest(B, sizeof(B) / sizeof(B[0])) << endl; // abc
	cout << ThirdGreatest(C, sizeof(C) / sizeof(C[0])) << endl; // word
	cout << ThirdGreatest(D, sizeof(D) / sizeof(D[0])) << endl; // after
	return 0;

}