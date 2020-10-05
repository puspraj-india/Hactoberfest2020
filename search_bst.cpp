#include<iostream>
using namespace std;

struct node 
{
	int data; 
	node *left, *right;
};

node * createNode(int data)
{
	node *temp = new node();
	temp ->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

node* Insert(node *root, int data)
{
	if(root == NULL )
	{
		root = createNode(data);
	}
	else if(data <= root->data)
		root->left = Insert(root->left, data);
	else 
		root->right = Insert(root->right, data);
	return root;
}

void inorder(node *root)
{
	if(root == NULL ) return;
	// cout << "nero";
	inorder(root->left);
	cout << root->data<< " ";
	inorder(root->right);
}

bool search(node *root, int data)
{
	if(root == NULL) return false;
	if(root->data == data) return true;
	if(data <= root->data)
		return search(root->left, data);
	else 
		return search(root->right, data);
}

int main()
{
	node *root = NULL;
	
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// to check the bst is built correct or not check it inorder traversal 
	//if it is in ascending order then it is correct.

	cout << endl;
	inorder(root);

	int x = 8;
	if(search(root, 8)) cout << "\nYes it is present ";
	else cout << "No, not present";

}