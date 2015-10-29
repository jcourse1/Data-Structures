#include <iostream>
using namespace std;

int recursiveMult(int num1, int num2)
{
	if (num2 == 1)
		return num1;
	else
		return num1 + recursiveMult(num1, num2 - 1);
}

int main()
{
	int numOne, numTwo;
	cout << "Num1: ";
	cin >> numOne;
	cout << "Num2: ";
	cin >> numTwo;

	cout << recursiveMult(numOne, numTwo) << endl;

	system("pause");
	return 0;
}