//////////////////////////////////////////////////////////*
/*	Joey Courseault
Tic Tac Toe Version 1.0
Data Structures - Dr. NG
Due Monday January 25, 2015
*/////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

////////problems
//keep count of wins, losses, draws ****

struct attributes	//struct to hold players attributes
{
	string name;
	string firstname;
	string lastname;
	char piece;
	int wins = 0;
	int losses = 0;
};

//-----GLOBAL CONSTANTS--------//
const int ROW = 3;
const int COL = 3;

////////Prototypes//////////////

void intro();
string nameformat(string);
void showboard(char[][COL], int);
void play(char[][COL], int, char, string);
bool win(char, char[][COL], int, string);
void showstats(string, int, int, int);
int checkwin(char[][COL], int, int);
int checktie(char board[][COL], int draw);

int main()
{
	attributes p1;		//struct object for first player
	attributes p2;		//struct object for second player
	char turn;
	char again = 'y';
	int draw = 0;
	bool winner = false;

	int p1win = 0;
	int p2win = 0;
	int p1total = 0;
	int p2total = 0;

	cout << "Welcome to Tic Tac Toe. \n";
	intro();	//initial display

	cout << "Player 1 enter your name: ";
	getline(cin, p1.firstname, ' ');	//gets first name until user enter space
	getline(cin, p1.lastname);
	p1.firstname = nameformat(p1.firstname);	//formats first name then stores in variable
	p1.lastname = nameformat(p1.lastname);		//formats last name then stores in variable
	p1.name = p1.firstname + ' ' + p1.lastname;		//stores first and last name in variable

	cout << "Player 2 enter your name: ";
	getline(cin, p2.firstname, ' ');		//gets first name
	getline(cin, p2.lastname);
	p2.firstname = nameformat(p2.firstname);		//formats name then stores in variable
	p2.lastname = nameformat(p2.lastname);			//formats last name and stores in variable
	p2.name = p2.firstname + ' ' + p2.lastname;		//stores first and last in variable

	cout << p1.firstname << " choose a piece, 'x' or 'o': ";

	while (true)	//input validation for piece selection
	{
		cin >> p1.piece;

		while (p1.piece != 'x' && p1.piece != 'o')
		{
			if (cin.get() != '\n')
			{
				while (p1.piece != 'x' && p1.piece != 'o')
				{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please reenter: ";
					cin >> p1.piece;
				}
			}
			cout << "Iput Error! Please reenter piece, either 'x' or 'o': ";
			cin >> p1.piece;
		}
		break;
	}

	turn = 'o';		//first play will be x

	if (p1.piece == 'x' || p1.piece == 'X')
	{
		p2.piece = 'o';
		cout << p1.firstname << " will be x and " << p2.firstname << " will be o. \n";
		cout << p2.firstname << "(o) will be first.\n";
	}
	else if (p1.piece == 'o' || p1.piece == 'O')
	{
		p2.piece = 'x';
		cout << p1.firstname << " will be o and " << p2.firstname << " will be x. \n";
		cout << p1.firstname << "(o) will be first.\n";
	}

	do
	{
		char board[ROW][COL] = { { '1', '2', '3' },		//initializes board members in 2D array
		{ '4', '5', '6' },
		{ '7', '8', '9' } };

		if (p1.piece == 'x')
		{
			while (!winner)
			{
				if (turn == 'o')
				{
					showboard(board, ROW);		//displays board
					play(board, COL, turn, p2.firstname);		//allows player to choose space on board
					winner = win(turn, board, ROW, p2.name);		//check for win or draw
					turn = 'x';		//switches turn
					p2.wins = checkwin(board, ROW, p2win);
					draw = checktie(board, draw);
				}
				else if (turn == 'x')
				{
					showboard(board, ROW);		//displays board
					play(board, COL, turn, p1.firstname);		//allows player to choose space on board
					winner = win(turn, board, ROW, p1.name);		//check for win or draw
					turn = 'o';		//changes turn
					p1.wins = checkwin(board, ROW, p1win);
					draw = checktie(board, draw);
				}
			}
		}
		else if (p1.piece == 'o')
		{
			while (!winner)
			{
				if (turn == 'o')
				{
					showboard(board, ROW);		//displays board
					play(board, COL, turn, p1.firstname);		//allows player to choose space on board
					winner = win(turn, board, ROW, p1.name);		//check for win or draw
					turn = 'x';		//changes turn
					p1.wins = checkwin(board, ROW, p1win);
					draw = checktie(board, draw);
				}
				else if (turn == 'x')
				{
					showboard(board, ROW);		//displays board
					play(board, COL, turn, p2.firstname);		//allows player to choose space on board
					winner = win(turn, board, ROW, p2.name);		//check for win or draw
					turn = 'o';		//changes turn
					p2.wins = checkwin(board, ROW, p2win);
					draw = checktie(board, draw);
				}
			}
		}
		p1total += p1.wins;
		p2total += p2.wins;


		//show stats for each player
		showstats(p1.name, p1total, p2total, draw);
		showstats(p2.name, p2total, p1total, draw);


		winner = false;		//to allow a replay of games
		cout << "Would you like to run again? Y/N ";
		cin >> again;
	} while (again == 'y' || again == 'Y');		//do while to see if players want to play again

	cout << "\n\n*********GAME OVER*************\n\n";

	system("pause");
	return 0;
}


