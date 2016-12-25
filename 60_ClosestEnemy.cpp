// For this challenge you will search in an array for an enemy.
/*
have the function ClosestEnemy(arr) take the array of numbers stored in arr and from the position in the array where a 1 is, return the number of spaces either left or right you must move to reach an enemy which is represented by a 2. For example: if arr is [0, 0, 1, 0, 0, 2, 0, 2] then your program should return 3 because the closest enemy (2) is 3 spaces away from the 1. The array will contain any number of 0's and 2's, but only a single 1. It may not contain any 2's at all as well, where in that case your program should return a 0.
*/

#include <iostream>
#include <algorithm>
using namespace std;


/*
Locate the one index
iterate to the left and search for any enemies
If found keep track of its distance
iterate to the right and search for any enemies and keep distance
report the closest enemy
if none found return 0
*/

int ClosestEnemy(int arr[], int size) 
{
	int enemy = size * 100;

	// Locate the index of our position
	int start = distance(arr,find(arr, size+arr, 1));

	// Locating the enemy to the left
	// We increment the length to use as a boundary check
	// If is equal to that boundary check length than we know the value was not found
	int left = distance(arr, find(arr, (start + arr)+1, 2));
	
	// Loop condition in the case we have multiples enemies before the start location
	// We have to increase our index from the start each time to ensure we reach the closest enemy
	int temp = left;
	int index = 0;
	while (temp != start + 1)
	{
		left = temp;
		temp = distance(arr, find(arr+index, (start + arr) + 1, 2));
		index++;
	}

	// Condition to check if found
	// If found find the difference in distance
	if (left != start+1)
	{
		enemy = start - left;
	}

	// Locating the closest enemy to the right
	int right = distance(arr, find(start + arr, (size + arr)+1, 2));
	if (right != size + 1 && right - start < enemy)
	{
		enemy = right - start;
	}
	
	// Condition to check if any enemies where found
	if (enemy == size * 100)
	{
		return 0;
	}
	else
	{
		return enemy;
	}
}

int main() 
{
	int A[] = { 0, 0, 1, 0, 0, 2, 0, 2 };
	int B[] = { 1, 0, 0, 0, 2, 2, 2 };
	int C[] = { 2, 0, 0, 0, 2, 2, 1, 0 };
	cout << ClosestEnemy(A, sizeof(A) / sizeof(A[0])) << endl; // 3
	cout << ClosestEnemy(B, sizeof(B) / sizeof(B[0])) << endl; // 4
	cout << ClosestEnemy(C, sizeof(C) / sizeof(C[0])) << endl; // 1
	return 0;

}