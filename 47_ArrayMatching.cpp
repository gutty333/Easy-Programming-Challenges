// For this challenge you will add elements from two arrays in a particular order.
// have the function ArrayMatching(strArr) read the array of strings stored in strArr which will contain only two elements, both of which will represent an array of positive integers. For example: if strArr is ["[1, 2, 5, 6]", "[5, 2, 8, 11]"], then both elements in the input represent two integer arrays, and your goal for this challenge is to add the elements in corresponding locations from both arrays. For the example input, your program should do the following additions: [(1 + 5), (2 + 2), (5 + 8), (6 + 11)] which then equals [6, 4, 13, 17]. Your program should finally return this resulting array in a string format with each element separated by a hyphen: 6-4-13-17. If the two arrays do not have the same amount of elements, then simply append the remaining elements onto the new array(example shown below).Both arrays will be in the format : [e1, e2, e3, ...] where at least one element will exist in each array.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string ArrayMatching(string strArr[], int size) 
{
	int length = 0, length2 = 100 * 100, total, high;
	vector <vector<int> > list(size);
	vector <int> newArray;
	string result;

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			if (strArr[row][col] == '[' || strArr[row][col] == ' ') // Removing unnecessary characters
			{
				strArr[row].erase(strArr[row].begin() + col);
			}
		}

		// Passing our string values to a new int list
		// This will make it easier for calculation and other requirements
		string temp;
		for (int x = 0; x < strArr[row].length(); x++)
		{
			if (strArr[row][x] == ',' || x == strArr[row].length() - 1)
			{
				int num;
				istringstream(temp) >> num;
				list[row].push_back(num);
				temp.clear();
			}
			else
			{
				temp.push_back(strArr[row][x]);
			}
		}

		// Condition to keep track of the largest and shortest sub array
		if (list[row].size() > length) 
		{
			length = list[row].size();
			high = row; // will determine from which sub-array we need to append if need to
		}
		if (list[row].size() < length2)
		{
			length2 = list[row].size();
		}
	}

	// Loop to perform the calculation
	for (int x = 0; x < length2; x++)
	{
		total = 0;
		total += list[0][x];
		total += list[1][x];
		newArray.push_back(total);
	}

	// Condition to check if we need to append remaining elements
	if (newArray.size() < length)
	{
		for (int x = length2; x < length; x++)
		{
			newArray.push_back(list[high][x]);
		}
	}
	
	// Loop for formatting
	for (int x = 0; x < newArray.size(); x++)
	{
		stringstream convert;
		convert << newArray[x];
		result += convert.str();
		if (x != newArray.size() - 1)
		{
			result += "-";
		}
	}
	return result;
}

int main() 
{
	string A[] = { "[1, 2, 5, 6]", "[5, 2, 8, 11]" };
	string B[] = { "[5, 2, 3]", "[2, 2, 3, 10, 6]" };
	cout << ArrayMatching(A, sizeof(A) / sizeof(A[0])) << endl; // 6-4-13-17
	cout << ArrayMatching(B, sizeof(B) / sizeof(B[0])) << endl; // 7-4-6-10-6
	return 0;

}