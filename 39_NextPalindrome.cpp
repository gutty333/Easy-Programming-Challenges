// For this challenge you will be determining the next largest palindrome.
// have the function NextPalindrome(num) take the num parameter being passed and return the next largest palindromic number. The input can be any positive integer. For example: if num is 24, then your program should return 33 because that is the next largest number that is a palindrome. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int NextPalindrome(int num)
{
	string temp;

	// Loop to check for palindrome as the number increases
	while (num)
	{
		num++; 
		
		// Convert to a string for comparison
		stringstream convert;
		convert << num;
		temp = convert.str();
		string temp2;

		for (int x = temp.length()-1; x >= 0; x--)
		{
			temp2.push_back(temp[x]);
		}

		if (temp2 == temp)
		{
			return num;
		}
	}
}

int main() 
{
	cout << NextPalindrome(24) << endl; // 33
	cout << NextPalindrome(43) << endl; // 44
	cout << NextPalindrome(2) << endl; // 3
	cout << NextPalindrome(180) << endl; // 181 
	cout << NextPalindrome(2335) << endl; // 2442
	cout << NextPalindrome(4352) << endl; // 4444
	cout << NextPalindrome(13242) << endl; // 13331
 	return 0;
}