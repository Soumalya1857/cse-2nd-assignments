#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n;
	scanf("%d",&n);
	int *pt;
	pt = (int*)malloc(n*sizeof(int));
	register int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",pt+i);
	}
	for(i=0;i<n;i++)
		printf("%d ",*(pt+i));
		
	printf("\n");
	 
	return 0;
}
