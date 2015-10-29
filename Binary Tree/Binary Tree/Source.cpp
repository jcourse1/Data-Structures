/*Joey Courseault
Preorder Tree Traversal
Dr. Ng
Data Structures and Algorithm Analysis
April 28, 2015*/

#include<iostream>
#include<string>
using namespace std;

int pos = 0;
struct node
{
	node *left;
	node *right;
	node()
	{
		left = NULL;
		right = NULL;
	}
	char val;
};

/*============================================================
Name: buildtree
Purpose: takes preorder traversal of tree and builds tree
==============================================================*/
node* buildtree(string str)
{
	if (str[pos] == '.' || pos == str.length())
	{
		return NULL;
	}
	node *cur = new node;
	cur->val = str[pos];
	pos += 1;
	cur->left = buildtree(str);
	pos += 1;
	cur->right = buildtree(str);
	return cur;
}

/*============================================================
Name: printpreorder
Purpose: prints the tree in the preorder traversal
==============================================================*/
void printpreorder(node *cur)
{
	if (cur == NULL)
	{
		cout << "." << " ";
		return;
	}
	cout << (cur->val) << " ";
	printpreorder(cur->left);
	printpreorder(cur->right);
	return;
}

/*============================================================
Name: postorder
Purpose: prints the tree in the post traversal
==============================================================*/
void printpostorder(node *cur)
{
	if (cur == NULL)
	{
		cout << "." << " ";
		return;
	}
	printpostorder(cur->left);
	printpostorder(cur->right);
	cout << (cur->val) << " ";
	return;
}



/*============================================================
Name: printinorder
Purpose: prints the tree in the inorder traversal
==============================================================*/
void printinorder(node *cur)
{
	if (cur == NULL)
	{
		cout << "." << " ";
		return;
	}
	printinorder(cur->left);
	cout << (cur->val) << " ";
	printinorder(cur->right);
	return;
}

/*============================================================
Name: printinorder
Purpose: prints the tree in the inorder traversal
==============================================================*/
void printlevelorder(node *cur)
{
	node* q[1111];
	int front = 0, back = 0;
	q[front] = cur;
	while (front <= back)
	{
		cur = q[front];
		front += 1;
		if (cur == NULL)
		{
			continue;
		}
		else
		{
			cout << cur->val << " ";
		}
		q[back + 1] = cur->left;
		back += 1;
		q[back + 1] = cur->right;
		back += 1;
	}
}

/*============================================================
Name: isBST
Purpose: Checks to see wether input string is a BST
==============================================================*/
int isBST(node* node)
{
	if (node == NULL)
		return 1;

	if (node->left != NULL && node->left->val > node->val)
		return 0;

	if (node->right != NULL && node->right->val < node->val)
		return 0;

	if (!isBST(node->left) || !isBST(node->right))
		return 0;

	//if all ither cases fail then traversal is binary tree
	return 1;
}
int main()
{
	string str;
	cout << "This program will allow the user to enter a preorder traversal of a binary tree.";
	cout << "The program will display the tree traversal in preorder form, inorder form, \n";
	cout << "postorder form and level order. Each node consist of single char\n";

	cout << "\nEnter preorder form of tree : ";
	cin >> str;

	//error checking....shouldnt accept empty tree and node shoulld be first

	node *cur = buildtree(str);
	cout << "\n\nPreorder Traversal --> ";
	printpreorder(cur);

	cout << "\n\nInorder Traversal --> ";
	printinorder(cur);
	
	cout << "\n\nPostorder Traversal --> ";
	printpostorder(cur);

	cout << "\n\nLevel OrderTraversal --> ";
	printlevelorder(cur);
	cout << "\n\n";

	if (isBST(cur) == 1)
		cout << "It is a BST\n\n";
	else
		cout << "It is NOT a BST\n\n";

	system("pause");
	return 0;
}



