#include "FeetInches.h"
#include <cstdlib>

void FeetInches::simplify() 
{ 
	if (inches >= 12) 
	{ 
		feet += (inches / 12); 
		inches = inches % 12;
	} 
	else if (inches < 0) 
	{ 
		feet -= ((abs(inches) / 12) + 1); 
		inches = 12 - (abs(inches) % 12); 
	}
}

FeetInches FeetInches::operator + (const FeetInches &right)
{ 
	FeetInches temp; 

	temp.inches = inches + right.inches; 
	temp.feet = feet + right.feet; 
	temp.simplify(); 
	return temp; 
} 

FeetInches FeetInches::operator - (const FeetInches &right)
{
	FeetInches temp;
	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}
