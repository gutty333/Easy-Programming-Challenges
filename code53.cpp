// For this challenge you will be traversing a matrix searching for the correct path to take.
/*
have the function CorrectPath(str) read the str parameter being passed, which will represent the movements made in a 5x5 grid of cells starting from the top left position. The characters in the input string will be entirely composed of: r, l, u, d, ?. Each of the characters stand for the direction to take within the grid, for example: r = right, l = left, u = up, d = down. Your goal is to determine what characters the question marks should be in order for a path to be created to go from the top left of the grid all the way to the bottom right without touching previously travelled on cells in the grid.

For example: if str is "r?d?drdd" then your program should output the final correct string that will allow a path to be formed from the top left of a 5x5 grid to the bottom right. For this input, your program should therefore return the string rrdrdrdd. There will only ever be one correct path and there will always be at least one question mark within the input string.
*/

#include <iostream>
#include <string>
using namespace std;


/* 

Check when there are ? marks
If found set up a move option that will try out the different movements that can be done
Make sure you only try the moments that follow the rule meaning no out of boundary or trace back
Keep track of the index for the grid and string
When you try a movement direction remember to update the grid

Keep looping through the string 
If you come across another ? mark, do the same step
You will maybe need an array of string to keep track of the move option
Also an array of integers to keep track of the indexes

Continue this progress and also update when there are no question marks

When you come across an error, trace back on the index and now check for another move option
Update the grid from that point

If you have checked all the options of that ? mark and there where more previous etc( ???rlu)
Return to the previous ? mark and check the move options there
Keep looping the string

Again repeat the process check for errors, if you find any trace back and check for another move option

*/




void movement(char direction, int& row, int& col)
{
	switch (direction)
	{
		case 'r':
			col += 1;
			break;
		case 'l':
			col -= 1;
			break;
		case 'u':
			row -= 1;
			break;
		case 'd':
			row += 1;
			break;
	}
}


bool boundaryCheck(int row, int col)
{
	if (row <= -1 || row >= 5 || col <= -1 || col >= 5)
	{
		return true;
	}
	return false;
}


string CorrectPath(string str) 
{
	int grid[5][5];

	// Loop to fill out our representing grid
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			grid[row][col] = 0;
		}
	}

	// Setting the top left to 1, which will represent our current position
	grid[0][0] = 1;
	int row, col;

	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] != '?')
		{
			if (x == 0)
			{
				movement(str[x], row, col);
				grid[row][col] = 1;
			}
			else
			{
				for 
			}
		}
	}
}

int main() 
{

	cout <<CorrectPath("r?d?drdd") << endl; // rrdrdrdd
	return 0;

}