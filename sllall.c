//WAP to creat a linked list and display 

#include<stdio.h>
#include<stdlib.h>
typedef struct sll
{
	int data;
	struct sll *next;
}node;


node *start=NULL;
node *creatll(node*);
node *display(node*);
node *insertbegin(node*);
node *insertend(node*);
node *insertbefore(node*);
node *insertafter(node*);
node *deletebegin(node*);
node *deleteend(node*);
node *deletenode(node*);

//main function
int main()
{
	int ch;
	do
	{
		printf("\n\n******Main menu******\n\n");
		printf("\n 1:creat a list");
		printf("\n 2:Display the list");
		printf("\n 3:Add a node at the begining");
		printf("\n 4:Add a node at the end");
		printf("\n 5:Add a node before a given node");
		printf("\n 6:Add a node after a given node");
		printf("\n 7:Delete a node from the begining");
		printf("\n 8:Delete a node from the end");
		printf("\n 9:Delete a given node");
		printf("\n 10:EXIT");
		printf("Enter the option:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:start=creatll(start);
					printf("\n Linked list is created");
					break;
			case 2:start=display(start);
					break;
			case 3:start=insertbegin(start);
					break;
			case 4:start=insertend(start);
					break;
			case 5:start=insertbefore(start);
					break;
			case 6:start=insertafter(start);
					break;
			case 7:start=deletebegin(start);
					break;
			case 8:start=deleteend(start);	
					break;
			case 9:start=deletenode(start);
					break;					
		}
	
	}while(ch!=10);
	return 0;
}

//function to create a single linked list
node* creatll(node *start)
{
	node *newnode,*ptr;
	int num;
	printf("\n enter -1 to end:");
	printf("\n Enter the data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=num;
		if(start==NULL)
		{
			start=newnode;
			newnode->next=NULL;
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

//function to display the ll
node* display(node *start)
{
	node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

//function to insert at begining of ll
node *insertbegin(node *start)
{
 	node *newnode;
	int num;
 	printf("Enter the value of num:");
 	scanf("%d",&num);
 	newnode=(node*)malloc(sizeof(node));
 	newnode->data=num;
 	if(start==NULL)
 	{
 		start=newnode;
	}
	else
	{
	newnode->next=start;
	start=newnode;
	}
	return start;
}

//function to insert at end of ll
node *insertend(node *start)
{
	node *ptr,*newnode;
	int num;
	printf("Enter the value of num:");
	scanf("%d",&num);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=newnode;
	newnode->next=NULL;
	return start;
}

//function to insert after the ll
node *insertafter(node *start)
{
	node *ptr,*newnode;
	int num,val;
	printf("\nEnter the value of num:");
	scanf("%d",&num);
	printf("\nEnter the value after which the data has to be inserted:");
	scanf("%d",&val);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	ptr=ptr->next;
	newnode->next=ptr->next;
	ptr->next=newnode;
	return start;
}

//function to insert before the ll
node *insertbefore(node *start)
{
	node *ptr,*preptr,*newnode;
	int num,val;
	printf("Enter the value of num:");
	scanf("%d",&num);
	printf("before which value you what to insert:");
	scanf("%d",&val);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}

//function to delete begin of ll
node *deletebegin(node *start)
{
	 node *ptr;
	 ptr=start;
	 if(start==NULL)
	 {
	 	printf("\n Linked list is empty");
	 }
	 else
	 {
	 	if(start->next==NULL)
	 	{
	 		ptr=start;
	 		start=NULL;
	 		free(ptr);
		}
		else
		{
			ptr=start;
			start=start->next;
			free(ptr);
		}
	 }
	 return start;
}

//function to delete end of ll
node *deleteend(node *start)
{
	node *ptr,*preptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		if(start->next==NULL)
		{
			ptr=start;
			start=NULL;
			free(ptr);
		}
		else
		{
			while(ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			preptr->next=NULL;
			free(ptr);
		}
	}
	return start;
}

//function to delete the node in linked list
node *deletenode(node *start)
{
	node *ptr,*preptr;
	int val;
	printf("\n Enter the value of the node which has to be deleted:");
	scanf("%d",&val);
	ptr=start;
	if(ptr->data==val)
	{
		start=deletebegin(start);
	}
	else
	{
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
	return start;
}
