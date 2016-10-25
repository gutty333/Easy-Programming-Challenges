// For this challenge you will be searching for a set of numbers in a string.

// have the function ThreeNumbers(str) take the str parameter being passed and determine if exactly three unique, single-digit integers occur within each word in the string. The integers can appear anywhere in the word, but they cannot be all adjacent to each other. If every word contains exactly 3 unique integers somewhere within it, then return the string true, otherwise return the string false. For example: if str is "2hell6o3 wor6l7d2" then your program should return "true" but if the string is "hell268o w6or2l4d" then your program should return "false" because all the integers are adjacent to each other in the first word.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Check each word
analyze if the words have 3 digits
make sure the digits are not adjacent
also make sure the digits are unique
*/

string ThreeNumbers(string str) 
{
	string temp;
	for (int x = 0; x < str.length(); x++)
	{
		temp += str[x];
		int count=0;
		vector <vector <int> > list(3);

		// Condition to determine when we reach the end of a word
		if (str[x] == ' ' || x == str.length()-1)  
		{
			for (int y = 0; y < temp.length(); y++)
			{
				if (temp[y] >= '0' && temp[y] <= '9')
				{
					list[count].push_back(temp[y]); // Store the digit
					list[count].push_back(y); // Store the index of that digit
					count++;

					// Condition to verify that each word only has 3 digits
					if (count > 3)
					{
						return "false";
					}
				}
			}

			// Condition to check that all the digits are not adjacent
			// Also checking that the 3 digits are unique
			if (list[0][1] + 1 == list[1][1] && list[1][1] + 1 == list[2][1])
			{
				return "false";
			}
			else if (list[0][0] == list[1][0] || list[0][0] == list[2][0] || list[1][0] == list[2][0])
			{
				return "false";
			}

			temp.clear();
		}
	}

	return "true";
}

int main() 
{
	cout << ThreeNumbers("2hell6o3 wor6l7d2") << endl; // true
	cout << ThreeNumbers("2a3b5 w1o2rl3d g1gg92") << endl; // true
	cout << ThreeNumbers("21aa3a ggg4g4g6ggg") << endl; // false
	return 0;

}