//binary search
#include<stdio.h>
int main()
{
	int a[10],n,key,low,high,i,flag,pos,mid;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	printf("Enter the elements into the array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the element to be searched:\n");
	scanf("%d",&key);
	flag=0;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==a[mid])
		{
			flag=1;
			pos=mid+1;
			break;
		}
		else if(key>a[mid])
		{
			low=mid+1;
		}
		else
		high=mid-1;
	}
	if(flag==1)
	printf("the element is found at possition=%d",pos);
	else
	printf("the element is not found");
}
