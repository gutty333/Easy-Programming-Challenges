// For this challenge you will determine how to optimally distribute food to people.
/*have the function FoodDistribution(arr) read the array of numbers stored in arr which will represent the hunger level of different people ranging from 0 to 5 (0 meaning not hungry at all, 5 meaning very hungry). You will also have N sandwiches to give out which will range from 1 to 20. The format of the array will be [N, h1, h2, h3, ...] where N represents the number of sandwiches you have and the rest of the array will represent the hunger levels of different people. Your goal is to minimize the hunger difference between each pair of people in the array using the sandwiches you have available. 

For example : if arr is[5, 3, 1, 2, 1], this means you have 5 sandwiches to give out.You can distribute them in the following order to the people : 2, 0, 1, 0. Giving these sandwiches to the people their hunger levels now become : [1, 1, 1, 1].The difference between each pair of people is now 0, the total is also 0, so your program should return 0. Note : You may not have to give out all, or even any, of your sandwiches to produce a minimized difference.

Another example : if arr is[4, 5, 2, 3, 1, 0] then you can distribute the sandwiches in the following order : [3, 0, 1, 0, 0] which makes all the hunger levels the following : [2, 2, 2, 1, 0].The differences between each pair of people is now : 0, 0, 1, 1 and so your program should return the final minimized difference of 2.
*/

#include <iostream>	
#include <string>	
using namespace std;

// Not Finished

int FoodDistribution(int arr[], int size) 
{

}

int main() 
{
	int A[] = { 5, 3, 1, 2, 1 };
	int B[] = { 4, 5, 2, 3, 1, 0 };
	cout << FoodDistribution(A, sizeof(A)/sizeof(A[0])); // 0
	cout << FoodDistribution(B, sizeof(B) / sizeof(B[0])); // 0
	return 0;

}