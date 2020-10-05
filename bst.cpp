#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node *left, *right;
};

node* create_binTree()
{
	node *newnode = new node();
	int x;
	cout << "value : ";
	cin >> x;
	if(x==-1) return NULL;

	newnode->data = x;
	cout << "enter " << x << "->left_";
	newnode->left = create_binTree();
	cout << "enter " << x << "->right_";
	newnode->right = create_binTree();

	return newnode;

}

int main()
{
	node *root;
	root = NULL;
	root = create_binTree();
}