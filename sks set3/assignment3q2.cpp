#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;


void swap(int &a, int &b)
{
	int t = a;
	a=b;
	b=t;	
	
}

int main()
{

	int a,b;
	cout << "Enter two variables of same type: ";
	cin >> a >> b;
	cout<< "before swapping: " << a << " " << b << "\n";
	swap(a,b);
	cout << "After swapping: "<< a << " "<< b << "\n";
	
	return 0;
}
