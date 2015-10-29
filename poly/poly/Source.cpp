//Joey Courseault
//April 1, 2015
//Data Structures and Algorith Analysis
//Dr. Ng
//=======Polynomial Program============//

#include<iostream>
#include <string>
using namespace std;

struct ATerm
{
	int  Coefficient;
	int  Exponent;
	ATerm  *Next;
};
typedef  ATerm  *Polynomial;
const int MAX = 10;

//problems
//exponent greater then 10
//put multiplication addition part together


//=============================================================================
//Function Name: valid_input
//Pre conditon: n/a
//Post condition: returns int
//Purpose: validates input
//===============================================================================
int valid_input()
{
	int n = 0; string m;
	bool input;
	do
	{
		cin >> m;
		if (m.empty())
			input = false;
		else if (m.length() == 2 && m[0] == '1' && m[1] == '0')
		{
			input = true;
			n = 10;
		}
		else if (m.length() > 1)
		{
			cout << "Error, value must be greater than 0 and less than " << MAX << endl;
			cout << "Please re-enter\n";
			input = false;
		}
		else
		{
			n = m[0] - '0';
			input = true;
		}
	} while (!input);
	return n;
}

//=============================================================================
//Function Name: format input
//Pre conditon: string array holding polynomials and the size
//Post condition: N/A
//Purpose: displays the formatted input as specified
//===============================================================================
void format_input(string s[], int size, int a)
{
	//take initial string that was inputted and output in correct formt with parenthesis
	for (int j = 0; j < size; j++)
	{
		for (int i = s[j].length() - 1; i >= 0; i--)
		{
			if (s[j][i] == '+' || s[j][i] == '-')
			{
				s[j].insert(i + 1, 1, ' ');
				s[j].insert(i, 1, ' ');
			}
		}
		if (a == 1)		//to add parenthesis for readable format once
		{
			string beg = "( ";
			string end = " )";
			s[j].insert(0, beg);
			s[j].insert(s[j].length(), end);
		}
		if (j != size - 1)			//for formatting
		{
			if (a == 1)
				cout << s[j] << " + ";
			else if (a == 2)
				cout << s[j] << " * ";
		}
		else
			cout << s[j];
	}
}

//=============================================================================
//Function Name: print
//Pre conditon: the polynomial object
//Post condition: n/a
//Purpose: the answer displayed
//===============================================================================
void show_poly(Polynomial poly)
{
	if (poly->Coefficient<0)
		cout << "-";
	while (poly->Next != NULL)		//iterates through polynomial
	{
		if (poly->Next->Coefficient>0)		//for positive exponent
		{
			if (poly->Exponent != 1)
				cout << abs(poly->Coefficient) << "x^" << poly->Exponent << " + ";
			else
				cout << abs(poly->Coefficient) << "x + ";
		}
		else
		{				//for negative exponent
			if (poly->Exponent != 1)		
				cout << abs(poly->Coefficient) << "x^" << poly->Exponent << " - ";
			else
				cout << abs(poly->Coefficient) << "x - ";
		}
		poly = poly->Next;	//iterates through string pointer
	}
	if (poly->Exponent == 1)
		cout << abs(poly->Coefficient) << "x";
	else if (poly->Exponent == 0)
		cout << abs(poly->Coefficient);
	else
		cout << poly->Coefficient << "x^" << poly->Exponent;
	cout << endl;
}

//=============================================================================
//Function Name: get_carry
//Pre conditon: the polynomial product, coefficient and exponent
//Post condition: returns the pollynomial
//Purpose: when 2 polynomials gets added, this returns the polynomial
//===============================================================================
Polynomial insert_s(Polynomial start, int coeff, int exp)
{
	Polynomial ptr, tmp;
	tmp = (Polynomial)malloc(sizeof(ATerm));	//for memory allocation
	tmp->Coefficient = coeff;
	tmp->Exponent = exp;
	//list empty or exp greater than first one 
	if (start == NULL || exp > start->Exponent)
	{
		tmp->Next = start;
		start = tmp;
	}
	////////find way to add coefficients if exponents are the same

	else
	{
		ptr = start;
		while (ptr->Next != NULL && ptr->Next->Exponent >= exp)
			ptr = ptr->Next;
		tmp->Next = ptr->Next;
		ptr->Next = tmp;
	}
	return start;
}

//=============================================================================
//Function Name: insert
//Pre conditon: the polynomial that gets added, the coefficient and exponents
//Post condition: returns the pollynomial when 2 get added
//Purpose: to correctely add 2 expressions int he polynomial
//===============================================================================
Polynomial insert(Polynomial start, int coeff, int exp)
{
	Polynomial ptr, tmp;
	tmp = (Polynomial)malloc(sizeof(ATerm));
	tmp->Coefficient = coeff;
	tmp->Exponent = exp;
	//If list is empty
	if (start == NULL)
	{
		tmp->Next = start;
		start = tmp;
	}
	else    //Insert at the end of the list
	{
		ptr = start;
		while (ptr->Next != NULL)
			ptr = ptr->Next;
		tmp->Next = ptr->Next;
		ptr->Next = tmp;
	}
	return start;
}

