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
NOT FINISHED


locate starting point
check if the matrix has any enemies
*/

int ClosestEnemyII(string strArr[], int size) 
{
	int startX, startY;
	bool enemyFound = false;

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < strArr[x].size(); y++)
		{
			if (strArr[x][y] == '1')
			{
				startX = x;
				startY = y;
			}

			if (strArr[x][y] == '2')
			{
				enemyFound = true;
			}
		}
	}

	if (!enemyFound)
	{
		return 0;
	}


}

int main() 
{
	string A[] = { "0000", "1000", "0002", "0002" };
	string B[] = { "000", "100", "200" };
	string C[] = { "0000", "2010", "0000", "2002" };

	cout << ClosestEnemyII(A,sizeof(A)/sizeof(A[0])) << endl; // 2
	cout << ClosestEnemyII(A, sizeof(A) / sizeof(A[0])) << endl; // 1
	cout << ClosestEnemyII(A, sizeof(A) / sizeof(A[0])) << endl; // 2
	return 0;

}