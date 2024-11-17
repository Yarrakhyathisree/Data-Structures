//WAP to create a sll and display the list
#include<stdio.h>
typedef struct slink
{
	int data;
	struct slink *next;
}node;
node *start=NULL;
node *createll(node*);
void display(node*);
int main()
{
	int ch;
	do
	{
		printf("\n\n***Main menu*** ");
		printf("\n 1:create list");
		printf("\n 2:Display the list");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:start=createll(start); 
			printf("Linked list is created");
			break;
			case 2:display(start);
			break;
		}
	}while(ch!=3);
} //main close
node* createll(node *start)
{
	node *newnode,*ptr;
	int num;
    printf("Enter -1 to end\n");//till we enter -1 this will be exicuted
	printf("Enter the data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=num;
	if(start==NULL)
	{
		newnode->next=NULL;
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=newnode;
		newnode->next=NULL;	
	}
	printf("Enter the data:");
	scanf("%d",&num);
}
return start;
}
void display(node *start)
{
	node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
}
