// For this challenge you will search in a matrix for an enemy.
/*
have the function ClosestEnemyII(strArr) read the matrix of numbers stored in strArr which will be a 2D matrix that contains only the integers 1, 0, or 2. Then from the position in the matrix where a 1 is, return the number of spaces either left, right, down, or up you must move to reach an enemy which is represented by a 2. You are able to wrap around one side of the matrix to the other as well. For example: if strArr is ["0000", "1000", "0002", "0002"] then this looks like the following:

0 0 0 0
1 0 0 0
0 0 0 2
0 0 0 2

For this input your program should return 2 because the closest enemy (2) is 2 spaces away from the 1 by moving left to wrap to the other side and then moving down once. The array will contain any number of 0's and 2's, but only a single 1. It may not contain any 2's at all as well, where in that case your program should return a 0.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
during the traversal, we extract the locations of our source
alongside the multiple destinations if any are found
if no destinations are in the matrix, we return 0
else we compare source to current destination
we analyze both their distance and keep track of number of steps
after we finish analyzing each distance, we return the lowest steps gathered
*/
int ClosestEnemyII(string strArr[], int size) 
{
	vector < vector<int> > destinations; // stores our destination indexes
	int sourceRow;
	int sourceCol;
	int minimalSteps = size * 100;

	// traverse the input array to extract its values
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < strArr[x].length(); y++)
		{
			// conditions to store critical locations
			if (strArr[x][y] == '1')
			{
				sourceRow = x;
				sourceCol = y;
			}
			else if (strArr[x][y] == '2')
			{
				vector <int> temp;
				temp.push_back(x);
				temp.push_back(y);
				
				destinations.push_back(temp);
			}
		}
	}

	// check if any destinations were found
	if (destinations.size() == 0)
	{
		return 0;
	}
	else
	{
		// iterate through our destinations and gather their distance from source
		for (int x = 0; x < destinations.size(); x++)
		{
			// current enemy location
			int targetRow = destinations[x][0];
			int targetCol = destinations[x][1];

			// calculating their distance 
			int rowDifference = targetRow - sourceRow;
			int colDifference = targetCol - sourceCol;
			if (rowDifference < 0)
			{
				rowDifference *= -1;

				// conditions to check wrapping around is more optimal
				if (rowDifference > size - (sourceRow- targetRow))
				{
					colDifference = size - (sourceRow - targetRow);
				}
			}
			else if (rowDifference > size - (targetRow - sourceRow))
			{
				rowDifference = size - (targetRow - sourceRow);
			}

			if (colDifference < 0)
			{
				colDifference *= -1;
				
				// conditions to check wrapping around is more optimal
				if (colDifference > size - (sourceCol - targetCol))
				{
					colDifference = size - (sourceCol - targetCol);
				}
			}
			else if (colDifference > size - (targetCol - sourceCol))
			{
				colDifference = size - (targetCol - sourceCol);
			}

			int currentSteps = colDifference + rowDifference;

			// keep track of the lowest distance
			if (currentSteps < minimalSteps)
			{
				minimalSteps = currentSteps;
			}
		}
	}

	return minimalSteps;
}

int main() 
{
	string A[] = { "0000", "1000", "0002", "0002" };
	string B[] = { "000", "100", "200" };
	string C[] = { "0000", "2010", "0000", "2002" };
	string D[] = { "0000", "0010", "0000", "0000" };
	string E[] = { "01000", "00020", "00000", "00002", "02002" };

	cout << ClosestEnemyII(A, sizeof(A) / sizeof(A[0])) << endl; // 2
	cout << ClosestEnemyII(B, sizeof(B) / sizeof(B[0])) << endl; // 1
	cout << ClosestEnemyII(C, sizeof(C) / sizeof(C[0])) << endl; // 2
	cout << ClosestEnemyII(D, sizeof(D) / sizeof(D[0])) << endl; // 0
	cout << ClosestEnemyII(E, sizeof(E) / sizeof(E[0])) << endl; // 1
	return 0;
}
