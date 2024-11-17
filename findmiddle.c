#include <stdio.h>
#include <stdlib.h>
//Find middle element in a Linked List
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
ListNode* middleNode(ListNode* head)
{
    int n = 0,i=0;
    ListNode* temp = head;

    // Count the number of nodes in the linked list
    while (temp!=NULL)
	{
        n++;
        temp = temp->next;
    }
    temp=head;
    // Reset temp to the head of the list
    // Move temp to the middle node
    for(i=0;i<n/2;i++)
	{
        temp = temp->next;
    }

    return temp;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Find the middle node
    ListNode* middle = middleNode(head);

    // Print the value of the middle node
    printf("Middle node value: %d\n", middle->val);

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

