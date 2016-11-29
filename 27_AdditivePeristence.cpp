// For this challenge you will be determining the additive persistence for a given number.
// have the function AdditivePersistence(num) take the num parameter being passed which will always be a positive integer and return its additive persistence which is the number of times you must add the digits in num until you reach a single digit. For example: if num is 2718 then your program should return 2 because 2 + 7 + 1 + 8 = 18 and 1 + 8 = 9 and you stop at 9. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int AdditivePersistence(int num) {

	int count = 0;

	if (num < 10)
	{
		return 0;
	}

	// Convert the number to a string for traversing
	stringstream convert;
	convert << num;
	string temp = convert.str();
	int total, number;
	
	do
	{
		total = 0;
		count++; // Keeps track of the count

		for (int x = 0; x < temp.length(); x++)
		{
			// Convert string character back to int for calculation
			number = int(temp[x]) - 48;
			total += number;
		}

		// Converting back to number
		stringstream convert;
		convert << total;
		temp = convert.str();
	} while (total >= 10);
	
	return count;
}

int main() {

	// keep this function call here
	cout << AdditivePersistence(4) << endl; // 0
	cout << AdditivePersistence(19) << endl; // 2
	cout << AdditivePersistence(2718) << endl; // 2
	cout << AdditivePersistence(199) << endl; // 3
	return 0;

}