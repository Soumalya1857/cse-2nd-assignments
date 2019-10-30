#include<stdio.h>
#include<stdlib.h>

int main()
{	

	int *p[3];
	register int i,j;
	for(i=0;i<3;i++)
	{
		p[i] = (int*)malloc(3*sizeof(int));
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",(p+i)+j);
		}
	}
	printf("using array of pointer: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",*(p+i+j));
		}
		printf("\n");
	}
	
		
	return 0;
}
