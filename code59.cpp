// For this challenge you will determine if a square of vowels exists in a matrix.
/*
have the function VowelSquare(strArr) take the strArr parameter being passed which will be a 2D matrix of some arbitrary size filled with letters from the alphabet, and determine if a 2x2 square composed entirely of vowels exists in the matrix. For example: strArr is ["abcd", "eikr", "oufj"] then this matrix looks like the following:

a b c d
e i k r
o u f j

Within this matrix there is a 2x2 square of vowels starting in the second row and first column, namely, ei, ou. If a 2x2square of vowels is found your program should return the top-left position (row-column) of the square, so for this example your program should return 1-0. If no 2x2 square of vowels exists, then return the string not found. If there are multiple squares of vowels, return the one that is at the most top-left position in the whole matrix. The input matrix will at least be of size 2x2.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Ensures we do not go out of boundary in our matrix
bool boundaryCheck(int row, int col, int size, string current)
{
	if (row <= -1 || row >= size || col <= -1 || col>= current.length())
	{
		return false;
	}
	return true;
}

bool neighbors(int row, int col, string current[], int size)
{
	int valid = 0;

	// Checks for neighboring vowels
	// Keeps count of how many we have found
	if (row + 1 < size)
	{
		if (boundaryCheck(row, col + 1, size, current[row]))
		{
			if (current[row][col + 1] == 'a' || current[row][col + 1] == 'e' || current[row][col + 1] == 'i' || current[row][col + 1] == 'o' || current[row][col + 1] == 'u')
			{
				valid++;
			}
		}
		else
		{
			return false;
		}
		if (boundaryCheck(row + 1, col + 1, size, current[row + 1]))
		{
			if (current[row + 1][col + 1] == 'a' || current[row + 1][col + 1] == 'e' || current[row + 1][col + 1] == 'i' || current[row + 1][col + 1] == 'o' || current[row + 1][col + 1] == 'u')
			{
				valid++;
			}
		}
		else
		{
			return false;
		}
		if (boundaryCheck(row + 1, col, size, current[row + 1]))
		{
			if (current[row + 1][col] == 'a' || current[row + 1][col] == 'e' || current[row + 1][col] == 'i' || current[row + 1][col] == 'o' || current[row + 1][col] == 'u')
			{
				valid++;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	if (valid == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string VowelSquare(string strArr[], int size) 
{
	int rowFinal = size, colFinal = strArr[0].length(); // temp values to later compare
	bool found = false;

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{	
			// We are going to assume the inputs will all be lower case
			// In the case this was more in depth we can easily just convert all the characters to lower case than check 
			if (strArr[row][col] == 'a' || strArr[row][col] == 'e' || strArr[row][col] == 'i' || strArr[row][col] == 'o' || strArr[row][col] == 'u')
			{
				// Condition for when we find a vowel square
				// Will keep track of our index
				// Also only stores the top left most starting position in the case we find multiple vowel squares
				if (neighbors(row, col, strArr, size) && (row+col) < (rowFinal+colFinal))
				{
					rowFinal = row;
					colFinal = col;
					found = true;
				}
			}
		}
	}

	if (found)
	{
		stringstream convert;
		convert << rowFinal << "-" << colFinal;
		return convert.str();
	}
	else
	{
		return "not found";
	}
}

int main() 
{
	string A[] = { "abcd", "eikr", "oufj" };
	string B[] = { "aqrst", "ukaei", "ffooo" };
	string C[] = { "gg", "ff" };
	cout << VowelSquare(A, sizeof(A) / sizeof(A[0])) << endl; // 1-0
	cout << VowelSquare(B, sizeof(B) / sizeof(B[0])) << endl; // 1-2
	cout << VowelSquare(C, sizeof(C) / sizeof(C[0])) << endl; // not found
	return 0;
}