#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new node
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

// Function to merge two linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    // when list1 is empty then our output will be same as list2
    if (l1 == NULL) 
	return l2;

    // when list2 is empty then our output will be same as list1
    if (l2 == NULL)
	 return l1;

    // pointing l1 and l2 to the smallest and greatest one
    if (l1->val > l2->val)
	{
        ListNode* temp = l1;
        l1 = l2;
        l2 = temp;
    }

    // act as head of resultant merged list
    ListNode* res = l1;

    while (l1 != NULL && l2 != NULL)
	 {
        ListNode* temp = NULL;

        // traverse through list1 until we find 
        // the node which is greater than or equal 
        // to the current node of list2
        while (l1 != NULL && l1->val <= l2->val) 
		{
            temp = l1;  // storing last sorted node  
            l1 = l1->next;//moving l1
        }

        // link previous sorted node with 
        // next larger node in list2
        temp->next = l2;
        
        // swap l1 and l2 to continue the process
        ListNode* tempSwap = l1;
        l1 = l2;
        l2 = tempSwap;
    }

    return res;
}

// Function to print the merged linked list
void printList(ListNode* head)
 {
    while (head != NULL) 
	{
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(ListNode* head)
 {
    ListNode* temp;
    while (head != NULL)
	 {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    // Define the first linked list
    ListNode* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    // Define the second linked list
    ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    // Merge the two linked lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged linked list
    printf("Merged List: ");
    printList(mergedList);

    // Free the memory allocated for the linked lists
    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}

