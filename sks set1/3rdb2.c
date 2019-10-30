#include<stdio.h>
#include<stdlib.h>
#define n 2

int main()
{	
	//int x[n];
	int (*p)[n];
	//p=&x;
	register int  i,j;
	for(i=0;i<n;i++)
	{
		 (p+i)= (int*)malloc(n*sizeof(int)); 
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",*(p+i)+j);
			//printf("%d",*(*(p+i)+j));
			
		}
		
	}
	
	
	printf("using pointer to an array: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
		
		printf("\n");
	}
	return 0;
}
