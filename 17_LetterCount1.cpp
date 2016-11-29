//  For this challenge you will determine which word has the greatest number of repeated letters.
//  take the str parameter being passed and return the first word with the greatest number of repeated letters. For example: "Today, is the greatest day ever!" should return greatest because it has 2 e's (and 2 t's) and it comes before ever which also has 2 e's. If there are no words with repeating letters return -1. Words will be separated by spaces.

#include <iostream>
#include <string>
using namespace std;

string LetterCountI(string str) {

	int size = str.length();
	int count = 0, count2 = 0, high = 0, high2 = 0;
	int start = -1, end = 0;
	int temp, temp2;
	char letter;

	for (int x = 0; x < size; x++, end++)
	{
		if (start == -1) // find beginning of the word
		{
			start = x;
		}

		if (str[x] == ' ' || x == size-1)
		{
			// Safeguard in the case the correct word is at the end of the string
			if (end == size - 1)
			{
				end += 1;
			}

			for (int y = start; y < end; y++)
			{
				// selecting letter from word to compare
				letter = str[y];

				// Loop to check if letter repeats
				for (int z = start; z < end; z++)
				{
					if (y == z)
					{
						continue;
					}
					else if (letter == str[z])
					{
						count++;
					}
				}

				if (count)
				{
					count2++;
				}
				
				// Keep track of words with repeated letters
				if (count > high && count2 > high2)
				{
					high = count;
					high2 = count2;
					temp = start;
					temp2 = end;
				}

				count = 0;
			}

			// Keep track of words with THE MOST repeated letters
			if (count2 > high2)
			{
				high2 = count2;
				temp = start;
				temp2 = end;
			}
			count2 = 0;

			start = end+1;
		}
	}

	// Passing the first word with most repeated letters
	if (high > 0)
	{
		string repeated;

		for (temp; temp < temp2; temp++)
		{
			repeated.push_back(str[temp]);
		}

		return repeated;
	}
	else
	{
		return "-1";
	}
}

int main() {

	// keep this function call here
	cout << LetterCountI("Hello apple pie") << endl; // Hello
	cout << LetterCountI("Today, is the greatest day ever!") << endl; // greatest
	cout << LetterCountI("No words") << endl; // -1
	cout << LetterCountI("This is to test the last worrdd") << endl; // worrdd
	cout << LetterCountI("Ohhhmymymy now the first is theeeeh correct") << endl; // Ohhhmymymy
	cout << LetterCountI("The alpaca is amaaazzziinng but so is the golllldddden dog") << endl; // amazing
	return 0;

}