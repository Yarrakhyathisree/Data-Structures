//linear search 
#include<stdio.h>
int main()
{
	int a[5],n,i,flag,key,pos;
	printf("Enter the size of an array:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the key to be searched:\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
	if(a[i]==key)
	{
		flag=1;
		pos=i+1;
		break;
	}
    } 
    if(flag==1)
    printf("The element is found at possition=%d",pos);
    else
    printf("The element is not found");
}
