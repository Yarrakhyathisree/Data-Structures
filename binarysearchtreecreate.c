//implementation of binary search tree
//create and display
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
}node;

//create a node function
node* createnode(int value)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

//inorder function
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

//main function
int main()
{
	node *root=NULL;
	root=createnode(50);
	root->left=createnode(25);
	root->left->left=createnode(20);
	root->left->right=createnode(30);
	root->right=createnode(55);
	root->right->left=createnode(52);
	root->right->right=createnode(58);
	printf("inorder tarversal:\n");
	inorder(root);
}
