#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;


int* fun(int x,int y)
{
	return &((x>y)?x:y);
}


int &fun1(int &x,int  &y)
{
	return ((x>y)?x:y);
}
int main()
{	

	cout << "Enter the two variable: ";
	int a,b;
	cin >> a >> b;
	
	int *x;
	x = fun(a,b);
	cout << *x << "\n";
	
	int y= fun1(a,b);
	cout << y << "\n";
	
	return 0;
}
