#include<stdio.h>
#define size 20
void push();
int pop();
void display();
int peek();
int stack[size],top=-1;
void main()
{
    int ch,val;
    do
    {
        printf("\n\n****MAIN MENU****\n\n");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.peek");
        printf("\n4.display");
        printf("\n5.exit");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the value to be pushed:\n");
                   scanf("%d",&val);
                   push(val);
                   break;
            case 2:val=pop();
                   printf("the value deleted from the list is %d",val);
                   break;
            case 3:val=peek();
                   if(val!=-1)
                   {
                       printf("the values stored at the top of stack is %d",val);
                   }
                   break;
            case 4:display();
                  break;
            case 5:exit(0);
            default:printf("\n worng selection please eneter 1 to 5");
                   
        }
    }while(ch!=6);
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
		printf("\n insertion success");
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
	{
		return stack[top];
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("stack is underflow");
	}
	else
	{
		for(i=top;i>=0;i--)
		printf("%d\n",stack[i]);
	}
}
