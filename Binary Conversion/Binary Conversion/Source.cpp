//Joey Courseault
//Computer Org Hmwk

#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int size = 7;		//variable declaration
	int arr[size];
	int total = 0;
	char again = 'y';

	do
	{
		cout << "This program converts 8 bit Binary Digit to its Decimal Value\n";

		for (int i = 0; i < size + 1; i++)	//gather user input for array
		{
			cout << "Enter digit " << i + 1 << ":\t";
			cin >> arr[i];

			while (arr[i] < 0 || arr[i] > 1)		//input validation
			{
				cout << "Input Error. Enter 0 or 1:\t";
				cin >> arr[i];
			}
		}

		cout << "The Binary Digit entered is ";

		for (int i = 0; i < size + 1; i++)	//display array elements
			cout << arr[i];
		cout << endl;

		for (int j = 7; j >= 0; j--)
		{
			total += arr[7 - j] * pow(2.0, j);
		}

		cout << "The decimal value is " << total << endl;
		total = 0;
		cout << "Would you like to run again? Y/N\t";
		cin >> again;
	} while (again == 'y' || again == 'Y');

	
	return 0;
}	