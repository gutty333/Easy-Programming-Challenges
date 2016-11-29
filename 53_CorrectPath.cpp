// For this challenge you will be traversing a matrix searching for the correct path to take.
/*
have the function CorrectPath(str) read the str parameter being passed, which will represent the movements made in a 5x5 grid of cells starting from the top left position. The characters in the input string will be entirely composed of: r, l, u, d, ?. Each of the characters stand for the direction to take within the grid, for example: r = right, l = left, u = up, d = down. Your goal is to determine what characters the question marks should be in order for a path to be created to go from the top left of the grid all the way to the bottom right without touching previously travelled on cells in the grid.

For example: if str is "r?d?drdd" then your program should output the final correct string that will allow a path to be formed from the top left of a 5x5 grid to the bottom right. For this input, your program should therefore return the string rrdrdrdd. There will only ever be one correct path and there will always be at least one question mark within the input string.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
Problem breakdown before coding

Check when there are ? marks
If found set up a move option that will try out the different movements that can be done
Make sure you only try the movements that follow the rule meaning no out of boundary or trace back
Keep track of the index for the grid and string
When you try a movement direction remember to update the grid

Keep looping through the string 
If you come across another ? mark, do the same step
You will maybe need an array of string to keep track of the move options
Also an array of integers to keep track of the indexes

Continue this progress and also update when there are no question marks

When you come across an error, trace back on the index and now check for another move option
Update the grid from that point

If you have checked all the options of that ? mark and there where more previous ? marks ie( ???rlu)
Return to the previous ? mark and check the move options there
Keep looping the string

Again repeat the process of checking for errors

If no errors where giving along the way and we finish the path, but did not reach the goal
Repeat the same progress of tracing back to the previous ? mark
*/


// Function that will perform movements based on direction
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

// Function that will make sure we do not step outside of the grid
bool boundaryCheck(int row, int col)
{
	if (row <= -1 || row >= 5 || col <= -1 || col >= 5)
	{
		return true;
	}
	return false;
}

// Function that will check will do not trace back on previously traveled cells
bool traceCheck(int grid[][5], int row, int col)
{
	if (grid[row][col] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Search function that will check which move options we have done
bool search(vector <string> list, int index , char val)
{
	for (int y = 0; y < list[index].size(); y++)
	{
		if (val == list[index][y])
		{
			return true;
		}
	}
	return false;
}

// Function that will reset the grid from a specific location
void reset(int grid[][5], int resetLocation, vector <vector <int> >& spots, int& newRow, int& newCol)
{
	// The Loop will iterate backwards to the nearest ? mark
	for (int row = spots.size(); row > resetLocation; row--)
	{
		// Replace the grid with the default 0 which signifies an empty spot
		grid[spots[spots.size() - 1][0]][spots[spots.size() - 1][1]] = 0;
		spots.pop_back();
	}

	// Update the original row and col for correct movement
	// Check when the ? mark is at the front
	if (spots.size() >= 1)
	{
		newRow = spots[spots.size() - 1][0];
		newCol = spots[spots.size() - 1][1];
	}
	else
	{
		newRow = 0;
		newCol = 0;
	}
}

string CorrectPath(string str) 
{
	int grid[5][5];
	int total = 0;

	// Loop to check how many ? marks are in the string
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '?')
		{
			total++;
		}
	}

	vector <string> moveOptions(total);  // Keeps track of the different directions we choose
	vector <int> indexLocations; // Keeps track of where the ? marks are located
	vector <vector <int> > locations; // Keeps track of the locations where we have made a change
	vector <int> temp;
	total = 0; 
	
	// Loop to fill out our representing grid
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			grid[row][col] = 0;
		}
	}

	// Setting the top left to 1, which will represent our starting position
	grid[0][0] = 1;
	int row = 0, col = 0; // Our cursor or location indicators

	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] != '?') // Condition to check for any non ? mark
		{
			// Update the grid based on that direction if it follows the rules
			movement(str[x], row, col);
			if (!boundaryCheck(row, col) && !traceCheck(grid, row, col))
			{
				grid[row][col] = 1;
				locations.push_back(temp);
				locations[x].push_back(row);
				locations[x].push_back(col);
			}
			else
			{
				// Trace back to our index to try another move option
				total--;
				x = indexLocations.back() - 1; 
				// Reset the grid to that previous position 
				reset(grid, indexLocations.back(), locations, row, col);
			}
		}
		else
		{
			// Condition to try out different move options
			// Only try move options that follow the rule
			// Keeps track of the location and updates the grid
			if (!search(moveOptions, total, 'l') && !boundaryCheck(row,col-1) && !traceCheck(grid,row,col-1))
			{
				moveOptions[total].push_back('l');
				movement('l', row, col);
				grid[row][col] = 1;
				locations.push_back(temp);
				locations[x].push_back(row);
				locations[x].push_back(col);
			}
			else if (!search(moveOptions, total, 'r') && !boundaryCheck(row, col + 1) && !traceCheck(grid, row, col + 1))
			{
				moveOptions[total].push_back('r');
				movement('r', row, col);
				grid[row][col] = 1;
				locations.push_back(temp);
				locations[x].push_back(row);
				locations[x].push_back(col);
				
			}
			else if (!search(moveOptions, total, 'u') && !boundaryCheck(row-1, col) && !traceCheck(grid, row-1, col))
			{
				moveOptions[total].push_back('u');
				movement('u', row, col);
				grid[row][col] = 1;
				locations.push_back(temp);
				locations[x].push_back(row);
				locations[x].push_back(col);
			}
			else if (!search(moveOptions, total, 'd') && !boundaryCheck(row+1, col) && !traceCheck(grid, row+1, col))
			{
				moveOptions[total].push_back('d');
				movement('d', row, col);
				grid[row][col] = 1;
				locations.push_back(temp);
				locations[x].push_back(row);
				locations[x].push_back(col);
			}
			else
			{
				// Since we are analyzing the previous ? mark we can clear the movements we made on this ? mark
				moveOptions[total].clear();
				indexLocations.pop_back();
				total--;
				x = indexLocations.back() - 1;
				reset(grid, indexLocations.back(), locations, row, col);
				continue;
			}
			// Keeps track of the index where the last ? mark was located
			if (indexLocations.size() == 0 || indexLocations.back() != x)
			{
				indexLocations.push_back(x);
			}

			total++;
		}

		// Condition to check if the path reached the end
		if (x == str.length() - 1 && grid[4][4] != 1)
		{
			total--;
			x = indexLocations.back() - 1;
			reset(grid, indexLocations.back(), locations, row, col);
		}
	}

	// Loop to generate the final string output that will have the correct characters represent the directions
	int count = 0;
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '?')
		{
			str[x] = moveOptions[count][moveOptions[count].size() - 1];
			count++;
		}
	}
	return str;
}

int main()
{
	cout << CorrectPath("r?d?drdd") << endl; // rrdrdrdd
	cout << CorrectPath("???rrurdr?")<< endl; // dddrrurdrd
	cout << CorrectPath("drdr??rrddd?")<< endl; // drdruurrdddd
	cout << CorrectPath("????ruu??dd?") << endl;
	cout << CorrectPath("rdrd??d?rr??") << endl;
	return 0;

}