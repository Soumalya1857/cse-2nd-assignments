#include<iostream>
#include<cstdlib>
using namespace std;

int min(int a,int b)
{
    return a<b?a:b;
}

class ARRAY
{
    private:
        int *ptr;
        int size;
    public:
        ARRAY(int *, int);
        ARRAY(int,int);
        int &operator[] (int);
        void print();
        void operator+(ARRAY);
        void operator=(ARRAY);
        void operator*(int);
        friend void operator*(int ,ARRAY &);
};

void ARRAY::operator=(ARRAY t)
{
    int i=0;
    if(size<t.size)
    {
        cout<<"Assignment Invalid\n";
        return ;
    }
    for(i=0;i<size;i++)
    {
        ptr[i]=t.ptr[i];
    }
}

int &ARRAY::operator[](int index)
{
    if (index >= size)
    {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return ptr[index];
}

ARRAY::ARRAY(int a,int b=1)
{
    ptr=new int[a];
    size=a;
    int i=0;
    for(i=0;i<a;i++)
    {
        ptr[i]=b;
    }
}

void ARRAY::operator+(ARRAY t)
{
    int x=min(t.size,size);
    int i=0;
    for(i=0;i<x;i++)
        ptr[i]+=t.ptr[i];
}

void ARRAY::operator*(int t)
{
    int i=0;
    for(i=0;i<size;i++)
        ptr[i]*=t;
}

ARRAY::ARRAY(int *p, int s = 0)
{
    size = s;
    ptr = NULL;
    if (s != 0)
    {
        ptr = new int[s];
        for (int i = 0; i < s; i++)
            ptr[i] = p[i];
    }
}

void ARRAY::print()
{
    for(int i = 0; i < size; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}

void operator*(int a,ARRAY &x)
{
    int i=0;
    for(i=0;i<x.size;i++)
        x.ptr[i]*=a;
}

int main()
{
    ARRAY ar1(5,10);
    ar1*4;
    2*ar1;
    ar1.print();
    return 0;
}