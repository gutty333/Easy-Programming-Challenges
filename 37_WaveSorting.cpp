// For this challenge you will determine if numbers in an array can be sorted in a particular way.
// have the function WaveSorting(arr) take the array of positive integers stored in arr and return the string true if the numbers can be arranged in a wave pattern: a1 > a2 < a3 > a4 < a5 > ..., otherwise return the string false. For example, if arr is: [0, 1, 2, 4, 1, 4], then a possible wave ordering of the numbers is: [2, 0, 4, 1, 4, 1]. So for this input your program should return the string true. The input array will always contain at least 2 elements. More examples are given below as sample test cases. 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void order(int arr[], int size)
{
	bool swap;
	int temp;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
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

string WaveSorting(int arr[], int size) 
{
	// Order the array in ascending order
	order(arr, size);
	
	// Find the mid point from where to begin the wave ordering
	int mid = size / 2;

	// Ordering the array for wave sorting
	vector <int> list;
	for (int x = 0; mid < size; x++, mid++)
	{
		list.push_back(arr[mid]);
		list.push_back(arr[x]);
	}

	if (size % 2 != 0)
	{
		list.pop_back();
	}

	// Loop to check for wave sorting
	for (int x = 0; x < list.size()-1; x++)
	{
		if (x % 2 == 0 && list[x] <= list[x + 1])
		{
			return "false";
		}
		else if (x % 2 != 0 && list[x] >= list[x + 1])
		{
			return "false";
		}
	}

	return "true";
}

int main() 
{
	int A[] = { 0, 1, 2, 4, 1, 4};
	int B[] = { 0, 1, 2, 4, 1, 1, 1 };
	int C[] = { 0, 4, 22, 4, 14, 4, 2 };
	int D[] = { 0, 1, 2, 3, 3, 3, 3, 3, 8, 9 };
	int E[] = { 1, 1, 1, 1, 5, 2, 5, 1, 1, 3, 5, 6, 8, 3 };

	cout << WaveSorting(A, sizeof(A) / sizeof(A[0])) << endl; // true 
	cout << WaveSorting(B, sizeof(B) / sizeof(B[0])) << endl; // false
	cout << WaveSorting(C, sizeof(C) / sizeof(C[0])) << endl; // true
	cout << WaveSorting(D, sizeof(D) / sizeof(D[0])) << endl; // true
	cout << WaveSorting(E, sizeof(E) / sizeof(E[0])) << endl; // true

	return 0;
}