/*Joey Courseault
Rainfall Stats modicication
Modify the Rainfall Statistics program. The program should display
a list of months, sorted in order of rainfall, from highest to lowest*/

#include <iostream>
#include <string>
using namespace std;
//Function Porotypes
void sortArray(string[], int);
void showArray(const int[], int);

int main()
{
	double avgRainfall = 0;
	double totalRainfall = 0;
	double lowestRainfall;
	double highestRainfall;
	string lowestMonth;
	string highestMonth;
	string monthNames[] = { "January", "Febuary", "March", "April", "May", 
		"June", "July", "August", "September", "October", "November", "December" };
	double monthlyTotals[12];
	char repeat;

	do
	{
		cout << "Enter the rainfall for each month, in inches: " << endl;
		//Input and positive number validation
		for (int i = 0; i < 12; i++)
		{
			cout << monthNames[i] << ": ";
			cin >> monthlyTotals[i];

			while (monthlyTotals[i] < 0)
			{
				cout << "Please enter a positive number for " << monthNames[i] << endl;
				cin >> monthlyTotals[i];
			}
		}

		//Sum
		for (int i = 0; i < 12; i++)
		{
			totalRainfall = totalRainfall + monthlyTotals[i];
		}

		//Average
		avgRainfall = totalRainfall / 12;

		//Highest and Lowest months
		highestRainfall = monthlyTotals[0];
		lowestRainfall = monthlyTotals[0];
		highestMonth = monthlyTotals[0];
		//lowestMonth = monthlyTotals[0];

//sort array
		sortArray(monthNames, 12);

		for (int i = 0; i < 12; i++)
		{
			//Higest
			if (monthlyTotals[i] > highestRainfall)
			{
				highestRainfall = monthlyTotals[i];
				highestMonth = monthNames[i];
			}
			lowestMonth = monthlyTotals[0];
			//Lowestss
			if (monthlyTotals[i] < lowestRainfall)
			{
				lowestRainfall = monthlyTotals[i];
				lowestMonth = monthNames[i];
			}
		}

		//Output
cout << "The total rainfall throughout the year was " << totalRainfall << " inches." << endl;
cout << "The average rainfall for the entire year is " << avgRainfall;
cout << " inches." << endl;
cout << "The month with the lowest rainfall is " << lowestMonth;
cout << ", with a total of " << lowestRainfall << " inches." << endl;
cout << "The month with the highest rainfall is " << highestMonth;
cout << ", with a total of " << highestRainfall << " inches." << endl;

		//Reset the variables So that it can re-run
		avgRainfall = 0;
		totalRainfall = 0;
		lowestRainfall = 0;
		highestRainfall = 0;

		cout << "\nWould you like to run the program again? (Y/N) ";
		cin >> repeat;
		cout << endl;
	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

//Sort function
void sortArray(string array[], int size)
{
	bool swap;
	int temp;
	do
	{
		swap = false; 
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

//show function
void showArray(const int array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}