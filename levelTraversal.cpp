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

void lever_ordered_traversal(node *root)
{
	queue<node *> a;
	a.push(root);

	while(a.size())
	{
		node * use = a.front();
		if(use->left !=NULL)
		{
			a.push(use->left);
		}
		if(use->right != NULL)
			a.push(use->right);
		cout << use->data << " ";
		a.pop();
	}
}

int main()
{
	node *root;
	root = NULL;
	root = create_binTree();
	cout << "level ordered traversal : ";
	lever_ordered_traversal(root);
}