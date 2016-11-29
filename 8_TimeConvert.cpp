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

		// Check how many hours are in the argument
		// Will continue to loop until we are only left with minutes (x < 60)
		// Looking back at this problem the other more basic method is
		// argument/60 to find hour and argument/60 remainder to find minutes
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