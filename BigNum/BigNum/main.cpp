//Joey Courseault
//February 25, 2015
//Big Numbers Program
//Dr. Ng
//Data Structures 

//problems
//get sum formatted
//do multiplication

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//CONSTANT INTEGERS
const int NUM = 15;
const int LENGTH = 30;
#define OVERFLOW 2
#define ROW b_len
#define COL a_len+b_len + OVERFLOW

//Function Prototypes
void intro();
int valid_input(int, const int);
bool check_num(string);
void initializer(int arr[][LENGTH], const int NUM, int size, string n[]);
void show_addition(string num[], int);
void show_mult(string num[]);
void sum(string num[], int size, int arr[][LENGTH], const int NUM, int len);
string multiply(const string, const string);
void printhuge(string a);

int main()
{
	string n[NUM];
	int size, len = 0;
	bool valid = false;
	intro();
	int again;
	do
	{
		cout << "How many numbers will you be entering :  ";
		size = valid_input(2, LENGTH);	//call function to validate input
		int arr[NUM][LENGTH];		//create 2d array to hold the numbers with max lenght and max numbers as parameters
		initializer(arr, NUM, size, n);		//initialize the array
		for (int i = 0; i < size; i++)
		{
			while (!valid)
			{
				cout << "Enter number " << i + 1 << " : ";
				cin >> n[i];
				valid = check_num(n[i]);	//makes sure the user enters only numbers
			}
			valid = false;
		}
		for (int i = 0; i < size; i++)	//gets length of the largest number
		{
			if (n[i].length() > len)
				len = n[i].length();
		}

		cout << endl;
		show_addition(n, size);		//shows numbers to be added formatted
		sum(n, size, arr, NUM, len);		//shows the sum
		cout << "\n\n";
		show_mult(n);		//ultiplies first 2 numbers and shows them formatted

		string temp1;
		string temp2;

		temp1 = n[0];
		temp2 = n[1];
		printhuge(multiply(temp1, temp2));		//gets product of first 2 numbers

		cout << "Enter 0 to run again or 1 to quit: ";
		again = valid_input(0, 1);
		
	} while (again == 0);

	cout << "\n\n";

	system("pause");
	return 0;
}


/////////////////////////////////////////////////
//Function Name: intro
//Pre conditon: n/a
//Post condition: n/a
//Purpose: to show the purpose of the program
/////////////////////////////////////////////////
void intro()
{
	cout << "Welcome to the big number program" << endl;
	cout << "This program will allow you to enter up to " << NUM << " numbers and this program will add "; 
	cout << "the numbers then will multiply the first 2 the using the long multiplication \n";
	cout << "method where multiply 2 numbers by hand on paper " << endl;
	cout << "--------------------------------------------------------------------------------\n";
}


//==============================================================
// Function name: valid_input
//Purpose: for integer valid input
//pre condition: sends value to function, the min and max of the value
//post condition: return integer value
//=============================================================
int valid_input(int min, const int NUM)
{		//for input validation for amount of numbers to be entered
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
			if (num < min || num > NUM)
			{
				cout << "Error. Value must be between " << min << " & " << NUM;
				cout << "\nPlease reenter: ";
				cin >> num;
			}
			else
				return num;
		}
	}
}


/////////////////////////////////////////////////
//Function Name: check_num
//Pre conditon: the number entered
//Post condition: true or false condition
//Purpose: to find if the string entered was valid
/////////////////////////////////////////////////
bool check_num(string number)
{
	bool valid = true;
	if (number.empty())
	{
		cout << "Error, cant enter an empty digit\n";
		valid = false;
	}
	else if (number.length() > LENGTH)
	{
		cout << "Error, number lenght must be less than " << LENGTH << " digits\n";
		valid = false;
	}

	for (int i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
		{
			cout << "Error. Must enter digits only\n";
			valid = false;
			return valid;
		}
	}
	return valid;
}


/////////////////////////////////////////////////
//Function Name: initializer
//Pre conditon: uninitialize array of integers
//Post condition: initialized array
//Purpose: returns max lenght of all numbers
/////////////////////////////////////////////////
void initializer(int arr[][LENGTH], const int NUM, int size, string n[])
{	//initializes array to 0 and returns the length
	int len = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < LENGTH; j++)
			arr[i][j] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (n[i].length() > len)
			len = n[i].length();
	}
}


