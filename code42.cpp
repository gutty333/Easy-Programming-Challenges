// For this challenge you will determine if two elements can sum to some larger number.
// have the function TwoSum(arr) take the array of integers stored in arr, and determine if any two numbers (excluding the first element) in the array can sum up to the first element in the array. For example: if arr is [7, 3, 5, 2, -4, 8, 11], then there are actually two pairs that sum to the number 7: [5, 2] and [-4, 11]. Your program should return all pairs, with the numbers separated by a comma, in the order the first number appears in the array. Pairs should be separated by a space. So for the example above, your program would return: 5,2 -4,11 


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void TwoSum(int arr[], int size) 
{
	int total = arr[0];
	vector <int> list;

	// Loop to check the different combinations
	for (int x = 1; x < size; x++)
	{
		int current = 0;
		for (int y = x; y < size; y++)
		{
			if (y == x)
			{
				continue;
			}
			
			current = arr[x] + arr[y]; // Evaluating each combination 
			if (current == total) 
			{
				list.push_back(arr[x]);
				list.push_back(arr[y]);
			}
		}
	}

	// Output
	if (list.size() > 0)
	{
		int pair = 0;
		for (int x = 0; x < list.size(); x++)
		{
			if (pair == 1)
			{
				cout << ",";
			}
			else if (pair == 2)
			{
				cout << " ";
				pair = 0;
			}

			cout << list[x];
			pair++;
		}
		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main() 
{
	int A[] = { 7, 3, 5, 2, -4, 8, 11 };
	int B[] = { 17, 4, 5, 6, 10, 11, 4, -3, -5, 3, 15, 2, 7 };
	int C[] = { 7, 6, 4, 1, 7, -2, 3, 12 };
	int D[] = { 4, 5, 2, 1 };
	TwoSum(A, sizeof(A)/sizeof(A[0])); // 5,2 -4,11
	TwoSum(B, sizeof(B) / sizeof(B[0])); // 6,11 10,7 15,2
	TwoSum(C, sizeof(C) / sizeof(C[0])); // 6,1 4,3
	TwoSum(D, sizeof(D) / sizeof(D[0])); // None

	return 0;

}