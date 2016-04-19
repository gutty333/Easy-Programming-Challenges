// For this challenge you will return the total number of minutes between two times.
// have the function CountingMinutesI(str) take the str parameter being passed which will be two times (each properly formatted with a colon and am or pm) separated by a hyphen and return the total number of minutes between the two times. The time will be in a 12 hour clock format. For example: if str is 9:00am-10:00am then the output should be 60. If str is 1:00pm-11:00am the output should be 1320. 


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int CountingMinutesI(string str) {

	string num1, num2;
	string hour1, hour2, min1, min2;
	int index = str.find('-');
	bool colon = false;

	for (int x = 0; x < str.length(); x++)
	{
		if (x >= index)
		{
			// Reset the colon to false
			// Since we are now analyzing the second time
			colon = false;
			for (x; x < str.length(); x++)
			{
				if (str[x] == ':')
				{
					colon = true;
					continue;
				}

				// Check if it is am or pm
				if (str[x] == 'a' || str[x] == 'p')
				{
					num2.push_back(str[x]);
					num2.push_back(str[x + 1]);
				}

				// Find the number for the hour and the minutes
				if (colon && isdigit(str[x]))
				{
					min2.push_back(str[x]);
				}
				else if (isdigit(str[x]))
				{
					hour2.push_back(str[x]);
				}
			}
		}
		else
		{
			// If colon is found this will help signify we are now taking in the minutes
			if (str[x] == ':')
			{
				colon = true;
				continue;
			}

			// Check if it is am or pm
			if (str[x] == 'a' || str[x] == 'p')
			{
				num1.push_back(str[x]);
				num1.push_back(str[x + 1]);
			}

			// Find the number for the hour and the minutes
			if (colon && isdigit(str[x]))
			{
				min1.push_back(str[x]);
			}
			else if (isdigit(str[x]))
			{
				hour1.push_back(str[x]);
			}
		}
	}

	// Finding the hour between the time
	int hour = 0;
	/*
	In the case that it is an older version of C++
	we can use the stream for conversion
	int h1, h2, m1, m2;
	istringstream(min1) >> m1;
	istringstream(min2) >> m2;
	istringstream(hour1) >> h1;
	istringstream(hour2) >> h2;*/
	
	// Various condition to determine the calculation
	// For example in the case that we have a 24 hr relapse, etc
	if (stoi(hour1) == stoi(hour2) && num1 == num2 && stoi(min1) > stoi(min2))
	{
		hour = 24 - (stoi(hour1) - stoi(hour2));
	}
	else if (stoi(hour1) > stoi(hour2) && num1 == num2 && stoi(min1) < stoi(min2))
	{
		hour = 24 - (stoi(hour1) - stoi(hour2));
	}
	else if (num1 == num2 || (hour2 == "12" && hour1 != "12"))
	{
		hour = stoi(hour2) - stoi(hour1);
	}
	else
	{
		hour = (12 - stoi(hour1)) + stoi(hour2);
	}

	// Calculation
	int time;
	if (min1 != "00")
	{
		time = (hour * 60 - stoi(min1)) + stoi(min2);
	}
	else
	{
		time = (hour * 60 + stoi(min1)) + stoi(min2);
	}

	return time;
}

int main() {

	// keep this function call here
	cout << CountingMinutesI("12:30pm-12:00am") << endl; // 690 
	cout << CountingMinutesI("1:23am-1:08am") << endl; // 1425
	cout << CountingMinutesI("12:31pm-12:34pm") << endl; // 60
	cout << CountingMinutesI("2:03pm-1:39pm") << endl; // 1416
	cout << CountingMinutesI("1:00pm-11:00am") << endl; // 1320
	return 0;

}

/*Note: Looking back at the code this could have been better simplifies by utilizing various string methods
Example to find the time we could do

break = str.find('-')

break the times
string1 = str.substr(0,break)
string2 = str.substr(break+1)

colon = string1.find(':')
colon2 = string2.find(':')

hour1 = string1.substring(0,colon);
min1 = string1.substring(colon+1);
Same would apply to the other time, overall this eliminates the need for a loop and can just focus on calculations
*/