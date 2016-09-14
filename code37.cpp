// For this challenge you will determine if numbers in an array can be sorted in a particular way.
// have the function WaveSorting(arr) take the array of positive integers stored in arr and return the string true if the numbers can be arranged in a wave pattern: a1 > a2 < a3 > a4 < a5 > ..., otherwise return the string false. For example, if arr is: [0, 1, 2, 4, 1, 4], then a possible wave ordering of the numbers is: [2, 0, 4, 1, 4, 1]. So for this input your program should return the string true. The input array will always contain at least 2 elements. More examples are given below as sample test cases. 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string WaveSorting(int arr[], int size) 
{
	int temp, index  = 0;
	bool swap, found;
	vector <int> arr2;



	do
	{
		for (int x = 0; x < size - 1; x++)
		{
			if (x % 2 != 0 && arr[x] >= arr[x + 1])
			{
				for (int y = x + 1; y < size; y++)
				{
					if (arr[x] > arr[y])
					{
						temp = arr[x];
						arr[x] = arr[y];
						arr[y] = temp;
						break;
					}
				}
			}

			/*

			
			0 1 2 3 3 3 3 3 8 9
			1 0 2 3 3 3 3 3 8 9
			1 0 3 2 3 3 3 3 8 9
			1 0 3 2 3 8 3 3 3 9
			1 0 3 2 3 8 3 9 3 3

			0 1 2 3 3 3 3 3 8 9
			0 1 

			*/
			else if (x % 2 == 0 && arr[x] <= arr[index + 1])
			{
				for (int y = index + 1; y < size; y++)
				{
					if (arr[x] < arr[y])
					{
						temp = arr[x];
						arr[x] = arr[y];
						arr[y] = temp;
						break;
					}
				}
			}
		}



		bool wavesort = true;
		// Loop to check if the wave sort is correct
		for (int x = 0; x < size - 1; x++)
		{
			if (x % 2 != 0 && arr[x] >= arr[x + 1])
			{
				wavesort = false;
			}
			else if (x % 2 == 0 && arr[x] <= arr[x + 1])
			{
				wavesort = false;
			}
		}

		if (wavesort)
		{
			return "true";
		}
	} while (index < size);


	

	return "false";
}

int main() 
{
	int A[] = {0,1,2,4,1,4};
	int B[] = { 0, 1, 2, 4, 1, 1, 1 };
	int C[] = { 0, 4, 22, 4, 14, 4, 2 };
	int D[] = { 0, 1, 2, 3, 3, 3, 3, 3, 8, 9 };
	int E[] = { 1, 1, 1, 1, 5, 2, 5, 1, 1, 3, 5, 6, 8, 3 };

	// 5 1 1 1 1 2 5 1 1 3 5 6 8 3
	// 5 1 2 1 1 1 5 1 1 3 5 6 8 3
	// 3 1 5 1 6 1 3 1 5 1 2 1 5 
	cout << WaveSorting(A, sizeof(A) / sizeof(A[0])) << endl; // true 
	cout << WaveSorting(B, sizeof(B) / sizeof(B[0])) << endl; // false
	cout << WaveSorting(C, sizeof(C) / sizeof(C[0])) << endl; // true
	cout << WaveSorting(D, sizeof(D) / sizeof(D[0])) << endl; // true



	/*
	1 1 1 1 1 1 3 3 5 5 5 2 6 8

	3 1 3 1 5 1 5 1 5 1 2 1 8 6

	5 1 5 1 5 1 3 1 3 1 2 1 8 6




	3 0 3 1 3 2 8 3 9 3




	0 1 2 3 3 3 3 3 8 9
	1 0 2 3 3 3 3 3 8 9
	1 0 3 2 3 3 3 3 8 9
	1 0 3 2 8 3 3 3 3 9
	1 0 3 2 8 3 9 3 3 3

	9 8 3 3 3 3 3 2 1 0

	0 1 2 3 3 3 3 3 8 9

	1 0 2 




	3 0 3 1 3 2 8 3 9 3
	
	
	
	
	
	*/
	cout << WaveSorting(E, sizeof(E) / sizeof(E[0])) << endl; // true

	return 0;
}