/////////////////////////////////////////////////
//Function Name: show_addition
//Pre conditon: n/a
//Post condition: n/a
//Purpose: to display the numbers in the correct format
/////////////////////////////////////////////////
void show_addition(string num[], int size)
{
	string temp[NUM];	//temp array so no change in the numbers
						//temp array to format the numbers
	for (int i = 0; i < size; i++)
		temp[i] = num[i];
	cout << "Here are the numbers you entered added up: \n\n";
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = temp[i].length(); j > 0 ; j--)		//inserts commas every 3 digits
		{
			if (count%3 == 0 && count !=0)
				temp[i].insert(j, 1, ',');
			count++;
		}
		if (i == size - 1)	//adds + sign to last nuumber line
		{
			cout << "+ ";
			cout << setw(LENGTH+10) << right << temp[i] << endl;
		}
		else
			cout << setw(LENGTH+12) << right << temp[i] << endl;
	}
	cout << "------------------------------------------\n";
}


/////////////////////////////////////////////////
//Function Name: show_mult
//Pre conditon: n/a
//Post condition: n/a
//Purpose: to show the correct multiplication format
/////////////////////////////////////////////////
void show_mult(string num[])
{
	string temp[2];		//temp to not change values of numbers
	for (int i = 0; i < 2; i++)
		temp[i] = num[i];
	int count = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = temp[i].length(); j > 0; j--)	//formats and adds commas
		{
			if (count % 3 == 0 && count != 0)
				temp[i].insert(j, 1, ',');
			count++;
		}
		count = 0;
	}

	cout << endl;
	cout << "The product of the first 2 numbers you entered: \n\n";
	cout << setw(LENGTH+15) << right << temp[0] << endl;
	cout << "* " << setw(LENGTH+13) << right << temp[1] << endl;
	cout << "---------------------------------------------\n";

}


/////////////////////////////////////////////////
//Function Name: sum
//Pre conditon: array of values 0
//Post condition: the sum of numbers
//Purpose: correctly take the numbers entered and add them to equal sum
/////////////////////////////////////////////////
void sum(string num[], int size, int arr[][LENGTH], int n, int len)
{
	int s[LENGTH];
	string temp[NUM];		//temp array to not change initial values
	for (int i = 0; i < size; i++)
		temp[i] = num[i];
	int l = len;
	for (int i = 0; i < size; i++)	//makes all number same size so you can add them
	{
		int l = temp[i].length();
		if (l < len)
		{
			int a = len - l;
			temp[i].insert(0, a, '0');
		}
		for (int j = 0; j < temp[i].length(); j++)
			arr[i][j] = temp[i][j] - '0';
	}

	for (int c = 0; c < len; c++)	//initialized the sum array
		s[c] = 0;
	int carry = 0;

	for (int j = len - 1; j >= 0; j--)
	{
		s[j] += carry;
		carry = 0;
		for (int i = 0; i < size; i++)
			s[j] += arr[i][j];
		carry = s[j] / 10;

		if (j > 0)
		{
			if (s[j] >= 10)
				s[j] = s[j] % 10;
			else if (s[j] >= 100)
			{
				s[j] = s[j] % 100;
				s[j] = s[j] % 10;
			}
		}
	}
	if (s[0] > 9)		//cleans up answer so commas will be formatted correctly
	{
		if (s[0] > 99)
		{
			for (int i = l - 1; i >= 0; i--)
				s[i+2] = s[i];
			s[2] = s[2] % 10;
			s[1] = s[0] / 10;
			s[1] = s[1] % 10;
			s[0] = s[0] / 100;
			l = l + 2;
		}
		else
		{
			for (int i = l; i >= 0; i--)
				s[i+1] = s[i];
			s[1] = s[1] % 10;	
			s[0] = s[0] / 10;
			l++;
		}
	}
	char s2[LENGTH];
	for (int i = 0; i < l; i++)		//turns int to char
		s2[i] = s[i] + '0';
	string totalsum;
	totalsum.append(s2, l);		//turns char array to string

	int count = 0;	
	for (int j = totalsum.length(); j > 0; j--)		//formats answer
	{
		if (count % 3 == 0 && count != 0)
			totalsum.insert(j, 1, ',');
		count++;
	}
		cout << setw(LENGTH + 12) << right << totalsum << endl;		//shows sum
} 


