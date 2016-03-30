//  For this challenge you will traverse a string searching for all the numbers and then you will add them up.
// have the function NumberSearch(str) take the str parameter, search for all the numbers in the string, add them together, then return that final number. For example: if str is "88Hello 3World!" the output should be 91. You will have to differentiate between single digit numbers and multiple digit numbers like in the example above. So "55Hello" and "5Hello 5" should return two different answers. Each string will contain at least one letter or symbol. 

#include <iostream>
#include <string>
using namespace std;


int NumberAddition(string str) {

	int total = 0;
	string temp;

	for (int x = 0; x < str.length(); x++)
	{
		if (isdigit(str[x]))
		{
			temp.push_back(str[x]);
			for (int y = x + 1; y < str.length(); y++)
			{
				if (y >= str.length())
				{
					break;
				}
				else if (isdigit(str[y]))
				{
					temp.push_back(str[y]);
					x = y;
				}
				else
				{
					break;
				}
			}

			total += stoi(temp);
			temp.clear();
		}
	}

	return total;
}

int main() {

	// keep this function call here
	cout << NumberAddition("75Number9") << endl; // 84
	cout << NumberAddition("10 2One Number*1*") << endl; // 13
	cout << NumberAddition("88Hello 3World!") << endl; // 91
	cout << NumberAddition("55Hello") << endl; // 55
	cout << NumberAddition("5Hello 5") << endl; // 10
	return 0;

}
