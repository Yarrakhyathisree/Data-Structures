//SELF-REFERENTIAL STRUCTURE EXAMPLE
//self referential structure with 1-link 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}list;
int main()
{
	list *ptr;
	ptr=(list *)malloc(sizeof (list));
	printf("enter the data:");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	printf("ptr->data=%d\n",ptr->data);
	printf("ptr->next=%u\n",ptr->next);
	return 0;
}