//----------Function Defitions-------------//

//==============================================================
// Function name: void info
//Purpose: to tell user about the game
//pre condition: N/A
//post condition: N/A
//=============================================================
void intro()
{
	cout << "This is a two player board game. This game will get the names of the 2 users\nplaying";
	cout << " then will allow the players to choose two pieces 'x' or 'o'. The game\nis won by ";
	cout << "getting your 3 pieces in order on the same row, column or diagonal.\n";
}


//==============================================================
// Function name: nameformat
//Purpose: to capitoloze first letter and lowercase all preceeding characters
//pre condition: string name
//post condition: function returns string
//=============================================================
string nameformat(string name)
{
	name[0] = char(toupper(name[0]));

	for (int i = 1; i < name.length(); i++)
		name[i] = char(tolower(name[i]));
	return name;
}


//==============================================================
// Function name: showboard
//Purpose: to display the game board simply
//pre condition: 2d char array, with constants row(3) and column(3) 
//post condition: N/A
//=============================================================
void showboard(char board[][COL], int ROW)
{
	cout << "|---+---+---|\n";
	for (int i = 0; i < ROW; i++)
	{
		cout << "|";
		for (int j = 0; j < COL; j++)
			cout << " " << board[i][j] << " |";
		cout << "\n|---+---+---|\n";
	}
}


//==============================================================
// Function name: play
//Purpose: to get the space on the board the user wishes to play then switches piece
//pre condition: the char board array[3][3], the turn ('x' or 'o') and the players name who will be playing
//post condition: the sace on the board the player plays
//=============================================================
void play(char board[][COL], int ROW, char turn, string name)
{
	int space;
	int row = 0;
	int col = 0;

	if (turn == 'o')
		cout << name << "(o) turn. Enter board space you wish to play: ";

	if (turn == 'x')
		cout << name << "(x) turn. Enter board space you wish to play: ";
	cin >> space;

	bool validentry = false;
	while (!validentry)	//input validation for board space
	{
		switch (space)
		{
		case 1: row = 0, col = 0; validentry = true;
			break;
		case 2: row = 0, col = 1; validentry = true;
			break;
		case 3: row = 0, col = 2; validentry = true;
			break;
		case 4: row = 1, col = 0; validentry = true;
			break;
		case 5: row = 1, col = 1; validentry = true;
			break;
		case 6: row = 1, col = 2; validentry = true;
			break;
		case 7: row = 2, col = 0; validentry = true;
			break;
		case 8: row = 2, col = 1; validentry = true;
			break;
		case 9: row = 2, col = 2; validentry = true;
			break;
		default:
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "invalid input. enter space-";
				cin >> name;
			}
			else if (!cin.fail())
			{
				cout << "Invalid entry. please reenter space: ";
				cin >> space;
			}
		}
	}

	if (turn == 'o' && board[row][col] != 'o' && board[row][col] != 'x')
	{
		board[row][col] = 'o';
		turn = 'x';
	}

	else if (turn == 'x' && board[row][col] != 'o' && board[row][col] != 'x')
	{
		board[row][col] = 'x';
		turn = 'o';
	}
	else
	{
		cout << "The cell you chose is used! Try again\n";
		play(board, ROW, turn, name);
	}
}

