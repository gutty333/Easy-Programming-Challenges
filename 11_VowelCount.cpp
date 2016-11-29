// For this challenge you will be counting all the vowels in a string.
//  take the str string parameter being passed and return the number of vowels the string contains (ie. "All cows eat grass" would return 5). Do not count y as a vowel for this challenge. 

#include <iostream>
#include <string>
using namespace std;

int VowelCount(string str) {

	int count = 0;

	for (int x = 0; x < str.length(); x++)
	{
		if (tolower(str[x]) == 'a' || tolower(str[x]) == 'e' || tolower(str[x]) == 'i' || (str[x]) == 'o' || tolower(str[x]) == 'u')
		{
			count++;
		}
	}
	return count;
}

int main() {

	// keep this function call here
	cout << VowelCount("hello") << endl; // 2
	cout << VowelCount("hello world") << endl; // 3
	cout << VowelCount("All cows eat grass") << endl; // 5
	return 0;

}