#include<iostream>
#define MaxNum 1000007
using namespace std;

class List;

class Account 
{
    int accNum;
    float balance;

    public:

        friend void add(Account &, List &);  
        friend int search(int , List &);

        float getBalance() 
        {
            return balance;
        }

        void setBalance(int amount) 
        {
            balance = amount;
        }

        void show();
};

void Account::show() 
{
    cout << "Account Number : " << accNum << "\n";
    cout << "Balance : " << balance << "\n\n";
}

class WithDraw 
{
    int accNum;
    float amount;

    public:
        friend void withdraw(WithDraw &, List &);
        friend int search(int , List &);
};

class List 
{
    int pos;
    Account *list;

    public:
        List() 
        {
            pos = 0;
            list = new Account[MaxNum];
        }
        ~List() 
        {
            delete list;
        }
        void DisplayAll();
        friend int search(int , List &);
        friend void add(Account &, List &);
        friend void withdraw(WithDraw &, List &);
};

void List::DisplayAll() 
{
    cout << "\nAccount Details : \n";
    for(int i = 0; i < pos; i++) 
    {
        list[i].show();
        cout<<"................................"<<endl;
    }
}

int search(int AccNum , List &L) 
{
    int found = -1;
    for(int i = 0; i < L.pos; i++) 
    {
        if(L.list[i].accNum == AccNum) 
        {
            found = i;
            break;
        }
    }
    return found;
}

void add(Account &A, List &L) 
{
    cout << "Enter account number : ";
    cin >> A.accNum;
    cout << "Enter Balance Amount : ";
    cin >> A.balance;
    int index = search(A.accNum , L);
    if(index == -1) 
    {
        L.list[L.pos] = A;
        L.pos++;
    }
    else 
    {
        float newBalance = L.list[index].getBalance() + A.balance;
        L.list[index].setBalance(newBalance);
    }
}

void withdraw(WithDraw &W, List &L) 
{
    cout << "Enter Account Number : ";
    cin >> W.accNum;
    int index = search(W.accNum , L);
    if(index != -1) 
    {
        cout << "Enter Withdrawal Amount : ";
        cin >> W.amount;
        if(W.amount <= L.list[index].getBalance()) 
        {
            float newBalance = L.list[index].getBalance() - W.amount;
            L.list[index].setBalance(newBalance);
        }
        else
        {
            cout<<"Insufficient Balance!"<<endl;
        }
        
    } 
}

int main() {
    Account A; 
    WithDraw W;
    List L;
    //add(A , L);
    //withdraw(W ,  L);
    //L.DisplayAll();

    int ch=0;

    while(1)
    {
        cout<<"1. Add account\n2. Withdraw amount\n3. Display all accounts\n4. Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                add(A,L);
                break;
            case 2:
                withdraw(W,L);
                break;
            case 3:
                L.DisplayAll();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Wrong choice!"<<endl;

        }
    }

    return 0;
}