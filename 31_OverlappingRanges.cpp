// For this practice test you will determine the intersection between two sets.
// have the function OverlappingRanges(arr) take the array of numbers stored in arr which will contain 5 positive integers, the first two representing a range of numbers (a to b), the next 2 also representing another range of integers (c to d), and a final 5th element (x) which will also be a positive integer, and return the string true if both sets of ranges overlap by at least x numbers. For example: if arr is [4, 10, 2, 6, 3] then your program should return the string true. The first range of numbers are 4, 5, 6, 7, 8, 9, 10 and the second range of numbers are 2, 3, 4, 5, 6. The last element in the array is 3, and there are 3 numbers that overlap between both ranges: 4, 5, and 6. If both ranges do not overlap by at least x numbers, then your program should return the string false. 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string OverlappingRanges(int arr[], int size) {

	int count = 0;
	vector <int> range1;
	vector <int> range2;
	// Find the first range
	for (int x = arr[0]; x <= arr[1]; x++)
	{
		range1.push_back(x);
	}
	// Find the second range
	for (int y = arr[2]; y <= arr[3]; y++)
	{
		range2.push_back(y);
	}
	// Check how many numbers match between both range
	for (int i = 0; i < range1.size(); i++)
	{
		for (int z = 0; z < range2.size(); z++)
		{
			if (range1[i] == range2[z])
			{
				count++;
			}
		}
	}

	if (count >= arr[4])
	{
		return "true";
	}
	else
	{
		return "false";
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 5, 11, 1, 5, 1 };
	int B[] = { 1, 8, 2, 4, 4 };
	int C[] = { 4, 10, 2, 6, 3 };
	int D[] = { 1, 2, 1, 3, 1 };
	int E[] = { 1, 10, 9, 10, 1 };
	int F[] = { 4, 10, 5, 8, 2 };
	cout << OverlappingRanges(A, sizeof(A) / sizeof(A[0])) << endl; // true
	cout << OverlappingRanges(B, sizeof(B) / sizeof(B[0])) << endl; // false
	cout << OverlappingRanges(C, sizeof(C) / sizeof(C[0])) << endl; // true
	cout << OverlappingRanges(D, sizeof(D) / sizeof(D[0])) << endl; // false
	cout << OverlappingRanges(E, sizeof(E) / sizeof(E[0])) << endl; // false
	cout << OverlappingRanges(F, sizeof(F) / sizeof(F[0])) << endl; // false
	return 0;

}