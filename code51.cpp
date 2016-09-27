// For this challenge you will be converting a string of Roman numerals.
// have the function BasicRomanNumerals(str) read str which will be a string of Roman numerals. The numerals being used are: I for 1, V for 5, X for 10, L for 50, C for 100, D for 500 and M for 1000. In Roman numerals, to create a number like 11 you simply add a 1 after the 10, so you get XI. But to create a number like 19, you use the subtraction notation which is to add an I before an X or V (or add an X before an L or C). So 19 in Roman numerals is XIX.  The goal of your program is to return the decimal equivalent of the Roman numeral given.For example : if str is "XXIV" your program should return 24

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int convert(char val)
{
	switch (val)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
}

int BasicRomanNumerals(string str) 
{
	vector <int> list;
	int total = 0;

	// Loop to get number values of each symbol
	for (int x = 0; x < str.length(); x++)
	{
		list.push_back(convert(str[x]));
	}

	// Loop to perform the correct conversion
	int temp = 0;
	for (int x = 0; x < list.size()-1; x++)
	{
		if (list[x] < list[x + 1])
		{
			total += list[x + 1] - list[x];
			x++;
			if (x + 1 == list.size() - 1)
			{

				total += list[x + 1];
			}
		}
		else
		{
			total += list[x];
			if (x + 1 == list.size() - 1)
			{
				total += list[x + 1];
			}
		}
	}

	return total;
}

int main()
{
	cout << BasicRomanNumerals("XXIV") << endl; // 24
	cout << BasicRomanNumerals("XV") << endl; // 15
	cout << BasicRomanNumerals("IV") << endl; // 4
	cout << BasicRomanNumerals("XLVI") << endl; // 46
	cout << BasicRomanNumerals("XCV") << endl; // 95
	return 0;

}