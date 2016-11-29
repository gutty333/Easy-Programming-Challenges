// For this challenge you will determine the second lowest and greatest numbers in an array.
// have the function SecondGreatLow(arr) take the array of numbers stored in arr and return the second lowest and second greatest numbers, respectively, separated by a space. For example: if arr contains [7, 7, 12, 98, 106] the output should be 12 98. The array will not be empty and will contain at least 2 numbers. It can get tricky if there's just two numbers! 

#include <iostream>
#include <string>
using namespace std;

void SecondGreatLow(int arr[], int size) {

	if (size == 2) // In the case that there is only 2 numbers
	{
		if (arr[0] < arr[1])
		{
			cout << arr[0] << " " << arr[1];
		}
		else
		{
			cout << arr[1] << " " << arr[0];
		}
	}
	else
	{
		// Implementing a bubble sort to sort the array from least to greatest
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

		int index = 0;
		int index2 = size - 1;
		// Loop to check if the first values are the same ex . 2,2,2,2.....
		for (int y = 0; y < size-1; y++)
		{
			if (arr[y] == arr[y + 1])
			{
				index++;
			}
			else
			{
				break;
			}
		}
		// Loop to check if the last values are the same ex .......45,45,45
		for (int z = size - 1; size > 0; z--)
		{
			if (arr[z] == arr[z - 1])
			{
				index2--;
			}
			else
			{
				break;
			}
		}
		cout << arr[index+1] << " " << arr[index2-1];
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 1, 42, 42, 180 };
	int B[] = { 4, 90 };
	int C[] = { 2, 2, 2, 5, 5, 5, 6, 6 };
	int D[] = { 7, 7, 90, 1000003 };
	SecondGreatLow(A, sizeof(A)/sizeof(A[0])); // 42 42
	cout << endl;
	SecondGreatLow(B, sizeof(B)/sizeof(B[0])); // 4 90 
	cout << endl;
	SecondGreatLow(C, sizeof(C) / sizeof(C[0])); // 5 5
	cout << endl;
	SecondGreatLow(D, sizeof(D) / sizeof(D[0])); // 90 90 
	cout << endl;
	return 0;

}