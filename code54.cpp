// For this challenge you will be balancing a scale with weights on it.
/*
have the function ScaleBalancing(strArr) read strArr which will contain two elements, the first being the two positive integer weights on a balance scale (left and right sides) and the second element being a list of available weights as positive integers. Your goal is to determine if you can balance the scale by using the least amount of weights from the list, but using at most only 2 weights. For example: if strArr is ["[5, 9]", "[1, 2, 6, 7]"] then this means there is a balance scale with a weight of 5 on the left side and 9 on the right side. It is in fact possible to balance this scale by adding a 6 to the left side from the list of weights and adding a 2 to the right side. Both scales will now equal 11 and they are perfectly balanced. Your program should return a common separated string of the weights that were used from the list in ascending order, so for this example your program should return the string 2,6

There will only ever be one unique solution and the list of available weights will not be empty. It is also possible to add two weights to only one side of the scale to balance it. If it is not possible to balance the scale then your program should return the string not possible.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Find out which side is the highest

Create a loop that will analyze if any of the weights from the list help make the lowest side equal to the highest
Check all possible solutions
Order the numbers in ascending order

In the case that you need to analyze both sides
Bounce back and forth in trying to match the highest value
For example if the lowest side now becomes 11 and the highest side was 9, search the list and check if a weight can be found to balance the scale
*/

int sum(vector <int> list)
{
	int total = 0;
	for (int x = 0; x < list.size(); x++)
	{
		total += list[x];
	}
	return total;
}

// Function to order the value and convert back to a string
string convertOrder(int low, int high)
{
	int temp;
	if (low > high)
	{
		temp = low;
		low = high;
		high = temp;
	}

	string temp2 = "";
	stringstream convert;
	convert << low;
	temp2 += convert.str();
	temp2 += ',';
	convert.str(string());
	convert.clear();
	convert << high;
	temp2 += convert.str();
	return temp2;
}

string ScaleBalancing(string strArr[], int size) 
{
	int low, high;
	vector <int> list;

	// Loop to delete unwanted characters
	char trash[] = " []";
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			strArr[x].erase(remove(strArr[x].begin(), strArr[x].end(), trash[y]), strArr[x].end());
		}
	}

	// Loop to take the string chars and convert to int number for easier manipulation
	string temp = "";
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < strArr[x].length(); y++)
		{
			if (y == strArr[x].length() - 1 || strArr[x][y] == ',')
			{
				if (y == strArr[x].length() - 1)
				{
					temp += strArr[x][y];
				}
				int num;
				istringstream(temp) >> num;
				list.push_back(num);
				temp.clear();
			}
			else
			{
				temp += strArr[x][y];
			}

			if (x == 0 && list.size() == 2) // Condition to get the 2 weights on the scale
			{
				high = list.back();
				list.pop_back();
				low = list.back();
				list.pop_back();
			}
		}
	}

	if (high < low) // Checking which side of the scale has the higher weight
	{
		list.push_back(high);
		high = low;
		low = list.back();
		list.pop_back();
		if (low == high)
		{
			return "perfect balance";
		}
	}

	for (int x = 0; x < list.size(); x++) // Loop in the case only one side needs a single weight for balance
	{
		if (low + list[x] == high)
		{
			stringstream convert;
			convert << list[x];
			return convert.str();
		}
	}
	for (int x = 0; x < list.size(); x++) // Loop in the case only one side needs 2 weights for balance
	{
		for (int y = x + 1; y < list.size(); y++)
		{
			if (list[x] + list[y] + low == high)
			{
				return convertOrder(list[x], list[y]);
			}
		}
	}
	int total = 0;
	for (int x = 0; x < list.size(); x++) // Loop in the case both sides needs a weight for balance
	{
		total += list[x] + high;
		for (int y = 0; y < list.size(); y++)
		{
			if (x == y)
			{
				continue;
			}
			if (list[y] + low == total)
			{
				return convertOrder(list[x], list[y]);
			}
		}
		total = 0;
	}

	return "not possible";
}

int main() 
{
	string A[] = { "[5, 9]", "[1, 2, 6, 7]" };
	string B[] = { "[3, 4]", "[1, 2, 7, 7]" };
	string C[] = { "[13, 4]", "[1, 2, 3, 6, 14]" };
	cout << ScaleBalancing(A, sizeof(A)/sizeof(A[0])) << endl; // 2,6
	cout << ScaleBalancing(B, sizeof(B) / sizeof(B[0])) << endl; // 1
	cout << ScaleBalancing(C, sizeof(C) / sizeof(C[0])) << endl; // 3,6
	return 0;

}