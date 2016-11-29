// Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. 

#include <iostream>
#include <string>
using namespace std;

string FirstReverse(string str) {
	// Set placeholder string value to copy the original
	string temp = str;
	int index = 0;

	// Traverse the placeholder value backwards
	// At the same time edit the original
	for (int x = temp.length()-1; x >= 0; x--)
	{
		str[index] = temp[x];
		index++;
	}
	return str;
}

int main() 
{
	cout << FirstReverse("coderbyte");
	return 0;
}