//=============================================================================
//Function Name: poly_add
//Pre conditon: 2 polynomials
//Post condition: a polynomial expression after the polynomials are added
//Purpose: polynomial expression
//===============================================================================
Polynomial add(Polynomial p1, Polynomial p2)
{
	Polynomial start3;
	start3 = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->Exponent > p2->Exponent)
		{
			start3 = insert(start3, p1->Coefficient, p1->Exponent);
			p1 = p1->Next;
		}
		else if (p2->Exponent > p1->Exponent)
		{
			start3 = insert(start3, p2->Coefficient, p2->Exponent);
			p2 = p2->Next;
		}
		else if (p1->Exponent == p2->Exponent)
		{
			start3 = insert(start3, p1->Coefficient + p2->Coefficient, p1->Exponent);
			p1 = p1->Next;
			p2 = p2->Next;
		}
	}
	//if poly2 has finished and elements left in poly1
	while (p1 != NULL)
	{
		start3 = insert(start3, p1->Coefficient, p1->Exponent);
		p1 = p1->Next;
	}
	//if poly1 has finished and elements left in poly2
	while (p2 != NULL)
	{
		start3 = insert(start3, p2->Coefficient, p2->Exponent);
		p2 = p2->Next;
	}
	return start3;
}

//=============================================================================
//Function Name: poly_mult
//Pre conditon: 2 polynomial expressions
//Post condition: the 2 expressions added
//Purpose: add two polynomail expressions
//===============================================================================
Polynomial multiply(Polynomial p1, Polynomial p2)
{
	Polynomial start3;
	Polynomial p2_beg = p2;
	start3 = NULL;

	while (p1 != NULL)
	{
		p2 = p2_beg;
		while (p2 != NULL)
		{
			start3 = insert_s(start3, p1->Coefficient*p2->Coefficient, p1->Exponent + p2->Exponent);
			p2 = p2->Next;
		}
		p1 = p1->Next;
	}
	Polynomial res = start3;
	while (start3->Next != NULL)
	{
		//cout<<start3->Exponent <<" "<< start3->Next->Exponent<<endl;
		while (start3->Exponent == start3->Next->Exponent)
		{

			start3->Coefficient = start3->Coefficient + start3->Next->Coefficient;
			start3->Next = start3->Next->Next;
		}
		start3 = start3->Next;
	}
	return res;
}


//=============================================================================
//Function Name: get_term
//Pre conditon: string the user entered
//Post condition: memory address to the pointer where the polynomial string references
//Purpose: checks the input for the polynomial
//===============================================================================
Polynomial get_term(string str)
{
	Polynomial poly = (Polynomial)malloc(sizeof(ATerm));
	Polynomial head = poly;
	int num = 0, l = 0;
	if (str[0] == '-')
		l = 1;
	while (isdigit(str[l]) && str[l] != 0)
	{
		num = num * 10 + (str[l] - '0');
		l++;
	}
	if (l == 0 && num == 0)
		num = 1;
	if (str[0] == '-')
	{
		poly->Coefficient = -num;
	}
	else
	{
		poly->Coefficient = num;
	}
	poly->Next = NULL;
	for (int i = 1; i<str.length(); i++)
	{
		if (!((str[i] != '+') && (str[i] != '-')))
		{
			if (str[i - 1] == 'x')
				poly->Exponent = 1;
			else
			{
				int j = i - 1;
				int mul = 1, num = 0;
				while (str[j] != '^' )
				{
					num = mul*(str[j] - '0') + num;
					mul *= 10;
					j--;
				}
				poly->Exponent = num;
			}

			Polynomial tmp = (Polynomial)malloc(sizeof(ATerm));
			num = 0; 
			l = i + 1;
			while (isdigit(str[l]))
			{
				num = num * 10 + (str[l] - '0'); 
				l++;
			}
			if (l == i + 1 && num == 0)
				num = 1;
			if (str[i] == '-')
				tmp->Coefficient = -num;
			else
				tmp->Coefficient = num;

			tmp->Next = NULL;
			poly->Next = tmp;
			poly = tmp;
		}

	}
	int j = str.length() - 1;
	int f = 0;
	if (str[j] == 'x')
		poly->Exponent = 1;
	else
	{
		while (str[j] != '+'&& str[j] != '-' && str[j] != '^' && j != 0)
			j--;
		if (str[j] == '+' || str[j] == '-' || j == 0)
			poly->Exponent = 0;
		else
			f = 1;
	}

	if (f == 1)
	{
		int num = 0; j++;
		while (j<str.length())
		{
			num = num * 10 + (str[j] - '0');
			j++;
		}
		poly->Exponent = num;
	}
	return head;
}

void intro()
{
	cout << "Welcome to the polynomial program. " << endl;
	cout << "This proram will allow the user to input up to 10 polynomials within the integer";
	cout << "limits and wil multiply and add the polynomials entered. The format for the  " << endl;
	cout << "polynomials will be '3x^2+6x+10' where your exponents will be used by the\n'^' sign.\n";
	cout << "-------------------------------------------------------------------------------\n";
}


int main()
{
	intro();
	Polynomial poly[MAX];
	cout << "Enter Number of Polynomials --> ";
	int n = valid_input();

	Polynomial sum, mul;
	string initial[MAX];

	for (int i = 0; i<n; i++)
	{
		cout << endl << "Enter Polynomial " << i + 1 << " : ";
		string str;
		cin >> str;
		initial[i] = str;
		poly[i] = get_term(str);
		if (i == 0)
			mul = sum = poly[0];
		else
		{
			mul = multiply(mul, poly[i]);
			sum = add(sum, poly[i]);
		}
	}

	cout << "\nThe sum of:\n";
	format_input(initial, n, 1);
	cout << "\n=\t"; 
	show_poly(sum);

	cout << "\n\nThe product of\n";
	format_input(initial, n, 2);
	cout << "\n=\t";
	show_poly(mul);

	cout << "\n\n\n";
	system("pause");
	return 0;
}

