#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int x);
void inordertra(struct node* root); 

int main()
{
    int y = 10;
    insert(y);

    y = 30;
    insert(y);

    y = 50;
    insert(y);

    y = 70;
    insert(y);

    y = 90;
    insert(y);

    
    printf("inorder traversal: ");
    inordertra(root);
    printf("\n\n");

    return 0;
}

void insert(int x)
 {
    struct node *p, *q, *prev;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL; // Initialize left pointer
    p->right = NULL; // Initialize right pointer

    if (root == NULL)
	 {
        root = p;
    }
	 else 
	{
        q = root;
        while (q != NULL)
		 {
            prev = q;
            q = (p->data < q->data) ? q->left : q->right; 
            //this loop cover the tree ,starting the root('q') ansd moves either to the left child or right child based on the value of p->data
            //it also keeps a track on the previous node 
        }
        if (p->data < prev->data) 
		{ //after finding the appropriate position for the value , this code insert the value eithe r in left child or right child 
            prev->left = p;
        } 
		else 
		{
            prev->right = p;
        }
    }
}

void inordertra(struct node* root) 
{ 
    if (root != NULL) 
	{
        inordertra(root->left);
        printf("%d ", root->data);
        inordertra(root->right);
    }
}
