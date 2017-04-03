// For this challenge you will need to find the four largest elements in an array.
/*
have the function LargestFour(arr) take the array of integers stored in arr, and find the four largest elements and return their sum. For example: if arr is [4, 5, -2, 3, 1, 2, 6, 6] then the four largest elements in this array are 6, 6, 4, and 5 and the total sum of these numbers is 21, so your program should return 21. If there are less than four numbers in the array your program should return the sum of all the numbers in the array.
*/

#include <iostream>
#include <string>
using namespace std;

/*
Check the size of the input
If less than or equal to 4 find the sum
Order the numbers
Get the last 4
find the sum
*/

void bubbleSort(int arr[], int size)
{
	bool swap;
	do
	{
		swap = false;
		int temp;

		for (int x = 0; x < size-1; x++)
		{
			if (arr[x] > arr[x + 1])
			{
				temp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int LargestFour(int arr[], int size) 
{
	int total = 0;
	if (size <= 4)
	{
		for (int x = 0; x < size; x++)
		{
			total += arr[x];
		}
		return total;
	}
	else
	{
		// Sort our input
		bubbleSort(arr, size);

		int count = 0;
		for (int x = size - 1; count < 4; count++, x--)
		{
			total += arr[x];
		}
		return total;
	}
}

int main() 
{
	int A[] = { 4, 5, -2, 3, 1, 2, 6, 6 };
	int B[] = { 1, 1, 1, -5 };
	int C[] = { 0, 0, 2, 3, 7, 1 };
	cout << LargestFour(A, sizeof(A)/sizeof(A[0])) << endl; // 21
	cout << LargestFour(B, sizeof(B) / sizeof(B[0])) << endl; // -2
	cout << LargestFour(C, sizeof(C) / sizeof(C[0])) << endl; // 13
	return 0;
}


