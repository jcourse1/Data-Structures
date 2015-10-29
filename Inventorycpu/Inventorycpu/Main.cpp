//Joey Courseault
//March 17, 2015
//Dr. Ng
//Data Structures and Algorith Analysis
//Computer Inventory Abstract Object

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX_ITEMS 100

//problems
//sorting function
//formatting correctly

int valid_input(int, int);

struct cpu_item
{
	string name;
	string key;
	int quantity;
};

class computer
{
	cpu_item item[MAX_ITEMS];
	int total;
	int amount;

public:
	computer();
	bool is_empty() const;
	bool is_full() const;
	bool is_unique(string);
	void add_new_item(string, string, int);
	void delete_item(string);
	void update_quantity(string, int);
	void get_quantity(string);
	void print_by_name(int);
};

computer::computer()
{
	amount = 0; 
	total = 0;
}

bool computer::is_empty() const
{
	return(total == 0 && amount == 0);
}

bool computer::is_full() const 
{
	return(amount+1 == MAX_ITEMS);
}

bool computer::is_unique(string key)
{
	bool valid = true;
	for (int i = 0; i < amount && valid; i++)
	{
		if (key.compare(item[i].name) == 0)
			valid = false;
	}
	return valid;
}

void computer::add_new_item(string n, string k, int q)
{
	item[amount].key = k;
	item[amount].name = n;
	item[amount].quantity = q;

	total += item[amount].quantity;
	amount++;
}

void computer::delete_item(string key)
{
	bool valid = true;
	int i = 0;
	for (i; i < amount && valid; i++)
	{
		if (key.compare(item[i].name) == 0)
			valid = false;
	}
	if (valid)
		cout << "Error! Key " << key << " not Found!\n";
	else
	{
		total = total - item[i].quantity;
		for (i; i < amount - 1; i++)
			item[i] = item[i + 1];	
		amount--;
	}
}

void computer::update_quantity(string k, int q)
{
	bool swap = false;
	for (int i = 0; i < amount && !swap; i++)
	{
		if (item[i].key.compare(k) == 0)
		{
			swap = true;
			total -= item[i].quantity;
			item[i].quantity = q;
		}
	}
	cout << "Quantity has been updated\n";
	total += q;
}

void computer::get_quantity(string k)
{
	bool swap = false;
	for (int i = 0; i < amount && !swap; i++)
	{
		if (item[i].key.compare(k) == 0)
		{
			swap = true;
			if (item[i].quantity==1)
				cout << "Item " << item[i].name << " with key " << k << " has " << item[i].quantity << " item\n";
			else
				cout << "Item " << item[i].name << " with key " << k << " has " << item[i].quantity << " items\n";
		}
	}
	cout << "Your inventory is currently holding " << total << " items\n";
}

void computer::print_by_name(int a)
{
	cout << "\tNAME\t\tKEY\t\tQUANTITY\n";
	cout << "\t-----------------------------------------\n";
	
	
	bool swap;
	cpu_item temp;
	do  
	{
		swap = false;  
		for (int i = 0; i < (amount - 1); i++)   
		{ 
			if (a == 1)
			{
				if (item[i].name.compare(item[i + 1].name) > 1)
				{
					temp = item[i];
					item[i] = item[i + 1];
					item[i + 1] = temp;
					swap = true;
				}
			}
			else if (a==2)
			{
				if (item[i].key.compare(item[i + 1].key) > 1)
				{
					temp = item[i];
					item[i] = item[i + 1];
					item[i + 1] = temp;
					swap = true;
				}
			}
			else
			{
				if (item[i].quantity > item[i + 1].quantity)
				{
					temp = item[i];
					item[i] = item[i + 1];
					item[i + 1] = temp;
					swap = true;
				}
			}
		}
	} while (swap);
	
	for (int i = 0; i < amount; i++)
	{
		cout << right << setw(10) << item[i].name;
		cout << right << setw(16) << item[i].key;
		cout << right << setw(16) << item[i].quantity << endl;
	}
	cout << "\nTotal quantity ---> " << total << endl;
}

int main()
{
	computer inventory;
	int choice, q;
	string n, k;
	do
	{
		cout << "You may now edit the your inventory items. \nPlease select a choice from the list:\n";
		cout << "\t1. Add a new item \n";
		cout << "\t2. Delete an item \n";
		cout << "\t3. Update the quantity \n";
		cout << "\t4. Get the current quantity \n";
		cout << "\t5. View the items in the list in order \n";
		cout << "\t6. Exit\n";
		choice = valid_input(1, 6);

		switch (choice)
		{
		case 1:
			cout << "\nEnter the name of the computer : ";
			getline(cin, n);
			cout << "\nEnter the key for the computer : ";
			getline(cin, k);
			cout << "\nEnter the quantity for the computer : ";
			cin >> q;
			if (inventory.is_unique(k))
			{
				inventory.add_new_item(n, k, q);
				cout << "Item " << n << " with key " << k << " has been added to your inventory!\n";
			}
			else
				cout << "Error! An item with key " << k << " already exist\n";
			
			break;
		case 2:
			cout << "\nEnter the name of the computer to delete : ";
			getline(cin, n);
			cout << "\nEnter the key for the computer to delete : ";
			getline(cin, k);
			inventory.delete_item(k);
			break;
		case 3:
			cout << "Enter the key for the computer : ";
			getline(cin, k);
			cout << "Enter the quantity for this computer : ";
			cin >> q;
			if (inventory.is_unique(k))
				cout << "Error! No item with key " << k << " exist!\n";
			else
				inventory.update_quantity(k, q);
			break;
		case 4:
			cout << "Which item would you like to view the quantity : ";
			getline(cin, k);
			if (inventory.is_unique(k))
				cout << "Error! No item with key " << k << " exist!\n";
			else
				inventory.get_quantity(k);
			break;
		case 5:
			cout << "\nWould you like to sort by:\n1)Computer Name  2)Computer Key 3)Quantity \n----> ";
			int option = valid_input(1, 3);
			if (option == 1)
				inventory.print_by_name(1);
			else if (option==2)
				inventory.print_by_name(2);
			else
				inventory.print_by_name(3);
			break;

		}
		cout << "\n";
	} while (choice != 6);


	system("pause");
	return 0;
}

int valid_input(int min, int max)
{
	int n; string m;
	bool input;
	do
	{
		getline(cin, m);
		if (m.empty())
			input = false;

		else if (m.length() != 1)
		{
			cout << "Error, please enter value menu choice" << endl;
			cout << "Please re-enter\n";
			input = false;
		}
		else
		{
			n = m[0] - '0';
			if (n<min || n>max)
			{
				cout << "Error! Please enter valid menu choice\n";
				input = false;
			}
			else
				input = true;
		}
	} while (!input);
	return n;
}