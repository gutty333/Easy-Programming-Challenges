// For this challenge you will determine if the mode equals the mean in an array.
//  have the function MeanMode(arr) take the array of numbers stored in arr and return 1 if the mode equals the mean, 0 if they don't equal each other (ie. [5, 3, 3, 3, 1] should return 1 because the mode (3) equals the mean (3)). The array will not be empty, will only contain positive integers, and will not contain more than one mode. 

#include <iostream>
using namespace std;

//we can solve it using another method
/*

bool sortByVal(const pair<int, int> &a, 
               const pair<int, int> &b) 
{ 
    return (a.second < b.second); 
} 

int MeanMode(int A[], int n){
    
    
    //finding mean of given array
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += A[i];
        
    int mean = sum/n;
    
    
    //creating a map to finding frequencies of given elements 
    //or to find mode of given array.
    map<int, int> m;
	for(int i = 0; i < n; i++)
	    m[A[i]]++;
	
	    
	map<int, int>::iterator itr;
	
	
    //push it into the vector for sorting elements
    vector<pair<int, int>> vec;
    for(itr = m.begin(); itr != m.end(); itr++)
        vec.push_back(make_pair(itr->first, itr->second));
    
        
    //sorting vector using second value of pair of vector.    
    sort(vec.begin(), vec.end(), sortByVal);
    int mode = vec.back().first;
    
    
    //checking results if mean == mode ? return 1 : return 0;
    if(mean == mode)
        return 1;
    else
        return 0;
    
}

*/


int MeanMode(int arr[], int size) {

	int total = 0, average;
	int count = 0, temp, mode = 0, index = 0;

	// Finding the mean of the array
	// Looking back the total accumulator could go in the other loop
	for (int x = 0; x < size; x++)
	{
		total += arr[x];
	}
	average = total / size;

	// Finding the mode of the array
	for (int y = 0; y < size; y++)
	{
		temp = arr[y];

		for (int z = 0; z < size; z++)
		{
			if (y == z)
			{
				continue;
			}
			else if (arr[z] == temp)
			{
				count++;
			}
		}

		if (count > mode)
		{
			mode = count;
			index = y;
		}
		count = 0;
	}

	if (arr[index] == average)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 1, 2, 3 }; // 0
	int B[] = { 4, 4, 4, 6, 2 }; // 1
	int C[] = { 5, 3, 3, 3, 1 }; // 1
	cout << MeanMode(A, sizeof(A)/sizeof(A[0])) << endl;
	cout << MeanMode(B, sizeof(B) / sizeof(B[0])) << endl;
	cout << MeanMode(C, sizeof(C) / sizeof(C[0])) << endl;
	return 0;

}
