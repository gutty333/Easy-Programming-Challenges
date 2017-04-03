// For this challenge you will be combining all of the elements in an array into a single number.
/*
have the function ElementMerger(arr) take the array of positive integers stored in arr and perform the following algorithm: continuously get the difference of adjacent integers to create a new array of integers, then do the same for the new array until a single number is left and return that number. For example: if arr is [4, 5, 1, 2, 7] then taking the difference of each pair of elements produces the following new array: [1, 4, 1, 5]. Then do the same for this new array to produce [3, 3, 4] -> [0, 1] -> 1. So for this example your program should return the number 1 because that is what's left at the end.
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
store the elements in a vector for easier manipulation
iterate and get the difference of adjacent elements
once we reach the last element update our list by removing that element and restart the process
End the loop once we have a single element
*/


int ElementMerger(int arr[], int size) 
{
	vector <int> list(arr, arr+size);
	int index = 0;

	while (list.size() > 1)
	{
		if (list.size() - 1 == index)
		{
			index = 0;
			list.pop_back();
		}
		else
		{
			int temp = abs(list[index] - list[index + 1]);
			list[index] = temp;
			index++;
		}
	}

	return list[0];
}

int main() 
{
	int A[] = { 4, 5, 1, 2, 7 };
	int B[] = { 5, 7, 16, 1, 2 };
	int C[] = { 1, 1, 1, 2 };
	cout << ElementMerger(A, sizeof(A)/sizeof(A[0])) << endl; // 1
	cout << ElementMerger(B, sizeof(B) / sizeof(B[0])) << endl; // 7
	cout << ElementMerger(C, sizeof(C) / sizeof(C[0])) << endl; // 1
	return 0;

}