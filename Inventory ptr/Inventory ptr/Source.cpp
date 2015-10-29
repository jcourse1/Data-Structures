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

//is unique
//adding 3rd item
//make sure name and key match up together for delete


class Inventory
{
	struct cpu_node
	{
		string name;
		string key;
		int quantity;
		cpu_node* next;
	};
	typedef cpu_node* cpu_nodeptr;
	cpu_nodeptr start;
	cpu_nodeptr rear;
	int types;
	int total;

public:
	Inventory();
	~Inventory();
	bool is_empty() const;
	void add_new_item(string, string, int);
	void delete_item(string, string);
	bool is_unique(string);
	void update_quantity(string, int);
	void get_quantity(string);
	void print_in_order();
	bool check_key(string);
};

Inventory::Inventory()
{
	start = rear =  NULL;
	total = 0;
	types = 0;
}

Inventory::~Inventory()
{
	delete(start);
	start = rear = NULL;
	total = 0;
	types = 0;
}

bool Inventory::is_empty() const
{
	return(total == 0 && types == 0);
}

bool Inventory::is_unique(string k)
{
	cpu_nodeptr temp = start;
	bool unique = true;
	while (temp != NULL && unique)
	{
		if (k.compare(temp->key) == 0)
			unique = false;
		else
			temp = temp->next;
	}
	return unique;
}

void Inventory::add_new_item(string n, string k, int num)
{
	cpu_nodeptr item_node = new cpu_node;
	item_node->name = n;
	item_node->key = k;
	item_node->quantity = num;
	item_node->next = NULL;
	
	if (rear==NULL)
		start = rear = item_node;	
	
	else
	{
		rear->next = item_node;
		rear = item_node;
	}
	types++;
	total=total+item_node->quantity;
}

void Inventory::delete_item(string n, string k)
{
	if (!is_empty())
	{
		cpu_nodeptr temp = start;
		cpu_nodeptr t = temp->next;
		if (start->name.compare(n) == 0 && start->key.compare(k) == 0)
		{
			total = total - start->quantity;
			start = start->next;
			cout << "\nItem " << n << " with key " << k << " has been Deleted!\n";
			types--;
		}
		else if (rear->name.compare(n) == 0 && rear->key.compare(k) == 0)
		{
			cpu_nodeptr temp = start;
			total = total - rear->quantity;
			while (temp->next != rear)
				temp = temp->next;
			rear = temp;
			rear->next = NULL;
			cout << "\nItem " << n << " with key " << k << " has been Deleted!\n";
			
			types--;
		}
		else
		{
			//make more efficient
		//	int c = 0;
			while (t != NULL)
			{
				temp = temp->next;
				t = t->next;
				if (k.compare(t->key) == 0 && n.compare(t->name) == 0)
					break;
				//cout << c++ << endl;
			}
			if (t == NULL)
				cout << "Error! Item" << n << " with key " << k << " NOT found!\n";
			else
			{
				cout << "\nItem " << n << " with key " << k << " has been Deleted!\n";
				cpu_nodeptr temp2 = temp->next;
				temp->next = temp2->next;
				total = total - temp2->quantity;
				free(temp2);
				types--;
			}
		}
	}
	else
		cout << "\nYour inventory is Empty! Delete operation ignored\n";
}

void Inventory::update_quantity(string key, int q)
{
	//find the name of the item and change the quantiy of the item of that node
	cpu_nodeptr temp = start;
	while (temp != NULL)
	{
		if (temp->key.compare(key) == 0)
			break;
		else
			temp = temp->next;
	}
	if (temp == NULL)
		cout << "Error! " << key << " not found!\n";
	else
	{
		temp->quantity = q;
	}
}

void Inventory::get_quantity(string k)
{
	cpu_nodeptr temp = start;
	bool found = false;
	while (temp != NULL && !found)
	{
		if (temp->key.compare(k) == 0)
			break;
		else
			temp = temp->next;
	}
	if (temp == NULL)
		cout << "Error! " << k << " not found!\n";
	else
	{
		cout << "The quantity for " << k << " is " << temp->quantity << endl;
	}
	cout << "The total quantity of all items is " << total << endl;
} 

void Inventory::print_in_order()
{
	if (is_empty())
		cout << "No items in inventory to sort!";
	else if (types == 1)
	{
		cout << "\nHere are the items of your inventory\n";
		cout << "\t\tNAME\t\tKEY\t\tQUANTITY\n\t\t------------------------------\n";
		cout << "\t\t" << start->name << "\t\t" << start->key << "\t\t" << start->quantity << endl;
	}
	else
	{
		bool swap;	
		/*do
		{
			swap = false;
			cpu_nodeptr temp1 = start;
			cpu_nodeptr t;
			for (int i = 0; i < types - 1; i++)
			{
				t = temp1->next;
				if (temp1->name.compare(t->name)>0)
				{
					string temp_name = temp1->name;
					string temp_key = temp1->key;
					int temp_q = temp1->quantity;

					temp1->name = t->name;
					temp1->key = t->key;
					temp1->quantity = t->quantity;

					t->name = temp_name;
					t->key = temp_key;
					t->quantity = temp_q;
					swap = true;
				}
				temp1 = temp1->next;
			}
		} while (swap);*/
		
		/*
		for (int i = 0; i < amount; i++)
	{
		cout << right << setw(10) << item[i].name;
		cout << right << setw(16) << item[i].key;
		cout << right << setw(16) << item[i].quantity << endl;
	}
	cout << "\nTotal quantity ---> " << total << endl;
		*/
		cout << "\nHere are the items of your inventory\n";
		cout << "\t\tNAME\t\tKEY\t\tQUANTITY\n\t\t------------------------------\n";

		cpu_nodeptr a = start;
		
		for (int i = 0; i < types; i++)
		{
			cout << right << setw(10) << a->name;
			cout << right << setw(10) << a->key;
			cout << right << setw(10) << a->quantity << endl;
			a = a->next;
		}
		cout << "\nYou have a total of " << total << " items in your inventory\n";
		cout << "You have " << types << " types of items\n";
	}
}

int valid_input(int, int);

int main()
{
	Inventory items;
	string n, k;
	int choice, q;
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
			if (items.is_unique(k))
			{
				items.add_new_item(n, k, q);
				cout << "\nItem " << n << " with key " << k << " has been added to your inventory!\n";
			}
			else
				cout << "\nError! An item with key " << k << " already exist\n";

			break;
		case 2:
			cout << "\nEnter the name of the computer to delete : ";
			getline(cin, n);
			cout << "\nEnter the key for the computer to delete : ";
			getline(cin, k);
			if (items.is_unique(k))
				cout << "\nError! Key " << k << " NOT found!\n";
			else
				items.delete_item(n, k);
			break;
		case 3:
			cout << "\nEnter the key for the computer : ";
			getline(cin, k);
			cout << "Enter the quantity for this computer : ";
			cin >> q;
			if (items.is_unique(k))
				cout << "Error! No item with key " << k << " exist!\n";
			else
				items.update_quantity(k, q);
			break;
		case 4:
			cout << "Which item would you like to view the quantity : ";
			getline(cin, k);
			if (items.is_unique(k))
				cout << "\nError! No item with key " << k << " exist!\n";
			else
				items.get_quantity(k);
			break;
		case 5:
			cout << "\nWould you like to sort by:\n1)Computer Name  2)Computer Key 3)Quantity \n----> ";
			int option = valid_input(1, 3);
			if (option == 1)
				items.print_in_order();	//by name
			else if (option == 2)
				items.print_in_order();	//by name a =2
			else
				items.print_in_order();	//by name a = 3
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