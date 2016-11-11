// For this challenge you will be adding up a whole row from Pascal's triangle.
//  have the function TriangleRow(num) take num which will be a positive integer representing some row from Pascal's triangle. Pascal's triangle starts with a [1] at the 0th row of the triangle. Then the first row is [1, 1] and the second row is [1, 2, 1]. The next row begins with 1 and ends with 1, and the inside of the row is determined by adding the k-1 and kth elements from the previous row. The next row in the triangle would then be [1, 3, 3, 1], and so on. The input will be some positive integer and your goal is to return the sum of that row. For example: if num is 4 then your program should return the sum of 1 + 4 + 6 + 4 + 1 which is 16. 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int TriangleRow(int num) 
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return pow(2, num);
	}
}

int main() 
{
	cout << TriangleRow(4) << endl; // 16
	cout << TriangleRow(1) << endl; // 2
	cout << TriangleRow(2) << endl; // 4
	cout << TriangleRow(7) << endl; // 128
	return 0;

}
