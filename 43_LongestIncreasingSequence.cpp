// For this challenge you will compute the length of the longest increasing subsequence.
// have the function LongestIncreasingSequence(arr) take the array of positive integers stored in arr and return the length of the longest increasing subsequence (LIS). A LIS is a subset of the original list where the numbers are in sorted order, from lowest to highest, and are in increasing order. The sequence does not need to be contiguous or unique, and there can be several different subsequences. For example: if arr is [4, 3, 5, 1, 6] then a possible LIS is[3, 5, 6], and another is[1, 6].For this input, your program should return 3 because that is the length of the longest increasing subsequence.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Still in progress

// Function to find the next best increasing number in the sequence
// Will determine the next number based on the difference with the last number in the sequence
//void nextVal(int arr[], int size, int lastNum, int& index, vector <int>& list)
//{
//	int difference = 100 * 100;
//	for (int x = index; x < size; x++)
//	{
//		if (arr[x] > lastNum && arr[x]-lastNum < difference)
//		{
//			difference = arr[x] - lastNum;
//			index = x;
//		}
//	}
//
//	// Condition to check if any increasing number was found
//	if (difference != 100 * 100)
//	{
//		list.push_back(arr[index]);
//	}
//}
//// 10, 12, 4, 6, 100, 2, 56, 34, 79 
//// 10, 22, 9, 33, 21, 50, 41, 60, 22, 68, 90
//int LongestIncreasingSequence(int arr[], int size) 
//{
//	int index, length = 0;
//	vector <int> list;
//	bool found;
//
//	// Loop to find increasing sequences
//	for (int x = 0; x < size; x++)
//	{
//		list.push_back(arr[x]);
//		// Loop to check the increasing sequence from this value
//		for (int y = x + 1; y < size; y++)
//		{
//			nextVal(arr, size, list.back(), y, list);
//		}
//
//		// Keep track of the longest increasing sequence
//		if (list.size() > length)
//		{
//			length = list.size();
//		}
//
//		// Clear the list, to analyze other combinations
//		list.clear();
//	}
//	
//	return length;
//}


// Function to check if there are other increasing numbers we can use
// This will help lengthen the sequence by doing further analysis
bool search(int arr[], int size, int index, vector <int> list)
{
	for (int x = index+1; x < size; x++)
	{
		if (arr[x] > list[list.size() - 2] && arr[x] < list.back())
		{
			return true;
		}
	}
	return false;
}

int LongestIncreasingSequence(int arr[], int size)
{
	int index, length = 0;
	vector <int> list;

	// Loop to find increasing sequences
	for (int x = 0; x < size; x++)
	{
		list.push_back(arr[x]);

		for (int y = x + 1; y < size; y++)
		{
			if (arr[y] > list.back()) // Check for all the values greater than the current
			{
				list.push_back(arr[y]);
				index = y;
			}
		}

		if (list.size() >= 2) // Analyze again to see if we can generate a better sequence
		{
			if (search(arr, size, index, list)) 
			{
				// Loop that implements the other increasing numbers
				do
				{
					list.pop_back();
					for (int z = index + 1; z < size; z++)
					{
						if (arr[z] > list.back())
						{
							list.push_back(arr[z]);
							index = z;
						}
					}
				} while (search(arr, size, index, list));
			}
		}

		if (list.size() > length) // Keep track of the longest increasing sequence
		{
			length = list.size();
		}

		list.clear();
		
	}

	return length;
}


int main() 
{
	int A[] = { 4, 3, 5, 1, 6 };
	int B[] = { 9, 9, 4, 2 };
	int C[] = { 10, 22, 9, 33, 21, 50, 41, 60, 22, 68, 90 };
	int D[] = { 10, 12, 4, 6, 100, 2, 56, 34, 79 };
	int E[] = { 10, 12, 4, 6, 100, 2, 56, 34, 79, 45, 33, 12, 45, 67, 89 };
	int F[] = { 2, 5, 7, 8, 9, 4, 10 };
	cout << LongestIncreasingSequence(A, sizeof(A) / sizeof(A[0])) << endl; // 3
	cout << LongestIncreasingSequence(B, sizeof(B) / sizeof(B[0])) << endl; // 1
	cout << LongestIncreasingSequence(C, sizeof(C) / sizeof(C[0])) << endl; // 7
	cout << LongestIncreasingSequence(D, sizeof(D) / sizeof(D[0])) << endl; // 4
	cout << LongestIncreasingSequence(E, sizeof(E) / sizeof(E[0])) << endl; // 6
	cout << LongestIncreasingSequence(F, sizeof(F) / sizeof(F[0])) << endl; // 6
	return 0;
}