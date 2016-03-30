// For this challenge you will determine the area of a rectangle.
// have the function RectangleArea(strArr) take the array of strings stored in strArr, which will only contain 4 elements and be in the form (x y) where x and y are both integers, and return the area of the rectangle formed by the 4 points on a Cartesian grid. The 4 elements will be in arbitrary order. For example: if strArr is ["(0 0)", "(3 0)", "(0 2)", "(3 2)"] then your program should return 6 because the width of the rectangle is 3 and the height is 2 and the area of a rectangle is equal to the width * height. 

#include <iostream>
#include <string>
using namespace std;

int RectangleArea(string strArr[]) {
	// Strings to store the points for X and Y
	string tempX;
	string tempY;
	
	// Will store the first X and Y point from the first string
	// Using condition to check if number is negative or positive
	if (strArr[0][1] == '-')
	{
		tempX.push_back(strArr[0][2]);
		if (strArr[0][4] == '-')
		{
			tempY.push_back(strArr[0][5]);
		}
		else
		{
			tempY.push_back(strArr[0][4]);
		}
	}
	else
	{
		tempX.push_back(strArr[0][1]);
		if (strArr[0][3] == '-')
		{
			tempY.push_back(strArr[0][4]);
		}
		else
		{
			tempY.push_back(strArr[0][3]);
		}
	}

	// Check the x and y point of every string to determine the width and height
	// Again will check for negative number
	for (int x = 0; x < 4; x++)
	{
		if (strArr[x][1] == '-')
		{
			if (strArr[x][2] != tempX[0] && tempX.length() == 1)
			{
				tempX.push_back(strArr[x][2]);
			}

			if (strArr[0][4] == '-')
			{
				if (strArr[x][5] != tempY[0] && tempY.length() == 1)
				{
					tempY.push_back(strArr[x][5]);
				}
			}
			else
			{
				if (strArr[x][4] != tempY[0] && tempY.length() == 1)
				{
					tempY.push_back(strArr[x][4]);
				}
			}
			
		}
		else
		{
			if (strArr[x][1] != tempX[0] && tempX.length() == 1)
			{
				tempX.push_back(strArr[x][1]);
			}

			if (strArr[x][3] == '-')
			{
				if (strArr[x][4] != tempY[0] && tempY.length() == 1)
				{
					tempY.push_back(strArr[x][4]);
				}
			}
			else
			{
				if (strArr[x][3] != tempY[0] && tempY.length() == 1)
				{
					tempY.push_back(strArr[x][3]);
				}
			}
		}
	}

	// In the case that the axis were the same
	// Copy the same value for ease of calculation
	if (tempX.length() == 1)
	{
		tempX.push_back(tempX[0]);
	}
	if (tempY.length() == 1)
	{
		tempY.push_back(tempY[0]);
	}

	// Calculating to find the numeric value of the width and the height
	int width, height;
	if (tempX[0] >= tempX[1])
	{
		width = (int(tempX[0]) - 48) - (int(tempX[1]) - 48);
	}
	else
	{
		width = (int(tempX[1]) - 48) - (int(tempX[0]) - 48);
	}
	if (tempY[0] >= tempY[1])
	{
		height = (int(tempY[0]) - 48) - (int(tempY[1]) - 48);
	}
	else
	{
		height = (int(tempY[1]) - 48) - (int(tempY[0]) - 48);
	}

	return width * height;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "(1 1)", "(1 3)", "(3 1)", "(3 3)" }; 
	string B[] = { "(0 0)", "(1 0)", "(1 1)", "(0 1)" }; 
	string C[] = { "(0 0)", "(3 0)", "(0 2)", "(3 2)" };
	string D[] = { "(-1 -1)", "(0 0)", "(-1 0)", "(0 -1)" };
	string E[] = { "(-2 -2)", "(0 0)", "(-2 0)", "(0 -2)" };
	string F[] = { "(0 0)", "(0 0)", "(0 0)", "(0 0)" };
	cout << RectangleArea(A) << endl; // 4
	cout << RectangleArea(B) << endl; // 1
	cout << RectangleArea(C) << endl; // 6
	cout << RectangleArea(D) << endl; // 1
	cout << RectangleArea(E) << endl; // 4
	cout << RectangleArea(F) << endl; // 0
	return 0;

}