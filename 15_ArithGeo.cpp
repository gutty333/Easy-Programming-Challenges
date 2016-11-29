// For this challenge you will determine if numbers within an array follow an arithmetic or geometric sequence.
// take the array of numbers stored in arr and return the string "Arithmetic" if the sequence follows an arithmetic pattern or return "Geometric" if it follows a geometric pattern. If the sequence doesn't follow either pattern return -1. An arithmetic sequence is one where the difference between each of the numbers is consistent, where as in a geometric sequence, each term after the first is multiplied by some constant or common ratio. Arithmetic example: [2, 4, 6, 8] and Geometric example: [2, 6, 18, 54]. Negative numbers may be entered as parameters, 0 will not be entered, and no array will contain all the same elements. 

#include <iostream>
#include <string>
using namespace std;

string ArithGeo(int arr[], const int size) {

	int difference = 0, difference2 = 0;
	bool arith = true, geo = true;

	// First find the difference of two numbers for both an arithmetic and geometric sequence
	difference = arr[1] - arr[0];
	difference2 = arr[1] / arr[0];

	// Check is the difference is true for all elements
	// If true than the array is arithmetic
	for (int y = 0; y < size-1 && arith; y++)
	{
		arith = false;
		if (arr[y] + difference == arr[y + 1])
		{
			arith = true;
		}
	}

	// Check is the difference is true for all elements
	// If true than the array is geometric
	for (int z = 0; z < size - 1 && geo; z++)
	{
		geo = false;
		if (arr[z] * difference2 == arr[z + 1])
		{
			geo = true;
		}
	}

	if (arith)
	{
		return "Arithmetic";
	}
	else if (geo)
	{
		return "Geometric";
	}
	else
	{
		return "-1";
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 2, 4, 16, 24 };
	int B[] = { 5, 10, 15,20 };
	int C[] = { 2, 6, 18, 54 };
	int D[] = { 2, 4, 6, 8 };
	cout << ArithGeo(A, sizeof(A)/sizeof(A[0])) << endl; // -1
	cout << ArithGeo(B, sizeof(A) / sizeof(A[0])) << endl; //Arithmetic
	cout << ArithGeo(C, sizeof(A) / sizeof(A[0])) << endl; //Geometric
	cout << ArithGeo(D, sizeof(A) / sizeof(A[0])) << endl; // Arithmetic
	return 0;
}