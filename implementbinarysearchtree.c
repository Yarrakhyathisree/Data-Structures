// C program to implement binary search tree
#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int key;
    struct node *left, *right;
}node;

//function to create a new node
node* creatnewnode(int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

//function to search a node
node* searchnode(node* root, int target)
{
    if (root == NULL || root->key == target)
    {
        return root;
    }
    if (root->key < target)
    {
        return searchnode(root->right, target);
    }
    return searchnode(root->left, target);
}

//function to insert a new node
node* insertnode(node* node, int value)
{
    if (node == NULL)
    {
        return creatnewnode(value);
    }
    if (value < node->key)
    {
        node->left = insertnode(node->left, value);
    }
    else if (value > node->key)
    {
        node->right = insertnode(node->right, value);
    }
    return node;
}

//function of post order
void postorder(node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->key);
    }
}

//function of inorder
void inorder(node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->key);
        inorder(root->right);
    }
}

//function of preorder
void preorder(node* root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

//function to findmin
node* findmin(node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findmin(root->left);
    }
    return root;
}

//function to delete a node
node* delete (struct node* root,int x)
{
    if (root == NULL)
        return NULL;
 
    if (x > root->key) 
    {
        root->right = delete (root->right, x);
    }
    else if (x < root->key) 
    {
        root->left = delete (root->left, x);
    }
    else 
    {
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL|| root->right == NULL) 
        {
            node* temp;
            if (root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else
        {
            node* temp = findmin(root->right);
            root->key = temp->key;
            root->right = delete (root->right, temp->key);
        }
    }
    return root;
}
 
 //main function
int main()
{
    struct node* root = NULL;

    root = insertnode(root, 70);
    insertnode(root, 20);
    insertnode(root, 25);
    insertnode(root, 30);
    insertnode(root, 35);
    insertnode(root, 40);
    insertnode(root, 45);

    if (searchnode(root, 20) != NULL) 
    {
        printf("found");
    }
    else
    {
        printf("not found");
    }
 
    printf("\n");

    postorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    node* temp = delete (root, 30);
    printf("After Delete: \n");
    inorder(root);
 
    return 0;
}
