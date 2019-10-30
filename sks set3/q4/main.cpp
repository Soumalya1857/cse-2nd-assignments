#include <iostream>

using namespace std;

long double total_tax(long int income,double tax)
{
        double temp = (income*tax)/100;
        return temp;
}

long double total_tax(long int income)
{
        double temp = (income/10);
        return temp;
}

int main()
{
        cout << "Enter total income: ";
        long int income;
        cin >> income;

        cout << "would you like to enter tax rate?\n";
        cout << "if yes enter 1\nelse enter 0\n";

        int choice;
        cin >> choice;

        switch(choice)
        {
                case 1: cout << "Ener your tax rate: ";
                        double tax;
                        cin >> tax;
                        cout << "tax per year: " << total_tax(income,tax)<< "\n";
                        break;

                case 0: cout << "tax per year: " << total_tax(income) << "\n"; break;

                default: cout << "///****invalid choice***////\n" ; break;
        }
        return 0;
}
