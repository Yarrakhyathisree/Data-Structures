//SELF-REFERENTIAL STRUCTURE EXAMPLE
//self referential structure with 2-link 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}list;
int main()
{
	list *first,*second;
	first=(list *)malloc(sizeof(list));
	printf("Enter the data for the first node:");
	scanf("%d",&first->data);
	second=(list *)malloc(sizeof(list));
	printf("Enter the data for the second node:");
	scanf("%d",&second->data);
	second->next=NULL;
	first->next=second;
	while(first!=NULL)
	{
		printf("%d->",first->data);
		first=first->next;
	}
	return 0;
}
