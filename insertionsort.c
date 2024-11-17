//insertion sort
#include<stdio.h>
void insertionsort(int a[],int n);
void main()
{
	int a[10],i,n;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	printf("Enter the elements into array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionsort(a,n);
	printf("\n sorted array is\n");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
void insertionsort(int a[],int n)
{
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
	}
	while((temp<a[j])&&(j>=0))
	{
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=temp;
}
