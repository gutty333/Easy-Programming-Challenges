// For this challenge you will be creating a subset of an array.
// have the function OffLineMinimum(strArr) take the strArr parameter being passed which will be an array of integers ranging from 1...n and the letter "E" and return the correct subset based on the following rules. The input will be in the following format: ["I","I","E","I",...,"E",...,"I"] where the I's stand for integers and the E means take out the smallest integer currently in the whole set. When finished, your program should return that new set with integers separated by commas. For example: if strArr is ["5","4","6","E","1","7","E","E","3","2"] then your program should return 4,1,5. 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void OffLineMinimum(string strArr[], int size) {

	vector <string> temp;
	vector <string> temp2;
	int index;

	for (int x = 0; x < size; x++)
	{
		// Keep track of integers before taking the smallest value
		if (strArr[x] != "E")
		{
			temp.push_back(strArr[x]);
		}
		else
		{
			string low = temp[0];
			index = 0;
			// Find the lowest of the current set
			for (int y = 0; y < temp.size(); y++)
			{
				if (temp[y] < low)
				{
					low = temp[y];
					index = y;
				}
			}

			// Erase the lowest value from that list
			// This will aid in finding the next lowest value, when we keep adding more integers
			temp.erase(temp.begin()+index);
			// Save the lowest value to a new list
			temp2.push_back(low);
		}
	}

	// Print out the results
	for (int z = 0; z < temp2.size(); z++)
	{
		if (z == temp2.size() - 1)
		{
			cout << temp2[z] << endl;
		}
		else
		{
			cout << temp2[z] << ",";
		}
	}
}
// Note looking back at the code, there is not need for the last loop
// We could print out the result in the previous loop, Example instead of saving the lowest value to a new list
// We instead print out that value

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "1", "2", "E", "E", "3" };
	string B[] = { "4", "E", "1", "E", "2", "E", "3", "E" };
	string C[] = { "5", "4", "6", "E", "1", "7", "E", "E", "3", "2" };
	string D[] = { "4", "1", "5", "E", "E", "E" };
	OffLineMinimum(A, sizeof(A) / sizeof(A[0])); // 1,2
	OffLineMinimum(B, sizeof(B) / sizeof(B[0])); // 4,1,2,3
	OffLineMinimum(C, sizeof(C) / sizeof(C[0])); // 4,1,5
	OffLineMinimum(D, sizeof(D) / sizeof(D[0])); // 1,4,5
	return 0;

}