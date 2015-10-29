/*Joey Courseault
Chapter 14 number 1 numbers*/
#include <iostream>
#include <string>
using namespace std;

class Numbers
{
	int number;		//private members
public:	//static arrays to hold words
	static string lessthan20[20];
	static string tens[10];
	static string hundred;
	static string thousand;

	Numbers(int x){ number = x; }	//constructor

	void print();
};

//static variables defined outside the class
string Numbers::lessthan20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", };

string Numbers::tens[10] = { "zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety", };

string Numbers::hundred = "Hundred";
string Numbers::thousand = "thousand";

//TO print english word for the function
void Numbers::print()
{
	if (number < 0)
		cout << "minus ";

	//residue holds what remains to be printed
	int residue = number;
	
	//account for nonnegative numbers
	if (residue < 0)
		residue = -residue;

	//if any thousands
	int n_thousand = residue / 1000;

	residue = residue % 1000;
	if (n_thousand > 0)
		cout << " " << lessthan20[n_thousand] << " thousand ";

	//if any hundreds
	int n_hundreds = residue / 100;
	residue = residue % 100;
	if (n_hundreds > 0)
		cout << " " << lessthan20[n_hundreds] << " hundred ";

	//less than 100
	if (residue >= 20)
	{
		int n_tens = residue / 10;
		residue = residue % 10;
		if (n_tens > 0)
			cout << tens[n_tens];
		if (residue == 0) return;
	}
	// anything less than 20
	cout << " " << lessthan20[residue];
}

//main function
int main()
{
	int number;

	cout << "This program translates whole dollar amounts into words for the \n";
	cout << "for the purpose of writing checks.\n Enter a negative number to terminate the program.\n";
	cout << "Enter the amount to be translated: ";
	cin >> number;

	while (number >= 0)		//input validation
	{
		Numbers n(number);		//creates number object

		n.print();	//prints english description
		cout << endl;

		cout << "Enter another number: ";	//get another number
		cin >> number;
	}

	system("pause");
	return 0;
}