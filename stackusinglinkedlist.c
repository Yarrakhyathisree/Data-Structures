//implement stack using linked list 
typedef struct node1
{
	int data;
	struct node *next;
}node;
node *top= NULL;
void push(int);
void pop();
void display();
 
void push(int val)
{
	node *newnode=(node *)malloc(sizeof(node));
	if(top==NULL)
	{
		newnode->data=val;
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->data=val;
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("stack is underflow");
	}
	else
	{
		printf("popped element=%d",top->data);
		node *temp=top;
		top=top->next;
		free(temp);
		printf("item popped");
	}
}
void display()
{
	node *temp=top;
	if(top==NULL)
	{
		printf("stack is underflow");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	push(30);
	push(50);
	push(70);
	printf("linked list\n");
	display();
	pop();
	printf("After popping,the new linked list\n");
	display();
	pop();
	printf("After popping,the new linked list\n");
	display();
}
