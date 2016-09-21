// For this challenge you will compute the length of the longest increasing subsequence.
// have the function LongestIncreasingSequence(arr) take the array of positive integers stored in arr and return the length of the longest increasing subsequence (LIS). A LIS is a subset of the original list where the numbers are in sorted order, from lowest to highest, and are in increasing order. The sequence does not need to be contiguous or unique, and there can be several different subsequences. For example: if arr is [4, 3, 5, 1, 6] then a possible LIS is[3, 5, 6], and another is[1, 6].For this input, your program should return 3 because that is the length of the longest increasing subsequence.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int LongestIncreasingSequence(int arr[], int size) 
{
	int index, length = 0;
	vector <int> list;

	// Loop to find increasing sequences
	//  10, 12, 4, 6, 100, 2, 56, 34, 79
	for (int x = 0; x < size-1; x++)
	{
		list.push_back(arr[x]);
		index = x;

		do
		{

			if (list.size() > 1)
			{
				list.pop_back();
			}

			for (int y = index + 1; y < size; y++)
			{
				if (arr[y] > list[list.size()-1])
				{
					list.push_back(arr[y]);
					index = y;
				}
			}

			for (int z = 0; z < list.size(); z++)
			{
				cout << list[z] << endl;
			}
			
			cout << "\t" << index << "    "  << size-1 << endl << endl;
			if (list.size() > length) // Condition to keep track of the longest sequence
			{
				length = list.size();
			}
		} while (index < size-1);
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
	//cout << LongestIncreasingSequence(A, sizeof(A)/sizeof(A[0])) << endl; // 3
	//cout << LongestIncreasingSequence(B, sizeof(B) / sizeof(B[0])) << endl; // 1
	//cout << LongestIncreasingSequence(C, sizeof(C) / sizeof(C[0])) << endl; // 7
	cout << LongestIncreasingSequence(D, sizeof(D) / sizeof(D[0])) << endl; // 4
	//cout << LongestIncreasingSequence(E, sizeof(E) / sizeof(E[0])) << endl; // 6
	return 0;

}