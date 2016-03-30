// For this challenge you will be determining the largest word in a string.

#include <iostream>
#include <string>
using namespace std;

string LongestWord(string sen) {

	string temp;
	string temp2;

	// Find the first word in the string
	for (int x = 0; x < sen.length(); x++)
	{
		if (sen[x] != ' ' && (int(sen[x]) >= 65 && int(sen[x]) <= 90) || (int(sen[x]) >= 97 && int(sen[x]) <= 122))
		{
			temp.push_back(sen[x]);
		}
		else
		{
			break;
		}
	}

	// Compare every other word in the string to the placeholder word we found
	// If that word longer, replace and keep iterating
	for (int x = 0; x < sen.length(); x++)
	{
		if (sen[x] != ' ' && (int(sen[x]) >= 65 && int(sen[x]) <= 90) || (int(sen[x]) >= 97 && int(sen[x]) <= 122))
		{
			temp2.push_back(sen[x]);

			if (x + 1 == sen.length() && temp2.length() > temp.length())
			{
				temp = temp2;
			}
		}
		else
		{
			if (temp2.length() > temp.length())
			{
				temp = temp2;
			}

			temp2.clear();
		}
	}
  
	return temp;
}

int main() {

	// keep this function call here
	cout << LongestWord("itsdsfsfs lovdsdsadsae dogsss  testi!!!!!!!!!!!!!!@!#@#@#@#@#@#@#@#@!!!! helllo whatisgoingonherenowthisiscrazy who did this");
	cout << endl;
	return 0;

}