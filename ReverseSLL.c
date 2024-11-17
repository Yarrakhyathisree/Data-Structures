//wap to reverse a linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
static void reverse(struct node* head)
{
	struct node*prev=NULL;
	struct node*current=*head;
	struct node*next=NULL;
	
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}

void push(struct node* head,int newdata)
{
	struct node * newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newnode;
	newnode->next=(*head);
	(*head)=newnode;
}

void printlist(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
	    temp=temp->next;
	}
}

int main()
{
	struct node *head=NULL;
	push(10);
	push(20);
	push(30);
	push(40);
	printf("Given linked list\n");
	printlist(head);
	printf("Reversed linked list");
	printlist(head);
}
