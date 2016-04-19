//  For this challenge you will divide two numbers and return them in a certain format.
// have the function DivisionStringified(num1,num2) take both parameters being passed, divide num1 by num2, and return the result as a string with properly formatted commas. If an answer is only 3 digits long, return the number with no commas (ie. 2 / 3 should output "1"). For example: if num1 is 123456789 and num2 is 10000 the output should be "12,346". 

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

string DivisionStringified(int num1, int num2) {

	int result = round(double(num1) / num2);
	
	// Converting a number to string using sstream
	// the other modern way is to use to_string(result);
	stringstream convert;
	convert << result;
	string temp = convert.str();
	string temp2 = temp;
	int count = 0;

	for (int x = temp.length() - 1; x >= 0; x--)
	{
		// Analyze how large the number is
		// If 3 digits than add a comma
		if (count == 3)
		{
			temp2.insert(x+1, ",");

			count = 1;
		}
		else
		{
			count++;
		}
	}
  
	return temp2;
}

int main() {

	// keep this function call here
	cout << DivisionStringified(5, 2) << endl; // 3
	cout << DivisionStringified(6874, 67) << endl; // 103
	cout << DivisionStringified(123456789, 10000) << endl;  // 12,346
	cout << DivisionStringified(123456789, 1) << endl; // 123,456,789
	cout << DivisionStringified(12456789, 1) << endl; // 12,456,789
	return 0;

}