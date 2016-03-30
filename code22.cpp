// For this challenge you will be manipulating a string using dashes (-).
// have the function DashInsert(str) insert dashes ('-') between each two odd numbers in str. For example: if str is 454793 the output should be 4547-9-3. Don't count zero as an odd number. 

#include <iostream>
#include <string>
using namespace std;


string DashInsert(string str) {

	string temp2 = str;

	for (int x = 0; x < str.length() - 1; x++)
	{
		if ((str[x] == '1' || str[x] == '3' || str[x] == '5' || str[x] == '7' || str[x] == '9') && (str[x + 1] == '1' || str[x + 1] == '3' || str[x + 1] == '5' || str[x + 1] == '7' || str[x + 1] == '9'))
		{
			temp2.insert(x+1,"-");
			str = temp2;
		}
	}

	return temp2;
}

int main() {

	// keep this function call here
	cout << DashInsert("454793") << endl; // 4547-9-3
	cout << DashInsert("99946") << endl; // 9-9-946
	cout << DashInsert("56730") << endl; // 567-30
	cout << DashInsert("157967350") << endl; // 1-5-7-967-3-50
	return 0;

}
