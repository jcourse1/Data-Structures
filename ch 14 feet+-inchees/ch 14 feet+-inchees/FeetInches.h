#ifndef FEETINCHES_H 2  
#define FEETINCHES_H 3  

class FeetInches 
{ 
	int feet;     
	int inches;     
	void simplify(); 
public:    
	FeetInches(int f = 0, int i = 0) 
	{ feet = f; 
		inches = i; 
		simplify(); 
	}     
	void setFeet(int f) 
	{ feet = f; }

	void setInches(int i)
	{ inches = i; 
	simplify(); }  
	int getFeet() const 
	{ return feet; } 
	int getInches() const 
	{ return inches; } 

	FeetInches FeetInches::operator++(int)
	{   FeetInches temp(feet, inches);  
		inches++;   
		simplify(); 
		return temp; }

	bool FeetInches::operator < (const FeetInches &right)
	{
		bool status;
		if (feet < right.feet)   
			status = true; 
		else if (feet == right.feet && inches < right.inches)  
			status = true;  
		else     
			status = false;
		return status;
	}

	bool FeetInches::operator > (const FeetInches &right)
	{
		bool status;
		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;
		return status;
	}

	bool FeetInches::operator == (const FeetInches &right) 
	{
		bool status;
		if (feet == right.feet && inches == right.inches)  
			status = true;  
		else     
			status = false;
		return status;
	}
	
	FeetInches operator + (const FeetInches &); 
	FeetInches operator - (const FeetInches &); 

	FeetInches FeetInches::operator++(int) 
	{ 
		FeetInches temp(feet, inches);  
		inches++;   
		simplify();  
		return temp;
	}
};
#endif
