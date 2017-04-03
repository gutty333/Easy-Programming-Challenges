//  For this challenge you will be checking whether a number is even.
/*
have the function SimpleEvens(num) check whether every single number passed in parameter is even. If so, return the string true, otherwise return the string false. For example: if num is 4602225 your program should return the string false because 5 is not an even number.
*/

#include <iostream>
#include <string>
using namespace std;


/*
take the input number at the start and check if is even
If so continue breaking that number down by multiplying by .1
After each iteration check if is even
This will check all the digits of the input
*/


string SimpleEvens(long long num) 
{
	while (num > 0)
	{
		if (num % 2 == 0)
		{
			num *= .1;
		}
		else
		{
			return "false";
		}
	}
	return "true";
}

int main() 
{
	cout << SimpleEvens(4602225) << endl; // false
	cout << SimpleEvens(2222220222) << endl; // true
	cout << SimpleEvens(20864646452) << endl; // false
	return 0;

}