//////////////////////////////////////////////
//Joey Courseault							//
//Tic Tac Toe Projects Version 2.0			//
//Dr. Ng									//
//Data Structures and Algorithms			//
//Start Date: January 29, 2015				//
//Due Date: Friday, February 6th			//
//////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//struct variables for each player
struct attributes
{						
	string firstname;
	string lastname;
	string name;
	int wins = 0;
	int losses = 0;
	char piece;
};

//Global Constants
const int ROW = 11;
const int COL = 16;

//-----Prototypes------//
void intro();			//game instructions
void show_board(char board1[][COL], int ROW, int, int);		
void board_play(attributes&, char board1[][COL], int, int, int);
void get_name(attributes&, int);
int valid_input(int, int);
bool check_win(attributes&, char board1[][COL], int, int, int);
void show_stats(attributes [], int, int, int, int);

 int main()
{
	attributes player[5];	//array of structs
	int games_played = 0; int draw = 0; int count = 0;
	char quit;
	int num_players;

	intro();
	cout << "Enter number of players between 2 & 5: ";
	num_players = valid_input(2, 5);	//input validation

	char piece = 'a';
	for (int i = 0; i < num_players; i++)	//get players names and assigns pieces in order
	{
		get_name(player[i], i);
		player[i].piece = piece;
		piece++;
	}

	do
	{		//continue to loop for game
		char board1[11][16];
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
				board1[i][j] = ' ';
		}
		int row, col;
		cout << "Enter # of rows between 3 & 11: ";
		row = valid_input(3, 11);
		cout << "Enter # of columns between 3 & 16: ";
		col = valid_input(3, 16);


		bool winner = false;
		int plays = row * col;
		int num = 0;
		while (!winner && num < plays)		//play game until a player has won or tie
		{		
			show_board(board1, ROW, row, col);
			board_play(player[count], board1, ROW, row, col);
			winner = check_win(player[count], board1, ROW, row, col);
			if (winner)
				player[count].wins++;
			if (count == num_players - 1)
				count = 0;
			else
				count++;
			num++;
		}
		if (num == plays && !winner)
		{
			cout << "Game Ends in a Tie!\n";
			draw++;		
		}
		else
		{
			for (int a = 0; a < num_players; a++)
			{
				if (count == 0)
				{
					if (a != num_players - 1)
						player[a].losses++;
				}
				else if (a != count - 1)
					player[a].losses++;
			}
		}
		
		games_played++;
		show_board(board1, ROW, row, col);
		show_stats(player, games_played, num_players, draw, num_players);

		cout << "Would you like to run again?:Y/N  ";
		cin >> quit;
	} while (quit != 'n' && quit != 'N');
	cout << "\n\n*********END GAME*************\n\n";

	system("pause");
	return 0;
}

//==============================================================
// Function name: void info
//Purpose: to tell user about the game
//pre condition: N/A
//post condition: N/A
//=============================================================
void intro()
{
	cout << "This is a modified tic tac toe board game where there can be between\n2-5 players.";
	cout << "This game will get the names of all the users playing and players\npieces will be pre assigned.";
	cout << "the game board can be at minimum 3x3 and maximum\n11X16 game board. The standard rules ";
	cout << "on how the game is won remain the same, \nthe first player to getting your 3 pieces in ";
	cout << "order on the same row, column or \ndiagonal to win.\n------------------------------";
	cout << "-------------------------------------------------\n";
}

//==============================================================
// Function name: get_name
//Purpose: get the name of all the players and format them correctly
//pre condition: struct object
//post condition: first and last name of the players
//=============================================================
void get_name(attributes& player, int num)
{
	cout << "Player " << num+1 << " enter your full name: ";
	cin >> player.firstname >> player.lastname;
	player.firstname[0] = char(toupper(player.firstname[0]));
	player.lastname[0] = char(toupper(player.lastname[0]));
	for (int i = 1; i < player.firstname.length(); i++)
		player.firstname[i] = char(tolower(player.firstname[i]));
	for (int j = 1; j < player.lastname.length(); j++)
		player.lastname[j] = char(tolower(player.lastname[j]));
	player.name = player.firstname + ' ' + player.lastname;		//stores first and last name in variable
}

//==============================================================
// Function name: valid_input
//Purpose: for integer valid input
//pre condition: sends value to function, the min and max of the value
//post condition: return integer value
//=============================================================
int valid_input(int min, int max)
{
	int num;
	cin >> num;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered wrong input. Must enter numeric value: ";
			cin >> num;
		}
		else if (!cin.fail())
		{
			if (num < min || num > max)
			{
				cout << "Error. Value must be between " << min << " & " << max;
				cout << "\nPlease reenter: ";
				cin >> num;
			}
			else
				break;
		}
	}
	return num;
}

//==============================================================
// Function name: show_board
//Purpose: to display the game board
//pre condition: N/A
//post condition: N/A
//=============================================================
void show_board(char board1[][COL], int ROW, int r, int c)
{
	char letter = 'A';
	cout << " ";
	for (int i = 0; i < c; i++)
	{
		if (i>9)
			cout << "  " << i + 1;
		else
			cout << "   " << i + 1;
	}
	cout << "\n  ";
	for (int j = 0; j < c; j++)
		cout << " ---";
	cout << endl;
	for (int x = 0; x < r; x++)
	{
		cout << letter;
		for (int y = 0; y < c; y++)
			cout << " | " << board1[x][y];
		cout << " | " << letter << "\n  ";
		for (int j = 0; j < c; j++)
			cout << " ---";
		cout << endl;
		letter++;
	}
	cout << " ";
	for (int i = 0; i < c; i++)
	{
		if (i>9)
			cout << "  " << i + 1;
		else
			cout << "   " << i + 1;
	}
	cout << endl;
}

