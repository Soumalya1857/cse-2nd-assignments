#include <iostream>

using namespace std;

class student
{
       private:
               int roll;
               string name;
               string branch;
               string admission_date;
               int marks[5];
               static int counter;

       public:

                student()
                {
                        int i=0;
                        for(i=0;i<5;i++) marks[i] = 0;
                        counter++;
                }

                ~student()
                {
                        counter--;
                        //delete student;
                }

                void get_data();
                void get_marks();
                void show_data();
                void show_marks();
                void show_count();

};

int student::counter = 0;
void student::get_data()
{
        cout << "Enter roll no of the student: ";
        cin >> roll;

        cout << "Enter name of the student: ";
        cin >> name;

        cout << "Enter branch name of the student: ";
        cin >> branch;

        cout << "Enter admission date of the student: ";
        cin >> admission_date;
}


void student::get_marks()
{
        cout << "enter 5 marks: ";
        for(int i =0;i<5;i++)
                cin >> marks[i];
}

void student::show_data()
{
        cout << "\nroll: " << roll << "\n";
        cout << "name: " << name << "\n";
        cout << "bramch name: " << branch << "\n";
        cout << "admission date: " << admission_date << "\n";
}

void student::show_marks()
{
        cout << "marks: ";
        for(int i=0;i<5;i++)
        {
                cout << marks[i] << " ";
        }
        cout << "\n";
}

void student::show_count()
{
        cout << "no of student admitted: ";
        cout << counter << "\n";
}

int main()
{
        student s1,s2,s3,s4;

        s1.get_data();
        s1.show_data();

        s1.get_marks();
        s1.show_marks();

        s1.show_count();

        return 0;
}
