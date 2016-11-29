// For this challenge you will be determining the multiplicative persistence for a given number.
// have the function MultiplicativePersistence(num) take the num parameter being passed which will always be a positive integer and return its multiplicative persistence which is the number of times you must multiply the digits in num until you reach a single digit. For example: if num is 39 then your program should return 3 because 3 * 9 = 27 then 2 * 7 = 14 and finally 1 * 4 = 4 and you stop at 4. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int MultiplicativePersistence(int num) {

	if (num < 10)
	{
		return 0;
	}

	int count = 0;

	stringstream convert;
	convert << num;
	string temp = convert.str();
	int total, number;

	do
	{
		count++;
		total = 1;
		for (int x = 0; x < temp.length(); x++)
		{
			number = int(temp[x]) - 48;
			total *= number;
		}

		stringstream convert;
		convert << total;
		temp = convert.str();
	} while (total >= 10);

	return count;
}

int main() {

	// keep this function call here
	cout << MultiplicativePersistence(4) << endl; // 0
	cout << MultiplicativePersistence(25) << endl; // 2
	cout << MultiplicativePersistence(39) << endl; // 3
	return 0;

}