//==============================================================
// Function name: board_play
//Purpose: have the player choose a space on the board
//pre condition: the board before the player plays their piece on the board
//post condition: returns the board space the user entered
//=============================================================
void board_play(attributes& player, char board1 [][COL], int ROW, int row, int col)
{
	string space;
	int r=0, c=0;
	cout << player.firstname << " (" << player.piece << ") turn. Please enter board space: ";
	cin >> space;

	switch (space[0])
	{
	case 'a':
	case 'A': r = 0; break;
	case 'b':
	case 'B': r = 1; break;
	case 'c':
	case 'C': r = 2; break;
	case 'd':
	case 'D': r = 3; break;
	case 'e':
	case 'E': r = 4; break;
	case 'f':
	case 'F': r = 5; break;
	case 'g':
	case 'G': r = 6; break;
	case 'h':
	case 'H': r = 7; break;
	case 'i':
	case 'I': r = 8; break;
	case 'j':
	case 'J': r = 9; break;
	case 'k':
	case 'K': r = 10; break;
	default: {
				 cout << "Error, invalid board space. Please reenter.\n";
				 board_play(player, board1, ROW, row, col);	}
	}
	switch (space[1])
	{
	case '1': {if (space[2] > 0)
		switch (space[2])
	{
		case'0':c = 9; break;
		case'1':c = 10; break;
		case'2':c = 11; break;
		case'3':c = 12; break;
		case'4':c = 13; break;
		case'5':c = 14; break;
		case'6':c = 15; break;
		default: {
					 cout << "Error, invalid board space. Please reenter.\n";
					 board_play(player, board1, ROW, row, col);	}
	}
			  else
				  c = 0; break;	}
	case '2': c = 1; break;
	case '3': c = 2; break;
	case '4': c = 3; break;
	case '5': c = 4; break;
	case '6': c = 5; break;
	case '7': c = 6; break;
	case '8': c = 7; break;
	case '9': c = 8; break;
	default: board_play(player, board1, ROW, row, col);
	}
	if (r > row || c > col)
	{ 
		cout << "Error, space isnt valid!\n";
		board_play(player, board1, ROW, row, col);
	}

	else if (board1[r][c] != ' ')
	{
		cout << "Error, invalid board space. Please reenter.\n";
		board_play(player, board1, ROW, row, col);
	}
	else
		board1[r][c] = player.piece;
}

//==============================================================
// Function name: check_win
//Purpose: the check to see if a player has won or is there a tie and increments number of wins and draws
//pre condition: the piece or turn, the board 2d array[3][3], the initial draw amount, initial
// player wins, initial player losses and the players name
//post condition: return the upper case winning combination if the game has been won, else returns false
//the game is not over
//=============================================================
bool check_win(attributes &player, char board1[][COL], int ROW, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board1[i][j] == board1[i + 1][j] && board1[i + 1][j] == board1[i + 2][j] && board1[i][j] != ' ')		//winning row
			{
				board1[i][j] = char(toupper(board1[i][j]));
				board1[i+1][j] = char(toupper(board1[i+1][j]));
				board1[i+2][j] = char(toupper(board1[i+2][j]));
				cout << player.firstname << " has won the game\n";
				return true;
			}
			else if (board1[i][j] == board1[i][j + 1] && board1[i][j + 1] == board1[i][j + 2] && board1[i][j] != ' ')	//winning column
			{
				board1[i][j] = char(toupper(board1[i][j]));
				board1[i][j+1] = char(toupper(board1[i][j+1]));
				board1[i][j+2] = char(toupper(board1[i][j+2]));
				cout << player.firstname << " has won the game\n";
				return true;
			}
			else if (board1[i][j] == board1[i + 1][j + 1] && board1[i + 1][j + 1] == board1[i + 2][j + 2] && board1[i][j] != ' ')	//diagonal win
			{
				board1[i][j] = char(toupper(board1[i][j]));
				board1[i + 1][j+1] = char(toupper(board1[i + 1][j+1]));
				board1[i + 2][j+2] = char(toupper(board1[i + 2][j+2]));
				cout << player.firstname << " has won the game\n";
				return true;
			}
			else if (board1[i][j] == board1[i - 1][j + 1] && board1[i - 1][j + 1] == board1[i - 2][j + 2] && board1[i][j] != ' ')	//diagonal win
			{
				board1[i][j] = char(toupper(board1[i][j]));
				board1[i - 1][j+1] = char(toupper(board1[i - 1][j+2]));
				board1[i - 2][j+2] = char(toupper(board1[i - 2][j+2]));
				cout << player.firstname << " has won the game\n";
				return true;
			}
		}
	}
	return false;
}

//==============================================================
// Function name: show_stats
//Purpose: to display stats
//pre condition: N/A
//post condition: N/A
//=============================================================
void show_stats(attributes player[5], int games, int num, int draw, int num_players)
{
	cout << "\nTotal Games Played = " << games << endl;
	cout << "\t\t  WIN  LOSS  DRAW\n";
	cout << "\t\t ----- ----- -----\n";
	for (int i = 0; i < num_players; i++)
	{
		cout << setw(15) << left << player[i].name << " |  " << player[i].wins << "  |  " << player[i].losses;
		cout << "  |  " << draw << "  |" << endl;
		cout << "\t\t ----- ----- -----" << endl;
	}
	cout << endl;
}