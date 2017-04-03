// For this challenge you will determine if two numbers can be multiplied to some specific number.
/*
have the function SumMultiplier(arr) take the array of numbers stored in arr and return the string true if any two numbers can be multiplied so that the answer is greater than double the sum of all the elements in the array. If not, return the string false. For example: if arr is [2, 5, 6, -6, 16, 2, 3, 6, 5, 3] then the sum of all these elements is 42 and doubling it is 84. There are two elements in the array, 16 * 6 = 96 and 96 is greater than 84, so your program should return the string true.
*/

#include <iostream>
#include <string>
using namespace std;

/*
find the total sum
double the sum
analyze if any 2 numbers are greater than double sum
*/

string SumMultiplier(int arr[], int size)
{
	int total = 0;
	
	for (int x = 0; x < size; x++)
	{
		total += arr[x];
	}

	total *= 2;

	for (int x = 0; x < size - 1; x++)
	{
		for (int y = x + 1; y < size; y++)
		{
			if (arr[x]*arr[y] > total)
			{
				return "true";
			}
		}
	}

	return "false";
}


int main() 
{
	int A[] = { 2, 5, 6, -6, 16, 2, 3, 6, 5, 3 };
	int B[] = { 2, 2, 2, 2, 4, 1 };
	int C[] = { 1, 1, 2, 10, 3, 1, 12 };
	cout << SumMultiplier(A, sizeof(A) / sizeof(A[0])) << endl; // true
	cout << SumMultiplier(B, sizeof(B) / sizeof(B[0])) << endl; // false
	cout << SumMultiplier(C, sizeof(C) / sizeof(C[0])) << endl; // true
	return 0;
}