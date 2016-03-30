// For this challenge you will be determining how many words a sentence contains.

#include <iostream>
#include <string>
using namespace std;

int WordCount(string str) {

	int count = 0;
	// This could be safeguard in the case that the string is all blank spaces
	// Just assuming here that there will be characters in the string
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == ' ')
			count++;
	}
	return count + 1;
}

int main() {

	// keep this function call here
	cout << WordCount("Never eat shredded wheat") << endl; // 4
	cout << WordCount("Hello World") << endl; // 2

	return 0;

}