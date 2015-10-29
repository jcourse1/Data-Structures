//Joey Courseault
//Infix/Postfix Program
//Dr. Ng
//April 23, 2015

#include<iostream>
#include<string>
using namespace std;

//FIX LAST EXPRESSION. CONVERT LETTERS TO NUMBERS

//struct for linked list implementation of stack
struct node
{
	char data;
	node *next;
};

//====================================================
//Fuunction Name: push
//Function Purpose: push item onto stack
//====================================================
node* push(node *top, char x)
{
	node *p = new node();
	node *save = new node();
	p->data = x;
	p->next = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		save = top;
		top = p;
		p->next = save;
	}
	return top;
}

node* push2(node *top, int x)
{
	node *p = new node();
	node *save = new node();
	p->data = x;
	p->next = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		save = top;
		top = p;
		p->next = save;
	}
	return top;
}

//====================================================
//Fuunction Name: pop
//Function Purpose: remove top element from stack
//====================================================
void pop(node **top)
{
	node *ptr = new node();
	if (*top == NULL)
		cout << "underflow!!";
	else
	{
		ptr = *top;
		*top = (*top)->next;
		delete ptr;
	}
}

//====================================================
//Fuunction Name: top
//Function Purpose: peek stack operartion
//returns top element without deletion
//====================================================
char top(node *top1)
{
	if (top1 == NULL)
		return 0;
	else
		return top1->data;
}

//====================================================
//Fuunction Name: empty
//Function Purpose: return wether stack is empty
//====================================================
int empty(node *top)
{
	if (top == NULL)
		return 1;
	else 
		return 0;
}


//====================================================
//Fuunction Name: getweight
//Function Purpose: get weight of operators as per precedence higher weight
//given to operators with higher precedence for non operators, return 0
//====================================================
int get_level(char c)
{
	switch (c)
	{
	case '/':
	case '*': return 2;
	case '+':
	case '-': return 1;
	default: return 0;
	}
}

//====================================================
//Fuunction Name: infix_2_postfix
//Function Purpose: convert infix expression to postfix using a stack
//====================================================
string infix_2_postfix(string infix)
{
	string postfix;
	int level;
	int x = 0;
	char c;
	int size = infix.length();
	node *st = NULL;
	// iterate through expression
	while (x < size)
	{
		c = infix[x];
		if (c == '(') 
		{
			st = push(st, c);
			x++;
			continue;
		}
		if (c == ')') //pop elements to end section and append elements
		{
			while (!empty(st) && top(st) != '(')
			{
				postfix += top(st);
				pop(&st);

			}
			if (!empty(st)) //removes opening parenthesis
				pop(&st);

			x++;
			continue;
		}
		level = get_level(c);
		if (level == 0)
			postfix += c;
		else	//operation found
		{
			if (empty(st)) //adds element to stack		
				st = push(st, c);
	
			else 
			{
				// pops all elements of lower precedence
				while (!empty(st) && top(st) != '(' &&
					level <= get_level(top(st)))
				{
					postfix += top(st);
					pop(&st);
				}
				// push the current operator onto stack
				st = push(st, c);
			}
		}
		x++;
	}
	//pops elements left over. end with empty stack
	while (!empty(st))
	{
		postfix += top(st);
		pop(&st);
	}
	return postfix;
}


//====================================================
//Fuunction Name: valid_input
//Function Purpose: validated input for menu options
//====================================================
int valid_input(int min, int max)
{
	bool valid = false;
	int n;
	string s;
	do
	{
		cin >> s;
		if (s.length() > 1)
			cout << "Error! Please input a valid menu choice. Please re-enter\n";
		else
		{
			n = s[0] - '0';
			if (n > max)
				cout << "Error! Please input valid menu choice between 1-4. Please re-enter\n";
			else
				valid = true;
		}

	} while (!valid);
	return n;
}


/*=========================================================
Name: base
Purpose: Converts from base 10 to base 36
===========================================================*/
int base(char c)
{
	int a;
	if (c >= '0' && c <= '9')
		a = c - '0';
	else if (c >= 'a' && c <= 'z')
		a = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		a = c - 'A' + 10;
	return a;
}

//Prototypes
bool Operator_check(char C);
bool Operand_check(char C);
int evaluator(string x);
string convertor(int num);


/*=====================================================
Fucntion Name: valid_exp
Purpose: make sure expression consist of correct values
=======================================================*/
string valid_exp()
{
	bool valid = false;
	string exp;
	while (!valid)
	{
		cin >> exp;
		valid = true; 
		if (exp.length() < 1)
			valid = false;
		else
		{
			for (int i = 0; i < exp.length() && valid; i++)
			{
				if (!Operand_check(exp[i]) && !Operator_check(exp[i]) && exp[i] != '(' && exp[i] != ')')
				{
					valid = false;
					cout << "Error! Values entered must be either numbers, letters, '+', '-', '*' or '/'\n";
					cout << "Please re-enter : ";
				}
			}
		}
	}
	return exp;
}

