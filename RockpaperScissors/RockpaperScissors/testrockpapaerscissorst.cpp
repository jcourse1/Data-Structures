/*Joey Courseault Program, original
chapter 6 program 4, number 44*/

#include <iostream>		//libraries used
#include <iomanip>
#include <ctime>
#include<cstdlib> 
using namespace std;

void Rock();		//function prototypes
void Paper();
void Scissors();

int compChoice = rand() % 3 + 1;	//global variable
int main()	//main function
{
	unsigned seed = time(0);	//Get a random number
	srand(seed);	//Seed the random number generator
	int userchoice;		
	
	char again;	//to run again

	do
	{
		cout << "Rock, Paper, Scissors Game against the computer.";
		cout << "\nType 1 for rock \n2 for paper \n3 for scissors" << endl;
		cin >> userchoice; //User enters choice here
		cout << compChoice << endl;

		if (userchoice == 1)
			Rock();
		if (userchoice == 2)
			Paper();
		if (userchoice == 3)
			Scissors();
		cout << "Play again? Y or N: \n";
		cin >> again;
	} while (again == 'Y' || again == 'y'); //ask user to play again

	return main();
	system("pause");
	return 0;	//end function
}

void Rock()
{
	if (compChoice == 1)		//for a tie
				cout << "We have picked the samething lets Rematch!!" << endl;
			else if (compChoice == 2)	
				cout << "Paper wraps rock, computer wins" << endl;
			else if (compChoice == 3)
				cout << "Rock smashes scissors, you win" << endl;
}
void Paper()
{
if (compChoice == 2)	//for a tie
				cout << "We have picked the samething lets Rematch!!" << endl;
			else if (compChoice == 1)		
				cout << "Paper wraps rock, you win" << endl;
			else if (compChoice == 3)
				cout << "Scissors cut paper, computer wins" << endl;
}
void Scissors()
{
			if (compChoice == 3)		//for a tie
				cout << "We have picked the samething lets Rematch!!" << endl;
			else if (compChoice == 2)
				cout << "Scissors cut paper, you win" << endl;
			else if (compChoice == 1)
				cout << "Rock smashes scissors, computer wins" << endl;
}