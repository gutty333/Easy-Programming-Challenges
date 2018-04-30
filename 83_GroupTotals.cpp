// For this challenge you will be adding values from key, value pairs.
/*
have the function GroupTotals(strArr) read in the strArr parameter containing key:value pairs where the key is a string and the value is an integer. Your program should return a string with new key:value pairs separated by a comma such that each key appears only once with the total values summed up.
For example: if strArr is ["B:-1", "A:1", "B:3", "A:5"] then your program should return the string A:6,B:2.

Your final output string should return the keys in alphabetical order. Exclude keys that have a value of 0 after being summed up.
*/

#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

/*
we traverse the string array
store key value pairs into a hash table
if key is already in our table we sum up the values
else create a new key value pair in the table
lastly we output the result, ignore any keys with a value of 0
*/
string GroupTotals(string strArr[], int size) 
{
	// our hast table
	map <string, int> table;

	// traversing the string array to extract the key value pairs
	for (int x = 0; x < size; x++)
	{
		string key;
		int value;

		// extracting the key
		for (int y = 0; y < strArr[x].length(); y++)
		{
			// breakpoint
			if (strArr[x][y] == ':')
			{
				break;
			}
			else
			{
				key += strArr[x][y];
			}
		}

		// extracting the value
		string num;
		for (int y = strArr[x].find(':') + 1; y < strArr[x].length(); y++)
		{
			num += strArr[x][y];
		}

		istringstream convert(num);
		convert >> value;

		// conditions to check the new data gathered
		// if the pair is new we just add it to our table
		// else we perform simple addition to the already existing pair
		if (table.count(key) == 0)
		{
			table[key] = value;
		}
		else
		{
			table[key] += value;
		}
	}

	// gathering our result
	string result;

	for (auto current = table.begin(); current != table.end(); current++)
	{
		// we ignore any pairs that have a value of 0
		if (current->second != 0)
		{
			ostringstream convert; 
			convert << current->second;
			string currentResult = current->first + ":" + convert.str();
			result += currentResult + ",";
		}
	}

	result.pop_back(); // remove last comma
	return result;
}

int main()
{
	string A[] = { "B:-1", "A:1", "B:3", "A:5" };
	string B[] = { "X:-1", "Y:1", "X:-4", "B:3", "X:5" };
	string C[] = { "Z:0", "A:-1" };
	
	cout << GroupTotals(A, sizeof(A) / sizeof(A[0])) << endl; //  A:6,B:2
	cout << GroupTotals(B, sizeof(B) / sizeof(B[0])) << endl; //  B:3,Y:1
	cout << GroupTotals(C, sizeof(C) / sizeof(C[0])) << endl; //  A:-1
	return 0;
}