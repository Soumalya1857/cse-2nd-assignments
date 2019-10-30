#include<stdio.h>
#include<stdlib.h>
#define n 3

int main()
{	
	int x[3][3];
	int (*p)[3];
	p=x;
	
	register i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",*(p+i)+j);
		}
		//p++;
	}
	//for(i=0;i<3;i++) p--;
	
	printf("using pointer to an array: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
		//p++;
		printf("\n");
	}
	return 0;
}
