#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

#define MAX(x,y) ((x>y)?x:y)

long long int myAtoi(string str) 
{ 
    long long int res = 0; 
  
   
    for (int i = 0; str[i] != '\0'; ++i) 
        res = res * 10 + str[i] - '0'; 
  
    
    return res; 
}

 

/*inline long long int maxi(long long int x,long long int y)
{
	if(x>y) return x;
	else return y;
} 

inline long long int maxis(string s1,string s2)
{
	 long long int a = myAtoi(s1);
	 long long int b = myAtoi(s2);
	
	if(a>=b) return a;
	else return b; 
}*/

inline void maxis(char a[],char b[])
{
	if(strlen(a)>strlen(b)) cout << a <<"\n";
	else if(strlen(a)< strlen(b)) cout << b << "\n";
	else {
		
		int x = strcmp(a,b);
		if(x>=0) cout<< a <<"\n";
		else cout << b << "\n";
	}
	
}

int main()
{

	cout << "Enter two numbers: ";
	char a[100],b[100];
	cin >> a >> b;
	//long long int mama1 = myAtoi(a);
	//long long int mama2 = myAtoi(b);
	
	
	//cout<< "max between them is: "<< MAX(a,b)<< "\n";
	cout << "max between them is: ";
	 maxis(a,b);
	 cout << "\n" << /*MAX(mama1,mama2) <<*/ "\n";
	return 0;
}
