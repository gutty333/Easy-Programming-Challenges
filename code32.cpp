// For this challenge you will determine if each number is greater than the sum of all previous elements in an array.
// have the function Superincreasing(arr) take the array of numbers stored in arr and determine if the array forms a super-increasing sequence where each element in the array is greater than the sum of all previous elements. The array will only consist of positive integers. For example: if arr is [1, 3, 6, 13, 54] then your program should return the string "true" because it forms a superincreasing sequence. If a superincreasing sequence isn't formed, then your program should return the string "false" 

#include <iostream>
#include <string>
using namespace std;

string Superincreasing(int arr[], int size) {

	int total = 0;

	for (int x = 0; x < size-1; x++)
	{
		total += arr[x];

		if (total >= arr[x+1])
		{
			return "false";
		}
	}

	return "true";
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 1, 2, 3, 4 };
	int B[] = { 1, 2, 5, 10 };
	int C[] = { 1, 3, 6, 13, 54 };
	cout << Superincreasing(A, sizeof(A) / sizeof(A[0])) << endl; // false
	cout << Superincreasing(B, sizeof(B) / sizeof(B[0])) << endl; // true
	cout << Superincreasing(C, sizeof(C) / sizeof(C[0])) << endl; // true
	return 0;

}