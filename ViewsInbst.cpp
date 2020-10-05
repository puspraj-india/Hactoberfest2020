#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	node *left, *right;
};

node *insert(node *root, int data)
{
	if(root == NULL)
	{
		node *newnode = new node();
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		root = newnode;
	}
	else if(data <= root->data)
		root->left = insert(root->left, data);
	else root->right = insert(root->right, data);

	return root;
}

void leftView(node *root)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{

		auto tem = q.front();
		cout << tem->data << " ";
		q.pop();

		if(tem->left)
			q.push(tem->left);
		else if(tem->right)
			q.push(tem->right);
		else break;
	}
}

void rightView(node *root)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{

		auto tem = q.front();
		cout << tem->data << " ";
		q.pop();

		if(tem->right)
			q.push(tem->right);
		else if(tem->left)
			q.push(tem->left);
		else break;
	}
}

void topView(node *root)
{
	queue<pair<node*, int>> q;
	q.push({root, 0});
	map<int, int> m;
	while(!q.empty())
	{
		auto tem = q.front();
		q.pop();
		int hd = tem.second;				// current horizontal distance
		node* current_node = tem.first;

		if(m.count(hd) == 0)
			m[hd] = current_node->data;

		if(current_node->left)
			q.push({current_node->left, hd-1});
		if(current_node->right)
			q.push({current_node->right, hd+1});
	}

	for (auto i: m) cout << i.second << " ";
}

void bottomView(node *root)
{
	queue<pair<node*, int>> q;
	q.push({root, 0});
	map<int, int> m;
	while(!q.empty())
	{
		auto tem = q.front();
		q.pop();
		int hd = tem.second;				// current horizontal distance
		node* current_node = tem.first;

		// if(m.count(hd) == 0)
			m[hd] = current_node->data;

		if(current_node->left)
			q.push({current_node->left, hd-1});
		if(current_node->right)
			q.push({current_node->right, hd+1});
	}

	for (auto i: m) cout << i.second << " ";
}

void inorder(node* root )
{
	if(root == NULL ) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int main()
{
	node *root = NULL;
	root = insert(root, 7);
	root = insert(root, 5);
	root = insert(root, 8);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 9);


	// inorder(root);
	leftView(root);
	cout << endl;
	rightView(root);
	cout << endl;
	topView(root);
	cout << endl;
	bottomView(root);
}