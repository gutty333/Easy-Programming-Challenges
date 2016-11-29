// For this challenge you will return the product of a set of elements in an array.
// have the function OtherProducts(arr) take the array of numbers stored in arr and return a new list of the products of all the other numbers in the array for each element. For example: if arr is [1, 2, 3, 4, 5] then the new array, where each location in the new array is the product of all other elements, is [120, 60, 40, 30, 24]. The following calculations were performed to get this answer: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]. You should generate this new array and then return the numbers as a string joined by a hyphen: 120-60-40-30-24. The array will contain at most 10 elements and at least 1 element of only positive integers. 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string OtherProducts(int arr[], int size)
{
	// Empty list that will include the new products
	vector <int> newList;
	int total;

	// Loop to calculate the products for the new list
	for (int x = 0; x < size; x++)
	{
		total = 1;

		for (int y = 0; y < size; y++)
		{
			if (x == y)
			{
				continue;
			}
			else
			{
				total *= arr[y];
			}
		}

		newList.push_back(total);
	}

	// Creating a string to generate our required result
	string result;

	// Loop to convert the values to a string and modify our result to include the hyphen
	for (int x = 0; x < size; x++)
	{
		stringstream convert;
		convert << newList[x];
		result+=convert.str();
		if (x != size - 1)
		{
			result += '-';
		}
	}

	return result;
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5 };

	cout << OtherProducts(A, sizeof(A) / sizeof(A[0])) << endl;

	return 0;
}