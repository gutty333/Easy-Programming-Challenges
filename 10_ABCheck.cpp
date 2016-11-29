// For this challenge you will determine if two characters are separated a specific way in the string.
//  take the str parameter being passed and return the string true if the characters a and b are separated by exactly 3 places anywhere in the string at least once (ie. "lane borrowed" would result in true because there is exactly three characters between a and b). Otherwise return the string false. 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ABCheck(string str) {

	// We can apply the toLower method if we need to also worry about letter cases
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == 'a' || str[x] == 'b')
		{
			for (int y = 0; y < str.length(); y++)
			{
				// if we found an a char
				// check spacing of the b char
				if (str[x] == 'a') 
				{
					if (str[y] == 'b' && abs(x-y) == 4)
					{
						return "true"; // just following guidelines, better function type would be a bool
					}
				}
				else // check spacing of a char if we found b instead
				{
					if (str[y] == 'a' && abs(x - y) == 4)
					{
						return "true";
					}
				}
			}
		}
	}

	return "false";
	// Note, looking back at code this could have been better simplified into a single condition
	// if (string[x] == 'a' && and string[x+4] == 'b') return true it would also be vice versa for the b character
}

int main() {

	// keep this function call here
	cout << ABCheck("after badly") << endl; // false
	cout << ABCheck("Laura sobs") << endl; // true
	cout << ABCheck("hello this is birdad yeah typos") << endl; // true
	cout << ABCheck("dogs are awesome") << endl; // false
	return 0;

}