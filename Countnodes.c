#include <stdio.h>
#include <stdlib.h>
//Find length of linked list
// Definition for singly-linked list
typedef struct ListNode
{
    int val;
    struct ListNode* next;
} ListNode;

// Function to create a new node with the given value
ListNode* createNode(int val)
 {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) 
	{
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to find the middle node of a linked list
int Countnodes(ListNode* head)
{
    int count = 0,i=0;
    ListNode* temp = head;

    // Count the number of nodes in the linked list
    while (temp!=NULL)
	{
        count++;
        temp = temp->next;
    }
    
    return count;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int count = countnodes(head);
    printf("The number of nodes in linked list: %d\n", count);

    // Free memory
    ListNode* temp;
    while (head != NULL) 
	{
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

