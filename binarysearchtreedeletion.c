//wap to delete a ode in binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
	struct bst *lchild;
	int data;
	struct bst *rchild;
}node;

//create a node function
node *createnode(int val)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	return newnode;
}

//inorder function
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d\t",root->data);
		inorder(root->rchild);
	}
}


//function to delete the node with the given key from the tree
node *deletenode(node *root,int key)
{
	if(root==NULL)
	return root;
	//if the key to be deleted is small than root key 
	if(key<root->data)
	{
		root->lchild=deletenode(root->lchild,key);
	}
	//if the key to be deleted is greater than root key
	else if(key>root->data)
	{
		root->rchild=deletenode(root->rchild,key);
	}
	else
	{
		if(root->lchild==NULL)
		{
			node *temp=root->rchild;
			free(root);
			return temp;
		}
		if(root->rchild==NULL)
		{
			node *temp=root->lchild;
			free(root);
			return temp;
		}
		//node with two children get the inorder succesor
		node *temp=root->rchild;
		while(temp->lchild!=NULL)
		{
			temp=temp->lchild;
		}
		root->data=temp->data;
		//delete the inorder succesor
		root->rchild=deletenode(root->rchild,temp->data);
		return root;
		
	}
}
//main function
int main()
{
	node *root=NULL;
	root=createnode(50);
	root->lchild=createnode(30);
	root->lchild->lchild=createnode(20);
	root->lchild->rchild=createnode(40);
	root->rchild=createnode(70);
	root->rchild->lchild=createnode(60);
	root->rchild->rchild=createnode(80);
	printf("Inorder traversal before deletion:\n");
	inorder(root);
	printf("\n");
	int key=30;
	root=deletenode(root,key);
	printf("Inorder traversal after deletion\n");
	inorder(root);
	return 0;
}


