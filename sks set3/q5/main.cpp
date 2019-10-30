#include <iostream>

using namespace std;

void function(int x,int y)
{
        int temp = x+y;
        cout << "the sum is: " << temp << "\n";
}

void function(char x ,int y)
{
        int temp = x+y;
        cout << "the sum is: " << temp << "\n";
}


int main()
{
        cout << "******function calling******\n" << "\n";

        function(5,a);
        function(b,a);
        function(10.23,12.26);
        function(5,10.36);

        return 0;
}
