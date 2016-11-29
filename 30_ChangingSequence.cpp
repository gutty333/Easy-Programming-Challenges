// For this challenge you will determine when an array changes sequences.
// have the function ChangingSequence(arr) take the array of numbers stored in arr and return the index at which the numbers stop increasing and begin decreasing or stop decreasing and begin increasing. For example: if arr is [1, 2, 4, 6, 4, 3, 1] then your program should return 3 because 6 is the last point in the array where the numbers were increasing and the next number begins a decreasing sequence. The array will contain at least 3 numbers and it may contains only a single sequence, increasing or decreasing. If there is only a single sequence in the array, then your program should return -1. Indexing should begin with 0. 

#include <iostream>
using namespace std;

int ChangingSequence(int arr[], int size) {
	// The conditions will determine what the starting sequence is
	if (arr[0] < arr[1])
	{
		for (int x = 0; x < size - 1; x++)
		{
			if ((arr[x] > arr[x + 1]))
			{
				return x;
			}
		}
	}
	else
	{
		for (int x = 0; x < size - 1; x++)
		{
			if ((arr[x] < arr[x + 1]))
			{
				return x;
			}
		}
	}

	return -1;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { -4, -2, 9, 10 };
	int B[] = { 5, 4, 3, 2, 10, 11 };
	int C[] = { 1, 2, 4, 6, 4, 3, 1 };
	cout << ChangingSequence(A, sizeof(A)/sizeof(A[0])) << endl; // -1
	cout << ChangingSequence(B, sizeof(B) / sizeof(B[0])) << endl; // 3
	cout << ChangingSequence(C, sizeof(C) / sizeof(C[0])) << endl; // 3
	return 0;

}