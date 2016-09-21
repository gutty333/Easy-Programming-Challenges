#include <iostream>
#include <string>
using namespace std;






int main()
{
	string password;
	bool pass, number;

	do
	{
		pass = true;
		number = false;

		cout << "Enter your password: ";
		getline(cin, password);

		// Password length
		if (password.length() < 6)
		{
			cout << "Please enter more than 6 characters" << endl;
			pass = false;
		}

		// Number 
		for (int x = 0; x < password.length(); x++)
		{
			if (password[x] >= '0' && password[x] <= '9')
			{
				number = true;
			}
		}
		if (!number)
		{
			cout << "Please include a number" << endl;
			pass = false;
		}
		cout << endl;
	} while (!pass);
	
	
	cout << endl << "Your account password is " << password << endl;

	return 0;
}