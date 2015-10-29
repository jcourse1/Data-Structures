
#include <iostream>
#include <string>
using namespace std;

double divide(int, int);

int main()
{
	int num1, num2;
	double quotient;
	int again = 0;

	while (again == 0)
	{
	cout << "Enter 2 numbers\t";
	cin >> num1 >> num2;

	try
	{
		quotient = num1 / num2;
		cout << "The quotient is " << quotient;
		cout << endl;
	}
	catch (string exceptionstring)
	{
		cout << exceptionstring;
		
	}
	cout << "enter 0 to run again";
	cin >> again;
	cout << endl;
	}
	cout << "End";

	system("pause");
	return 0;
}

double divide(int numerator, int denominator)
{
	if (denominator == 0)
	{
		string exceptionstring = "Error!\n";
		throw exceptionstring;
	}
	return static_cast<double>(numerator) / denominator;
} 