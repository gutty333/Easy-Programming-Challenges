// For this challenge you will be determining the difference in hours and minutes between two given times.
// Take the num parameter being passed and return the number of hours and minutes the parameter converts to (ie. if num = 63 then the output should be 1:3). Separate the number of hours and minutes with a colon. 

#include <iostream>
#include <string>
using namespace std;

void TimeConvert(int num) {

	bool hour;
	int count = 0;

	do
	{
		hour = false;

		if (num >= 60)
		{
			count++;
			num -= 60;
			hour = true;
		}
	} while (hour);

	cout << count << ":" << num << endl;
}

int main() {

	// keep this function call here
	TimeConvert(63);
	TimeConvert(60);
	TimeConvert(120);
	return 0;

}