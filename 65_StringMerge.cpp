// For this challenge you will be merging two different strings together.
/*
have the function StringMerge(str) read the str parameter being passed which will contain a large string of alphanumeric characters with a single asterisk character splitting the string evenly into two separate strings. Your goal is to return a new string by pairing up the characters in the corresponding locations in both strings. For example: if str is "abc1*kyoo" then your program should return the string akbyco1o because a pairs with k, b pairs with y, etc. The string will always split evenly with the asterisk in the center.
*/

#include <iostream>
#include <string>
using namespace std;

/*
split the string into 2
after combine the 2 strings into one doing a step by step merge alternating between the 2
*/

string StringMerge(string str) 
{
	int middle = str.find("*");

	string first = str.substr(0, middle);
	string second = str.substr(middle+1, str.size() - middle);
	string result;

	for (int x = 0; x < middle; x++)
	{
		result.push_back(first[x]);
		result.push_back(second[x]);
	}

	return result;
}

int main() 
{
	cout << StringMerge("abc1*kyoo") << endl; // akbyco1o
	cout << StringMerge("aaa*bbb") << endl; // ababab
	cout << StringMerge("123hg*aaabb") << endl; // 1a2a3ahbgb
	return 0;

}