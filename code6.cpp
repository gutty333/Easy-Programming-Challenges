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
		if (sen[x] != ' ' && (int(sen[x]) >= 65 && int(sen[x]) <= 90) || (int(sen[x]) >= 97 && int(sen[x]) <= 122) || (int(sen[x] >= 48 && int(sen[x])<= 57)))
		{
			temp.push_back(sen[x]);
		}
		else
		{
			break;
		}
	}

	// Compare every other word in the string to the placeholder word we found
	// If that word is longer, replace and keep iterating
	for (int x = 0; x < sen.length(); x++)
	{
		if (sen[x] != ' ' && (int(sen[x]) >= 65 && int(sen[x]) <= 90) || (int(sen[x]) >= 97 && int(sen[x]) <= 122) || (int(sen[x] >= 48 && int(sen[x]) <= 57)))
		{
			// Find the new word before the next space
			temp2.push_back(sen[x]);

			// In the case that this is the last word in the string
			if (x + 1 == sen.length() && temp2.length() > temp.length())
			{
				temp = temp2;
			}
		}
		else
		{
			// Keep comparing the new temp word with the previous word
			// Clear the new temp word each time
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
	cout << LongestWord("hello") << endl;
	cout << LongestWord("Wow very beautiful") << endl; // beautiful
	cout << LongestWord("nice very cool") << endl; // nice
	cout << LongestWord("fun&!! time") << endl; // time
	cout << LongestWord("123456789 98765432") << endl;
	return 0;

}