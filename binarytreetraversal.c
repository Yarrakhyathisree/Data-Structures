//implementation of binary tree traversal techniques using linked list
#include<stdio.h>
#include<stdlib.h>
 
typedef struct binarytree
{
	struct binarytree *left;
	int data;
	struct binarytree *right;
}node;

// create a node function
node *createnode(int value)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

//preorder traversal
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//inorder traversal
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

//postorder traversal
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}

//main function
int main()
{
	node *root=NULL;
	root=createnode(10);
	root->left=createnode(20);
	root->right=createnode(30);
	root->left->right=createnode(40);
	root->left->left=createnode(50);
	root->right->left=createnode(60);
	root->right->right=createnode(70);
	printf("Inorder traversal:\n"); 
	inorder(root);
	printf("Preorder traversal:\n");
	preorder(root);
	printf("Postorder traversal:\n");
	postorder(root);
	return 0;
}
