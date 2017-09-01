// For this challenge you will determine how to create evenly matched brackets.
/*
have the function RemoveBrackets(str) take the str string parameter being passed, which will contain only the characters "(" and ")", and determine the minimum number of brackets that need to be removed to create a string of correctly matched brackets. For example: if str is "(()))" then your program should return the number 1. The answer could potentially be 0, and there will always be at least one set of matching brackets in the string.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
traverse the string
any opening tags get stored in stack
if we have a closing tag compare it to the stack
If they match than pop the top value of our stack
if they do not match we will still add it to the stack
we will traverse the whole string and repeat the above steps
in the end if the stack has any elements in it, this signals the number of brackets we would need to remove
*/
int RemoveBrackets(string str)
{
	stack <char> list;

	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '(')
		{
			list.push(str[x]);
		}
		else if (str[x] == ')')
		{
			if (!list.empty() && list.top() == '(')
			{
				list.pop();
			}
			else
			{
				list.push(str[x]);
			}
		}
	}

	return list.size();
}

int main() 
{
	cout << RemoveBrackets("(())()(((") << endl; // 3
	cout << RemoveBrackets("(()(") << endl; // 2
	cout << RemoveBrackets("(()))") << endl; // 1
	cout << RemoveBrackets("))(()))") << endl; // 3
	cout << RemoveBrackets("(())") << endl; // 0
	return 0;
}