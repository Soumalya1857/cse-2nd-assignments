#include <iostream>

using namespace std;

struct student
{
    private:
        int rNo;
        float perc;
    public:

        student(int a=0,float b=0)
        {
                rNo = a;
                perc = b;
        }

        void input(void)
        {
            cout<<"Enter roll number: ";
            cin>>rNo;
            cout<<"Enter percentage in maths: ";
            cin>>perc;
        }

        void show_data(void)
        {
            cout<<endl;
            cout<<"Roll number: "<<rNo<<endl;
            cout<<"Pecentage in maths: "<<perc<<"%"<<endl;
        }
        friend void print_member(student&);
        friend void modify_data(student&);

};

void modify_data(student &s)
{
        cout << "Enter roll number: ";
        cin >> s.rNo;
        cout << "Enter percentage in maths: ";
        cin >> s.perc;
}

void print_member(student &s)
{

        cout<<"Roll number: "<<s.rNo<<endl;
        cout<<"Pecentage in maths: "<<s.perc<<"%"<<endl;
}

int main()
{

        student s1(1,95.10);
        student s2(2,62.56);
        student s3(3,56.32);

        s2.show_data();
        modify_data(s2);
        print_member(s2);


        return 0;
}
