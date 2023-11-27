#include<stdio.h>
void sort(int ary[20],int num)
{
	int i,j,temp;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if( ary[i] > ary[j] )
			{
				temp=ary[i];
				ary[i]=ary[j];
				ary[j]=temp;
			}
		}
	}
}			
void merge(int a[20],int b[20], int n, int m)
{
	int i,j=0;
	for(i=n;i<m+n;i++)
	{
		a[i]=b[j];
		j++;
	}
	int l=m+n;
	printf("\nmerged array is: \n");
	for(i=0;i<n+m;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int n,m,arr1[20],arr2[20],i;
	printf("enter the number of elements in first array: ");
	scanf("%d",&n);
	printf("first array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	sort(arr1,n);
	printf("sorted array 1 is:\n ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\nenter the number of elements in seccond array: ");
	scanf("%d",&m);
	printf("first array elements: ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr2[i]);
	}
	sort(arr2,m);
	printf("sorted array 2 is:\n ");
	for(i=0;i<m;i++)
	{
		printf("%d\t",arr2[i]);
	}
	merge(arr1,arr2,n,m);
return(0);
}



