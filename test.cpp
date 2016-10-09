#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	cout << "ENTER A NUMBER: ";
	cin >> num;

	int* list;
	list = new int [num];

	for (int x = 0; x < num; x++)
	{
		list[x] = x * 5;
		cout << x + 1 << ". " << list[x] << endl;
	}

	delete[]list;
	list = 0;

	cout << endl;
	return 0;
}