#include<iostream>
#include<string>

using namespace std;


class STRING
{
    char *p;
    int size;
    public:
        STRING(char *str)
        {
            int l=0;
            for(l=0;str[l]!='\0';l++);
            size=l;
            if(size==0)
                p=NULL;
            else
            {
                p=new char[size];
            }
            int i=0;
            for(i=0;i<l;i++)
            {
                p[i]=str[i];
            }
        }

        STRING(int s=0)
        {
            size=s;
            if(size==0)
                p=NULL;
            else
            {
                p=new char[size];
            }
            
        }

        STRING operator +(STRING S)
        {
            int l1=0,l2=0,l=0,i=0;
            for(l1=0;p[l1]!='\0';l1++);
            for(l2=0;S.p[l2]!='\0';l2++);
            l=l1+l2;
            
            STRING temp(l);
            
            for(i=0;i<l1;i++)
            {
                temp.p[i]=p[i];
            }

            for(i=l1;i<l;i++)
            {
                temp.p[i]=S.p[i-l1];
            }

            return temp;
        }

        int operator >=(STRING S)
        {
            
            int l1=0,l2=0,l=0,i=0,v1=0,v2=0;
            for(l1=0;p[l1]!='\0';l1++);
            for(l2=0;S.p[l2]!='\0';l2++);
            
            if(l1<l2)
                return 0;
            else
            {
                for(i=0;i<l2;i++)
                {
                    v1=(int)p[i];
                    v2=(int)S.p[i];
                    if(v1<v2)
                        return 0;
                }
                return 1;
            }
            
        }

        int operator <=(STRING S)
        {
            int l1=0,l2=0,l=0,i=0,v1=0,v2=0;
            for(l1=0;p[l1]!='\0';l1++);
            for(l2=0;S.p[l2]!='\0';l2++);
            if(l1>l2)
                return 0;
            else
            {
                for(i=0;i<l1;i++)
                {
                    v1=(int)p[i];
                    v2=(int)S.p[i];
                    if(v1>v2)
                        return 0;
                }
                return 1;
            }
        }

        int operator ==(STRING S)
        {
            int l1=0,l2=0,l=0,i=0,v1=0,v2=0;
            for(l1=0;p[l1]!='\0';l1++);
            for(l2=0;S.p[l2]!='\0';l2++);

            if(l1!=l2)
            {
                return 0;
            }
            else
            {
                for(i=0;i<l1;i++)
                {
                    v1=(int)p[i];
                    v2=(int)S.p[i];
                    if(v1!=v2)
                        return 0;
                }
                return 1;
            }
            
        }

        void show()
        {
            int i=0;
            for(i=0;p[i]!='\0';i++)
            {
                cout<<p[i];
            }
            cout<<endl;
        }

        ~STRING()
        {
            delete p;
        }

};

int main()
{
    STRING a1("OOPSLab");
    STRING a2("JadavpurUniversity");
    STRING a3=a1+a2;
    a3.show();

    STRING c1("samarpan");
    STRING c2("sam");


    if(c1==c2)
    {
        cout<<"Equal strings"<<endl;
    }
   
    else if(c1>=c2)
    {
        cout<<"First string greater"<<endl;
    }

    else if(c1<=c2)
    {
        cout<<"Second string greater"<<endl;
    }

    return 0;
}