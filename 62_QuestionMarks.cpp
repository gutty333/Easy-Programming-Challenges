// For this challenge you will be determining if a string follows a particular pattern.
/*
have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, letters, and question marks, and check if there are exactly 3 question marks between every pair of two numbers that add up to 10. If so, then your program should return the string true, otherwise it should return the string false. If there aren't any two numbers that add up to 10 in the string, then your program should return false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are exactly 3 question marks between 6 and 4, and 3 question marks between 5 and 5 at the end of the string.
*/

#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::cin;
using std::endl;

/*
locate any digits
analyze if the pair of number add up to 10
Keep track of their index if they do
Check to see if there are exactly 3 question marks in between them
*/

string QuestionsMarks(string str) 
{
	bool correctPair = false;

	for (int x = 0; x < str.size()-1; x++)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			for (int y = x + 1; y < str.size(); y++)
			{
				if (str[y] >= '0' && str[y] <= '9')
				{
					int total = int(str[x]) - 48 + (int(str[y]) - 48);

					if (total == 10)
					{
						correctPair = true;

						// Count number of question marks
						int count = 0;
						for (int i = x; i < y; i++)
						{
							if (str[i] == '?')
							{
								count++;
							}
						}


						if (count != 3)
						{
							return "false";
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}

	if (correctPair)
	{
		return "true";
	}
	else
	{
		return "false";
	}
	
}

int main() 
{
	cout << QuestionsMarks("arrb6???4xxbl5???eee5") << endl; // true
	cout << QuestionsMarks("acc?7??sss?3rr1??????5") << endl; // true
	cout << QuestionsMarks("aa6?9") << endl; // false
	return 0;
}