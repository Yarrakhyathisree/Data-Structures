
//WAP to creat a double linked list and display 
typedef struct dll
{ 
  struct dll *prev;
  int data;
  struct dll *next;
}node;

node *start=NULL;
node* createdll(node*);
void display(node*);
node* insertbegin(node*);
node* insertbefore(node*);
node* insertafter(node*);
node* insertend(node*);
node* deletebegin(node*);
node* deleteend(node*);
node* deletemiddle(node*);

//main function
int main()
{
	int ch;
	do
	{
		printf("\n\n\n*****Main menu*****");
		printf("1.create double linked list\n");
		printf("2.display \n");
		printf("3.insert at begining of linked list \n");
		printf("4.insert at before of the given node \n");
		printf("5.insert after the given node \n");
		printf("6.insert at end of the dll\n");
		printf("7.delete the node at the begining of the linked list\n");
		printf("8.delete node at the end");
		printf("9.delete a node in the middle (before a given node)");
		
		printf("enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:start=createdll(start);
			       break;
		    case 2:display(start);
		           break;
		    case 3:start=insertbegin(start);
		       	   break;
			case 4:start=insertbefore(start);
			       break;
			case 5:start=insertafter(start);
			       break;
			case 6:start=insertend(start);
			       break;
			case 7:start=deletebegin(start);
			       break;
			case 8:start=deleteend(start);
			       break;
		    case 9:start=deletemiddle(start);
			       break;	    
		}
		
	}while(ch!=10);
}

//create the doble linked list function
node* createdll(node *start)
{
	node *newnode,*ptr;
	int num;
	printf("enter -1 to end");
	printf("enter the data:\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		if(start==NULL)
		{
		newnode=(node*)malloc(sizeof(node));
		newnode->prev=NULL;
		newnode->data=num;
		newnode->next=NULL;
		start=newnode;
	    } 
	    else
	    {
	    	ptr=start;
	    	newnode=(node*)malloc(sizeof(node));
	    	newnode->data=num;
	    	while(ptr->next!=NULL)
	    	{
	    		ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->prev=ptr;
			newnode->next=NULL;
	    	
		}
		printf("enter the data:\n");
		scanf("%d",&num);
	}
	return start;
}

//display the dll function
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

//function to insert at begining of dll
node* insertbegin(node *start)
{
	node *newnode;
	int num;
	printf("Enter the value to be inserted at begining:");
	scanf("%d",&num);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	if(start==NULL)
	{
		start=newnode;
		start->next=NULL;
		start->prev=NULL;
	}
	else 
	{
	newnode->next=start;
	start->prev=newnode;
	newnode->prev=NULL;
	start=newnode;
   } 
}

//function to insert at end of dll
node* insertend(node *start)
{
	node *newnode,*ptr;
	int num;
	printf("enter the value of num:");
	scanf("%d",&num);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
	newnode->next=NULL;
	return start;
}

//function to insert before dll
node* insertbefore(node* start)
{
	node *newnode,*ptr;
	int num,val;
	printf("Enter the value to be inserted:");
	scanf("%d",&num);
	printf("Enter the value before with the data has to be inserted:");
    scanf("%d",&val);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
    	ptr=ptr->next;
	}
	newnode->next=ptr;
	newnode->prev=ptr->prev;
	ptr->prev->next=newnode;
	ptr->prev=newnode;
	return start;
}

//function to insert after dll
node* insertafter(node *start)
{
	node *newnode,*ptr;
	int num,val;
	printf("Enter the value to be inserted:");
	scanf("%d",&num);
	printf("Enter the value after with the data should be inserted:");
	scanf("%d",&val);
	newnode=(node*)malloc(sizeof(node));
	newnode->next=num;
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	newnode->prev=ptr;
	newnode->next=ptr->next;
	ptr->next->prev=newnode;
	ptr->next=newnode;
	return start;
}

//functionto delete begin dll
node* deletebegin(node *start)
{
	node *temp;
	if(start==NULL)
	{
		printf("NO elements for deletion in linked list");
	}
	else if(start->next==NULL)
	{
		temp=start;
		printf("deleted element=%d",start->data);
		start=NULL;
		free(temp);
	}
	else
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		free(temp);
	}
	return start;
}

//function to delete end of dll
node* deleteend(node *start)
{
	node *temp;
	if(start==NULL)
	{
		printf("No elements for deletion in linked list");
	}
	else if(start->next==NULL)
	{
		temp=start;
		printf("deleted element=%d",start->data);
		start=NULL;
		free(temp);
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp;)
	}
	return start;
}

//before a given node we delete it
node* deletemiddle(node *start)
{
	node *ptr,*temp;
	int val;
	printf("Enter the value before with the node is deleted:");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	temp=ptr->prev;
	if(temp==start)
	{
		start=start->next;
		start->prev=NULL;
		free(temp);
	}
	else
	{
		ptr->prev=temp->prev;
		temp->prev->next=ptr;
	}
	free(temp);
	return start;
}

 

