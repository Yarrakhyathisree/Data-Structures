#include <stdio.h>
#include <stdlib.h>
//Search an element in a Linked List
// Node structure represents a node in a linked list
typedef struct Node
 {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given value and NULL next pointer
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a given element is present in the linked list
int checkifPresent(Node* head, int desiredElement) 
{
    Node* temp = head;

    // Traverse the linked list
    while (temp != NULL) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found

        // Move to the next node
        temp = temp->next;
    }

    return 0;  // Return 0 if the element is not found in the linked list
}

int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    int val = 2;  // Element to be checked for presence in the linked list

    // Call the checkifPresent function and print the result
    if(checkifPresent(head, val))
    {
    	printf("The given element is found");
	}
	else
	{
		printf("The given element is not found");
	}

    return 0;  // Return 0 to indicate successful execution
}

