//insert a new key into binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	struct bst *left;
	int data;
	struct bst *right;
}node;

//create a new node function
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

//insert function to insert a new key
node *insert(node *root,int key)
{
	node *nodeptr=root;
	while(1)
	{
		if(nodeptr->data<=key)//Moving to right subtree
		{
			if(nodeptr->right!=NULL)
			{
				nodeptr=nodeptr->right;
			}
			else
			{
				nodeptr->right=createnode(key);
				break;
			}
		}
		else//moving to left subtree
		{
			if(nodeptr->left!=NULL)
			{
				nodeptr=nodeptr->left;
			}
			else
			{
				nodeptr->left=createnode(key);
				break;
			}
		}
	}
	return root;
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
	printf("binary search tree before insertion :\n");
	inorder(root);
	root=insert(root,90);
	printf("binary search tree after insertion :\n");
	inorder(root);
	
}

