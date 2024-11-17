#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
Node* insert(Node* root, int data) 
{
    if (root == NULL)
	{
        root = createNode(data);
    }
	 else 
	 {
        if (data <= root->data) 
		{
            root->left = insert(root->left, data);
        } 
		else 
		{
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node* root) 
{
    if (root != NULL) 
	{
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(Node* root)
{
    if (root != NULL)
	{
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(Node* root)
{
    if (root != NULL) 
	{
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 3);
    
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
