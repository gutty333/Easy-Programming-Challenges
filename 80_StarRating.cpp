// For this challenge you will be calculating how to display a 5 star rating.
/*
have the function StarRating(str) take the str parameter being passed which will be an average rating between 0.00 and 5.00, and convert this rating into a list of 5 image names to be displayed in a user interface to represent the rating as a list of stars and half stars. Ratings should be rounded up to the nearest half. There are 3 image file names available: "full.jpg", "half.jpg", "empty.jpg". The output will be the name of the 5 images (without the extension), from left to right, separated by spaces. For example: if str is "2.36" then this should be displayed by the following image:

So your program should return the string "full full half empty empty".
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


/*
first we would convert the string value to a float
we can set a loop to continuously subtract 1 or its fractional amount from the total value
For instance if value originally is 1.45
we subtract by 1 in first iteration
than subtract by .45 

*/
string StarRating(string str) 
{
	// converting the string
	istringstream convert(str);
	float value;
	convert >> value;

	string result="";
	int starCount = 0;

	// subtract by either 1 or a fraction of its value until we reach zero
	while (starCount < 5)
	{
		// if greater than or equal to one this will result in a full star 
		if (value >= 1)
		{
			result += "full ";

			// update our value
			value -= 1;
		}
		else if (value > 0)
		{
			if (value+.25 >= 1)
			{
				result += "full ";
			}
			else if (value+.25 >= .5)
			{
				result += "half ";
			}
			else
			{
				result += "empty ";
			}

			value -= value;
		}
		else
		{
			// empty star
			result += "empty ";
		}

		starCount++;
	}

	return result;
}

int main() 
{
	cout << StarRating("2.36") << endl; // full full half empty empty
	cout << StarRating("0.38") << endl; // half empty empty empty empty
	cout << StarRating("4.5") << endl; // full full full full half
	cout << StarRating("3.02") << endl; // full full full empty empty
	cout << StarRating("2.75") << endl; // full full full empty empty
	
	return 0;
}