// For this challenge you will be searching for the smallest time difference.
// have the function TimeDifference(strArr) read the array of strings stored in strArr which will be an unsorted list of times in a twelve-hour format like so: HH:MM(am/pm). Your goal is to determine the smallest difference in minutes between two of the times in the list. For example: if strArr is ["2:10pm", "1:30pm", "10:30am", "4:42pm"] then your program should return 40 because the smallest difference is between 1:30pm and 2:10pm with a difference of 40 minutes. The input array will always contain at least two elements and all of the elements will be in the correct format and unique. 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

void bubbleSort(vector <double>& list,int size)
{
	double temp;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size-1; x++)
		{
			if (list[x] > list[x + 1])
			{
				temp = list[x];
				list[x] = list[x + 1];
				list[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}


double TimeDifference(string strArr[], int size) 
{
	// List holding the time in 24 hour format as ints for ordering later
	vector <double> newTime;

	// Convert the string values to int
	for (int x = 0; x < size; x++)
	{
		double tempNum;
		string temp = "";
		int colon = strArr[x].find(':');
		bool morning=false;

		// Finding the hour
		for (int y = 0; y < colon; y++)
		{
			if (strArr[x][y] >= '0' && strArr[x][y] <= '9')
			{
				temp += strArr[x][y];
			}
		}

		// Check for either AM/PM
		if (strArr[x].find('a') != -1)
		{
			morning = true;
		}

		// Analyzing the hour for 12am since we are working with military time
		if (temp == "12" && strArr[x].find('a') != -1)
		{
			temp = "00";
		}
		temp += ".";

		// Finding the minutes
		for (colon; colon < strArr[x].length(); colon++)
		{
			if (strArr[x][colon] >= '0' && strArr[x][colon] <= '9')
			{
				temp += strArr[x][colon];
			}
		}

		// Converting our string to a double
		istringstream(temp) >> tempNum;
		if (!morning) // Adjust the time to 24 hours format
		{
			tempNum += 12;
		}
		newTime.push_back(tempNum);
	}

	// Sort our number, this will make it easier to check for our smallest difference
	bubbleSort(newTime,size);

	double result = 200 * 200; // Just temp/garbage value we will use later to compare and find the lowest difference
	for (int x = 0; x < size; x++)
	{
		// Used to extract the decimal and fraction values from our newTime value
		double difference;
		double decimal1, decimal2;
		double fraction1, fraction2;

		if (x == size - 1) // In the case we reach the end, we should also compare the first and last time values
		{
			fraction1 = modf(newTime[x], &decimal1);
			fraction2 = modf(newTime[0], &decimal2);
			difference = (24.00 + newTime[0]) - newTime[x];
		}
		else
		{
			fraction1 = modf(newTime[x], &decimal1);
			fraction2 = modf(newTime[x + 1], &decimal2);
			difference = newTime[x + 1] - newTime[x];
		}
		
		if (fraction2 < fraction1)
		{
			difference -= 0.4;
		}
		
		// Converting our difference result to minutes
		// The decimal will represent the hour and fraction will represent minutes
		fraction1 = modf(difference, &decimal1);
		decimal1 *= 60;
		fraction1 *= 100;
		difference = decimal1 + fraction1;

		// Keep track of the lowest difference
		if (difference < result)
		{
			result = difference;
		}
	}
	
	return result;
}

int main() 
{
	string A[] = { "2:10pm", "1:30pm", "10:30am", "4:42pm" };
	string B[] = { "1:10pm", "4:40am", "5:00pm" };
	string C[] = { "10:00am", "11:45pm", "5:00am", "12:01am" };
	cout << TimeDifference(A, sizeof(A)/sizeof(A[0])) << endl; // 40
	cout << TimeDifference(B, sizeof(B) / sizeof(B[0])) << endl; // 230
	cout << TimeDifference(C, sizeof(C) / sizeof(C[0])) << endl; // 16
	return 0;
}