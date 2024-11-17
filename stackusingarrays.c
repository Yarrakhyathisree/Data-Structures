//implement stack using arrays
#include<stdio.h>
#define size 20
void push(int);
int pop();
void display();
int peek();
int stack[size],top=-1;
void main()
{
	int val,choice;
	do
	{
		printf("\n\n****MAIN MENU****\n");
		printf("\n 1.push");
		printf("\n 2.pop");
		printf("\n 3.peek");
		printf("\n 4.display");
		printf("\n 5.exit");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n Enter the value to be pushed on stack:");
			       scanf("%d",&val);
			       push(val);
			       break;
		    case 2:val=pop();
		           printf("\n The value deleted from stack is %d",val);
		           break;
		    case 3:val=peek();
		           if(val!=-1)
		           {
		           	printf("\n The value stored at top of stack is %d",val);
				   }
				   break;
			case 4:display();
			       break;
			case 5:exit(0);
			default :printf("\n Wrong selection,please enter 1-5");       
		}
	}while(choice!=6);
}
void push(int val)
{
	if(top==size-1)
	{
		printf("\n stack overflow insertion is not possible");
	}
	else
	{
		top++;
		stack[top]=val;
		printf("\n Insertion success");
	}
}
int pop()
{
	int val;
	if(top==-1)
	{
		printf("\n stack underflow");
	}
	else
	{
		val=stack[top];
		top--;
		return val;
	}
}
int peek()
{
	if(top==-1)
	{
		printf("\n stack is underflow");
		return -1;
	}
	else 
	  return (stack[top]);
}
void display()
{
	int i;
	if(top==-1)
	printf("stack is underflow");
	else
	{
		for(i=top;i>0;i--)
		printf("\n %d",stack[i]);
	}
}
