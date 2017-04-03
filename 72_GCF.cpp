// For this challenge you will determine the greatest common factor of two numbers.
/*
have the function GCF(arr) take the array of numbers stored in arr which will always contain only two positive integers, and return the greatest common factor of them. For example: if arr is [45, 12] then your program should return 3. There will always be two elements in the array and they will be positive integers.
*/

#include <iostream>
using namespace std;

int GCF(int arr[]) 
{
	int gcf;
	if (arr[0] > arr[1])
	{
		gcf = arr[1];
	}
	else
	{
		gcf = arr[0];
	}

	while (arr[0] % gcf != 0 || arr[1] % gcf != 0)
	{
		gcf--;
	}
	return gcf;
}

int main() 
{
	int A[] = { 45, 12};
	int B[] = { 1, 6 };
	int C[] = {12 ,28};
	cout << GCF(A) << endl; // 3
	cout << GCF(B) << endl; // 1 
	cout << GCF(C) << endl; // 4

	return 0;

}