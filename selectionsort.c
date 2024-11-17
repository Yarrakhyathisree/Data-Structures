//selection sort
#include<stdio.h>
int main()
{
	int i,a[10],n,j,temp;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	printf("Enter the elements in array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		int min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("sorted list:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
