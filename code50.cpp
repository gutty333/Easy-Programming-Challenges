// For this challenge you will determine how to optimally distribute food to people.
/*have the function FoodDistribution(arr) read the array of numbers stored in arr which will represent the hunger level of different people ranging from 0 to 5 (0 meaning not hungry at all, 5 meaning very hungry). You will also have N sandwiches to give out which will range from 1 to 20. The format of the array will be [N, h1, h2, h3, ...] where N represents the number of sandwiches you have and the rest of the array will represent the hunger levels of different people. Your goal is to minimize the hunger difference between each pair of people in the array using the sandwiches you have available. 

For example : if arr is[5, 3, 1, 2, 1], this means you have 5 sandwiches to give out.You can distribute them in the following order to the people : 2, 0, 1, 0. Giving these sandwiches to the people their hunger levels now become : [1, 1, 1, 1].The difference between each pair of people is now 0, the total is also 0, so your program should return 0. Note : You may not have to give out all, or even any, of your sandwiches to produce a minimized difference.

Another example : if arr is[4, 5, 2, 3, 1, 0] then you can distribute the sandwiches in the following order : [3, 0, 1, 0, 0] which makes all the hunger levels the following : [2, 2, 2, 1, 0].The differences between each pair of people is now : 0, 0, 1, 1 and so your program should return the final minimized difference of 2.
*/

#include <iostream>	
#include <string>	
using namespace std;

int FoodDistribution(int arr[], int size) 
{
	int total = arr[0]; // Number of Sandwiches
	int difference = 0; // Use to store the difference
	bool give; // Signal each time a distribution takes place

	// Checking for the difference of the original
	// In some cases we might not need to do food distribution if the difference across is 0
	for (int x = 1; x < size-1; x++)
	{
		difference += (arr[x] - arr[x + 1]);
	}
	if (difference == 0)
	{
		return 0;
	}

	// Loop to distribute food to those that are hungry
	// The distribution will be based by comparing the hunger levels adjacent to each other
	// The goal is to get the hunger levels to be equal across all people if possible
	do
	{
		give = false;

		for (int x = 1; x < size - 1; x++)
		{
			if (x == 1)
			{
				if (arr[x] > arr[x + 1] && total > 0)
				{
					give = true;
					arr[x]--;
					cout << "index " << x << " now is " << arr[x] << endl;
					total--;
				}
			}
			else if (arr[x] > arr[x + 1] && arr[x] > arr[x - 1] && total > 0)
			{
				give = true;
				arr[x]--;
				cout << "index " << x << " now is " << arr[x] << endl;
				total--;
			}
		}
	} while (give);

	// Checking for the difference after the distribution took place
	difference = 0;
	for (int x = 1; x < size - 1; x++)
	{
		int temp = arr[x] - arr[x + 1];
		if (temp < 0)
		{
			temp *= -1;
		}
		difference += temp;
	}

	return difference;
}

int main() 
{
	int A[] = { 5, 3, 1, 2, 1 };
	int B[] = { 4, 5, 2, 3, 1, 0 };
	int C[] = { 5, 2, 2, 2, 2, 2 };
	int D[] = { 5, 2, 3, 4, 5 };
	int E[] = { 3, 2, 1, 0, 4, 1, 0 };
	cout << FoodDistribution(A, sizeof(A)/sizeof(A[0])) << endl; // 0
	cout << FoodDistribution(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << FoodDistribution(C, sizeof(C) / sizeof(C[0])) << endl; // 0
	cout << FoodDistribution(D, sizeof(D) / sizeof(D[0])) << endl; // 1
	cout << FoodDistribution(E, sizeof(E) / sizeof(E[0])) << endl; // 4
	return 0;

	/*
	2 3 4 5		5
	2 2 4 5		4
	2 2 3 5		3
	2 2 3 4		2
	2 2 2 4		1
	2 2 2 3		0


	2 1 0 4 1 0		3
	2 1 0 3 1 0		2
	2 1 0 2 1 0		1
	2 1 0 1 1 0		0
	
	1 1 1 0 1
	
	*/
}