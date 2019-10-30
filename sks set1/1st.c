#include<stdio.h>

int main()
{
	int x;
	int *p;
	int **pp;
	printf("enter a number: ");
	scanf("%d",&x);
	p = &x;
	pp = &p;
	printf("the number: %d.....%d\n",*p,**pp);
	return 0;
}
