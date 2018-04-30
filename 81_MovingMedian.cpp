// For this challenge you will calculate the median in an array within a sliding window.
/*
have the function MovingMedian(arr) read the array of numbers stored in arr which will contain a sliding window size, N, as the first element in the array and the rest will be a list of numbers. Your program should return the Moving Median for each element based on the element and its N-1 predecessors, where N is the sliding window size. The final output should be a string with the moving median corresponding to each entry in the original array separated by commas.

Note that for the first few elements (until the window size is reached), the median is computed on a smaller number of entries. For example: if arr is [3, 1, 3, 5, 10, 6, 4, 3, 1] then your program should output "1,2,3,5,6,6,4,3"
*/

#include <iostream>
#include <string>
using namespace std;

// NOT FINISHED

int MovingMedian(int arr[], int size) 
{

}

int main() 
{
	int A[] = { 3, 1, 3, 5, 10, 6, 4, 3, 1 };
	int B[] = { 5, 2, 4, 6 };
	int C[] = { 3, 0, 0, -2, 0, 2, 0, -2 };

	cout << MovingMedian(A, sizeof(A) / sizeof(A[0])) << endl; // 1,2,3,5,6,6,4,3
	cout << MovingMedian(B, sizeof(B) / sizeof(B[0])) << endl; // 2,3,4
	cout << MovingMedian(C, sizeof(C) / sizeof(C[0])) << endl; // 0,0,0,0,0,0,0
	return 0;

}