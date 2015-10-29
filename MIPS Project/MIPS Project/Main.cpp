/*Joey Courseault
MIPS simulator
Dr. Perry
Computer Org
*/

#include <cctype> 
#include <string>
#include <cmath>
#include <iostream> 

using namespace std;

int btd(string bin) // Gets The Length Of The binary String That Is Being Passed
{
	int dec = 0;

	for (int x = 0, i = (bin.length() - 1); i >= 0; i--) //This Function Starts At The Right Most Character Working Its Way To The Left.
	{	
		// 'X' Is The Power That 2 Will Be Raised To.
		// binary to decimal converter
		if (bin[i] == '1')
		{
			dec += pow(2, x);
			x++;
		}
		else
		{
			dec += 0;
			x++;
		}
	}
	return dec;
}

int regi[31]; // the register starts counting from 0 and only has 32 bits; ram example
int memo[127]; // amount of alloted space for the memore; memory has 128 bits; 

int main()
{
	string hexid;
	int pc = 0;
	char again = 'y';

	do
	{
		cout << "Enter Instruction: ";
		cin >> hexid;
		

		// Convert Hexi To Binary
		string binary;
		unsigned int count;

		for (unsigned int index = 0; index < hexid.length(); index++) 
			hexid[index] = toupper(hexid[index]);

		for (count = 0; count < hexid.length(); count++) // converts the hexidecimal to binary
		{
			switch (hexid[count])
			{
			case '0': binary.append("0000");	break;
			case '1': binary.append("0001");	break;
			case '2': binary.append("0010");	break;
			case '3': binary.append("0011");	break;
			case '4': binary.append("0100");	break;
			case '5': binary.append("0101");	break;
			case '6': binary.append("0110");	break;
			case '7': binary.append("0111");	break;
			case '8': binary.append("1000");	break;
			case '9': binary.append("1001");	break;
			case 'A': binary.append("1010");	break;
			case 'B': binary.append("1011");	break;
			case 'C': binary.append("1100");	break;
			case 'D': binary.append("1101");	break;
			case 'E': binary.append("1110");	break;
			case 'F': binary.append("1111");	break;
			}
		}
		cout << "Binary: " << binary << endl;

		//R-Type instructions
		string op = binary.substr(0, 6), 		// to get first 6 elements for opcode
			rs = binary.substr(6, 5),         // To get the first register file, RS
			rt = binary.substr(11, 5),        // To get the second register file, Rt
			rd = binary.substr(16, 5),       //To store in the third register file, Rd
			shift = binary.substr(21, 5),       // shift
			funct = binary.substr(26, 6),       // the function amount for some instructions
			address = binary.substr(16, 16);	// to store address when needed
		string Jump = binary.substr(6, 26);
		
		//for I type 
		int opCode = btd(op);  
		int RegS = btd(rs);  
		int RegT = btd(rt); 
		int RegD = btd(rd); 
		int sa = btd(shift); 
		int Func = btd(funct);
		int a = btd(address);
		//j type
		int j = btd(Jump);

		// *The Address Is Only Used For I-type*
		if (opCode == 0)		// Checks for R-type
		{
			if (Func == 32)		//For addition
			{
				cout << "Add: $" << RegD << " = $" << RegS << " + $" << RegT << endl; // shows what happens
				regi[RegD] = regi[RegS] + regi[RegT]; // the instruction executed
				cout << regi[RegD] << endl;  // Displays What Is Stored Within The Location
			}

			if (Func == 34)		// Subtraction
			{
				cout << "Sub: $" << RegD << " = $" << RegS << " - $" << RegT << endl; //shows what the instruction is
				regi[RegD] = regi[RegS] - regi[RegT]; // instruction being executed
				cout << regi[RegD] << endl; // Displays What Is Stored Within The Location
			}

			if (Func == 36)		// AND
			{
				cout << "And: " << RegD << " = $" << RegS << " and $" << RegT << endl;
				regi[RegD] = regi[RegS] & regi[RegT]; // The Actual instruction
				cout << regi[RegD] << endl; // Displays What Is Stored Within The Location
			}

			if (Func == 37)		// OR 
			{
				cout << "Or: $" << RegD << " = $" << RegS << " | $" << RegT << endl;	//whats supposed to happen
				regi[RegD] = regi[RegS] | regi[RegT]; // The Actually Code
				cout << regi[RegD] << endl;	// Displays What Is Stored Within The Location
			}

			if (Func == 42)		//slti
			{
				cout << "Slt: $" << RegD << ", " << RegT << endl;
				if (regi[RegS] < regi[RegT])
					regi[RegD] = 1;
				else
					regi[RegD] = 0;
			}
		}

		//j type instruction
		if (opCode == 2)	//execute jump 
		{
			pc = j;
			cout << "J " << j << endl;
		}

		//R type instructions
		if (opCode == 4)		// Branch Is Equal: Checks To See Whether The Values Stored Within Each Register Is Equal 
		{
			cout << "Branch Is Equal To: $" << RegS << " = $" << RegT << ", " << a << endl;		//instruction

			if (memo[RegS] == memo[RegT])		
				cout << "True, Registers Equal.\n";
			else
				cout << "False, Registers not Equal.\n";
		}

		if (opCode == 5)		// Branch Not Equal: Checks To See Whether The Values Stored Within Each Register Are Not Equal 
		{
			cout << "Branch Not Equal: $" << RegS << " = $" << RegT << ", " << a << endl;
			if (memo[RegS] != memo[RegT])
				cout << "True, Registers Not Equal.\n";
			else
				cout << "False, Registers Equal.\n";
		}

		if (opCode == 8)	//Addi
		{
			cout << "Addi: $" << RegT << " = $" << RegS << " + " << a << endl;
			regi[RegT] = regi[RegS] + a;
			cout << regi[RegT] << endl;
		}

		if (opCode == 10)	//slti instruction
		{
			cout << "Slti " << RegD << ", " << RegS << ", " << a << endl;
			if (regi[RegS] < a)
				regi[RegD] = 1;
			else
				regi[RegD] = 0;
			cout << regi[RegD] << endl;
		}

		if (opCode == 35)		//Load word instruction
		{
			cout << "Lw: $" << RegT << " = " << a << "($" << RegS << ")\n"; // Displays instruction
			regi[RegT] = memo[a + regi[RegS]]; // Instruction being executed
			cout << RegT << endl;
		}

		if (opCode == 43)		// Store Word instruction
		{
			cout << "Sw: $" << RegT << " = " << a << "($" << RegS << ")\n";
			memo[a + regi[RegS]] = regi[RegT]; // Executing the instruction
			cout << memo[RegT] << endl;
		}

		cout << "PC: " << pc + 1 << endl;
		pc++;
		cout << "Would you like to run again? Y/N";
		cin >> again;
	} while (again == 'y' || again == 'Y');

	cout << "Registers:\n";		//shows all final register values
	for (int x = 0; x < 32; x++)
		cout << (x+1)  << " " << regi[x+1] << endl;
	

	cout << "Memory:\n";		//showing all final memory values
	for (int y = 0; y < 128; y++)
		cout << (y + 1) << " " << memo[y] << endl;
	

	system("pause");
	return 0;
}