//============================================================
//Function Name: get_carry
//Pre conditon: a number which will determine wether there will be a carry value
//Post condition: the number to be carried
//Purpose: the num to find if there will be a carry
/////////////////////////////////////////////////
int getCarry(int num)
{
	int carry = 0;
	if (num >= 10) 
	{
		while (num != 0) 
		{
			carry = num % 10;	//gets what should be carried
			num = num / 10;		//gets remainder
		}
	}
	else carry = 0;
	return carry;
}

/////////////////////////////////////////////////
//Function Name: num
//Pre conditon: a char
//Post condition: the int value of the char
//Purpose: to convert char to int
/////////////////////////////////////////////////
int num(char a)
{
	return int(a) - '0';
}

/////////////////////////////////////////////////
//Function Name: multiply
//Pre conditon: 2 string of numbers to be multiplied
//Post condition: the product of the 2 numbers
//Purpose: multiply 2 numbers which are strings
/////////////////////////////////////////////////
string multiply(string a, string b)
{
	string ret;
	int a_len = a.length();
	int b_len = b.length();
	int **mat = new int*[ROW];		//pointer to dynamiclly allocate space
	for (int i = 0; i < ROW; i++)
		mat[i] = new int[COL];
	
	//int mat[ROW][COL];
	for (int i = 0; i<ROW; ++i)
	{
		for (int j = 0; j<COL; ++j) 
			mat[i][j] = 0;
	}

	int k = COL;
	int carry = 0, n, x = a_len - 1, y = b_len - 1;
	for (int i = 0; i<ROW; ++i) 
	{
		k = COL;
		x = a_len - 1;
		carry = 0;
		for (int j = (COL - 1) - i; j >= 0; --j) 
		{
			if ((x >= 0) && (y >= 0))  
			{
				n = (num(a[x])*num(b[y])) + carry;
				mat[i][j] = n % 10;
				carry = getCarry(n);
			}
			else if ((x >= -1) && (y >= -1)) 
				mat[i][j] = carry;
			x--;
		}
		y--;
	}
	string ans;
	for (int i = 0; i < ROW; i++)
	{
		ans = "";
		for (int j = 0; j < COL; j++)
			ans = ans + to_string(mat[i][j]);

		int count = 0;
		for (int j = ans.length(); j > 0; j--)		//inserts commas every 3 digits
		{
			if (count % 3 == 0 && count != 0)
				ans.insert(j, 1, ',');
			count++;
		}

		if (i==b_len-1)
			cout << "+ " << setw(LENGTH + 13) << right <<  ans;
		else
		cout << setw(LENGTH + 15) << right << ans;

		cout << endl;
	}
	carry = 0;
	int *sum_arr = new int[COL];
	for (int i = 0; i<COL; ++i) 
		sum_arr[i] = 0;
	for (int i = 0; i<ROW; ++i)
	{
		for (int j = COL - 1; j >= 0; --j) 
			sum_arr[j] += (mat[i][j]);
	}
	int temp;
	for (int i = COL - 1; i >= 0; --i) 
	{
		sum_arr[i] += carry;
		temp = sum_arr[i];
		sum_arr[i] = sum_arr[i] % 10;
		carry = getCarry(temp);
	}

	for (int i = 0; i<COL; ++i) 
		ret.push_back(char(sum_arr[i] + 48));

	while (ret[0] == '0')
		ret = ret.substr(1, ret.length() - 1);

	return ret;
}


/////////////////////////////////////////////////
//Function Name: print_huge
//Pre conditon: a string
//Post condition: n/a
//Purpose: print the content of the 2 strings which were multiplied
/////////////////////////////////////////////////
void printhuge(string a)
{
	cout << "---------------------------------------------\n";
	int count = 0;
	for (int j = a.length(); j > 0; j--)		//inserts commas every 3 digits
	{
		if (count % 3 == 0 && count != 0)
			a.insert(j, 1, ',');
		count++;
	}
	if (a.empty())
		cout << setw(LENGTH + 15) << right << "0";
	else
		cout << setw(LENGTH + 15) << right << a;
	cout << "\n\n\n";
}
