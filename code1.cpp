// Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. 

#include <iostream>
#include <string>
using namespace std;

string FirstReverse(string str) {

	/*string temp;
	int index = 0;
	int size = str.length()-1;

	for (size; size >= 0; size--)
	{
		temp.push_back(str[size]);
		index++;
	}

	return temp;*/


	// Better solution
	string temp = str;
	int index = 0;

	for (int x = temp.length()-1; x >= 0; x--)
	{
		str[index] = temp[x];
		index++;
	}
	return str;

}

int main() {

	// keep this function call here
	cout << FirstReverse("coderbyte");
	return 0;

}