//==============================================================
// Function name: win
//Purpose: the check to see if a player has won or is there a tie and increments number of wins and draws
//pre condition: the piece or turn, the board 2d array[3][3], the initial draw amount, initial
// player wins, initial player losses and the players name
//post condition: return the upper case winning combination if the game has been won, else returns false
//the game is not over
//=============================================================
bool win(char turn, char board[][COL], int ROW, string name)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])	//winning rows
		{
			board[i][0] = toupper(board[i][0]);
			board[i][1] = toupper(board[i][1]);
			board[i][2] = toupper(board[i][2]);
			cout << name << " has won the game\n";
			cout << "The winning combination\n";
			showboard(board, ROW);		//displays the winning combination
			return true;
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])		//winning columns
		{
			board[0][i] = toupper(board[0][i]);
			board[1][i] = toupper(board[1][i]);
			board[2][i] = toupper(board[2][i]);
			cout << name << " has won the game\n";
			cout << "The winning combination\n";
			showboard(board, ROW);		//displays the winning combination
			return true;
		}
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])	//diagonal win
		{
			board[0][0] = toupper(board[0][0]);
			board[1][1] = toupper(board[1][1]);
			board[2][2] = toupper(board[2][2]);
			cout << name << " has won the game\n";
			cout << "The winning combination\n";
			showboard(board, ROW);		//displays the winning combination
			return true;
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])		//diagonal win
		{
			board[2][0] = toupper(board[2][0]);
			board[1][1] = toupper(board[1][1]);
			board[0][2] = toupper(board[0][2]);
			cout << name << " has won the game\n";
			cout << "The winning combination\n";
			showboard(board, ROW);		//displays the winning combination
			return true;
		}
	}

	if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' && board[1][1] != '5'
		&& board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
	{
		cout << "Tie game\n";
		return true;
	}
	return false;
}


//==============================================================
// Function name: showstats
//Purpose: to show players wins, losses and draws
//pre condition: players name, wins, losses, and draws
//post condition: displays players stats
//=============================================================
void showstats(string name, int w, int l, int draw)
{
	cout << name << "\n----------------\n";
	cout << "Wins\t" << w << endl;
	cout << "Losses\t" << l << endl;
	cout << "Draw\t" << draw << endl;
}


//==============================================================
// Function name: check win
//Purpose: if player has won, add to their win total
//pre condition: board, row, and wins
//post condition: adds 1 to win
//=============================================================
int checkwin(char board[][COL], int ROW, int win)
{
	int w = win;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])	//winning rows
			w = 1;
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])		//winning columns
			w = 1;
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])	//diagonal win
			w = 1;
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])		//diagonal win
			w = 1;
		//else
		//return 0;
	}
	return w;
}


//==============================================================
// Function name: checktie
//Purpose: check for a draw, add to draw total
//pre condition: board and total draws
//post condition: adds 1 to draw
//=============================================================
int checktie(char board[][COL], int draw)
{
	int d = draw;
	if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' && board[1][1] != '5'
		&& board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
		d += 1;
	return d;
}
