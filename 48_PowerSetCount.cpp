//  For this challenge you will determine the length of a power set.
// have the function PowerSetCount(arr) take the array of integers stored in arr, and return the length of the power set (the number of all possible sets) that can be generated. For example: if arr is [1, 2, 3], then the following sets form the power set: 

#include <iostream>
#include <cmath>
using namespace std;

int PowerSetCount(int arr[], int size)
{
	return pow(2,size);
}

int main() 
{
	int A[] = { 1, 2, 3 };
	cout << PowerSetCount(A, sizeof(A) / sizeof(A[0])) << endl; // 8
	return 0;

}