int main()
{
	int choice, answer;
	string expression, postexp, res;
	char c;
	
	do
	{
		cout << "Please Select one of the following options:\n";
		cout << "\t1) Read in an infix expression and convert to postfix form\n";
		cout << "\t2) Read in a postfix expression and evaluate the postfix expression\n";
		cout << "\t3) Read in infix expression, convert to postfix form then evaluate \n";
		cout << "\t4) Exit";
		cout << "\nEnter your choice:\t";
		choice = valid_input(1, 4);

		switch (choice)
		{
		case 1:
			cout << "\nEnter Infix Expression :  ";
			cin.ignore(256, '\n');
			expression = valid_exp();
			postexp = infix_2_postfix(expression);
			cout << "\nThe postfix expression is ---> " << postexp << "\n";
			break;

		case 2:
			cout << "\nEnter Postfix Expression :  ";
			cin.ignore(256, '\n');
			expression = valid_exp();
			answer = evaluator(expression);
			if (answer<0)
				cout << "\nThe postfix evaluation is ---> " << answer << "\n";
			else
			{
				res = convertor(answer);
				cout << "\nThe postfix evaluation is ---> " << res << "\n";
			}
			break;

		case 3:
			cout << "\nEnter Infix Expression :  ";
			cin.ignore(256, '\n');
			getline(cin, expression);
			postexp = infix_2_postfix(expression);

			answer = evaluator(postexp);
			if (answer<0)
				cout << "\nThe postfix evaluation is ---> " << answer << "\n";
			else
			{
				res = convertor(answer);
				cout << "\nThe postfix evaluation is ---> " << res << "\n";
			}
			break;

		case 4:
			break;

		default:
			cout << "\nInvalid Input";
			cout << "\n Enter your choice:\t";
			cin >> choice;
			break;
		}
		cout << endl;
	} while (choice != 4);

	cout << endl;
	system("pause");
	return 0;
}


//====================================================
//Fuunction Name: converter
//Function Purpose: takes number and converts to base 36
//====================================================
string convertor(int num)
{
	string result, digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (; num; num /= 36)
	{
		result.insert(result.begin(), digits[num % 36]);
	}
	return result;
}


//====================================================
//Fuunction Name: evaluator
//Function Purpose: evaluates postfix expression
//====================================================
int evaluator(string s)
{
	node *st = NULL;
	int a, b;
	int x;	
	for (int i = 0; i <s.length(); i++)
	{
		if (Operand_check(s[i]))
		{
			st = push(st, s[i]);
		}
		else if (Operator_check(s[i]))
		{
			if (!empty(st))
			{
				a = top(st) - '0';
				pop(&st);
			}
			else
			{
				cout << "\nError.. Wrong input";
				break;
			}
			if (!empty(st))
			{
				b = top(st) - '0';
				pop(&st);
			}
			else
			{
				cout << "\nError.. Wrong input";
				break;
			}
			int val;
			char ans;

			switch (s[i])
			{
			case '+':
				val = a + b;
				ans = val + '0';
				st = push(st, ans);
				break;
			case '-':
				val = b - a;
				ans = val + '0';
				st = push(st, ans);
				break;
			case '*':
				val = a*b;
				ans = val + '0';
				st = push(st, ans);
				break;
			case '/':
				val = b / a;
				//if (a == 0)
					//abort operation b/c division by 0
				ans = val + '0';
				st = push(st, ans);
				break;
			}
		}
		else
			cout << "Error! input incorrect format!\n";
	}
	int q = (top(st) - '0');
	pop(&st);
	return q;
}


//=======================================================================
//Fuunction Name: operaand check
//Function Purpose: Verifies whether a character is alphanumeric 
//character (letter or numeric digit) or not.
//======================================================================= 
bool Operand_check(char C)
{
	if ((C >= '0' && C <= '9') || (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z')) 
		return true;
	else
		return false;
}


//====================================================
//Fuunction Name: operator check
//Function Purpose: Function to verify whether a 
//character is operator symbol or not.
//====================================================
bool Operator_check(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	else
		return false;
}


/*
Infix: Postfix:
A+B AB+
A+B-C AB+C-
A*B-C AB*C-
A+B*C ABC*+
(A+B)*C AB+C*
(A+B)/(C-D) AB+CD-/
A+B/C-D ABC/+D-
A*B+(C-D/E) AB*CDE/-+
A*B+C/D-E AB*CD/+E-
A*B+C/(D-E) AB*CDE-/+
A*(B+C/(D-E)) ABCDE-/+*

12+3* -> 9
123*+ -> 7
12*3+ -> 5
12-34*+ -> B
123*-4+ -> -1
15431-/+* -> 7
25*431-/+ -> C
AB* -> 32 ...1E
and ab* = -110
*/


