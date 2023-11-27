#include<stdio.h>
int main()
{
	int a[50]={};
	int i,sum=0,n;
	printf("enter the size: ");
	scanf("%d",&n);
	if(n>50)
	{
		printf("array oversize");
	}
	else if(n<0)
	{
		printf("error");
	}
	else
	{
		for(i=0;i<n;i++)
	{
		printf("enter elements");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		sum = sum+a[i];
	}
	printf("sum=%d",sum);
	}
return(0);
}
		
