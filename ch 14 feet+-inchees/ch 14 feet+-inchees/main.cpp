#include <iostream>   
#include "FeetInches.h"   
using namespace std;   

int main()
{
	int feet, inches;

	FeetInches first, second, third;

	cout << "Enter another distance in feet and inches: ";
	cin >> feet >> inches;
	second.setFeet(feet);
	second.setInches(inches);
	third = first + second;
	cout << "first + second = ";
	cout << third.getFeet() << " feet, ";
	cout << third.getInches() << " inches.\n";
	
	first.setFeet(feet);
	first.setInches(inches);
	
	if (first == second)  
		cout << "first is equal to second.\n";  
	if (first > second)  
		cout << "first is greater than second.\n";  
	if (first < second)
		cout << "first is less than second.\n";
	
	third = first - second;
	cout << "first - second = ";
	cout << third.getFeet() << " feet, ";
	cout << third.getInches() << " inches.\n";

	cout << "\nDemonstrating postfix ++ operator.\n";  
	for (int count = 0; count < 4; count++)
	{
		first = second++;
		cout << "first: " << first.getFeet() << " feet, ";
		cout << first.getInches() << " inches. ";
		cout << "second: " << second.getFeet() << " feet, ";
		cout << second.getInches() << " inches.\n";
	}
	
	for (int count = 0; count < 5; count++)  
	{  
		first = second++;  
		cout << "first: " << first.getFeet() << " feet, ";  
		cout << first.getInches() << " inches. ";  
		cout << "second: " << second.getFeet() << " feet, ";  
		cout << second.getInches() << " inches.\n";  
	}

	


	system("pause");
	return 0;
}
