#include<iostream>
using namespace std;

int count=0;
#define max_size 10

class APPLICANT
{
	int applicId,score;
	char name[20];
	public:
		void get_data()
		{
			applicId=count+1;
			cout<<"Enter the data: \nEnter Name: ";
			cin>>name;
            cout<<"Enter the score: ";
			cin>>score;
			count++;
		}

		void show_data()
		{
			cout<<"************DATABASE***************\n";
			cout<<"Application Id: "<<applicId<<"\n";
			cout<<"Name: "<<name<<"\n";
			cout<<"Score: "<<score<<"\n";
		}
};

void show_count()
{
	cout<<"No. of applicants: "<<count<<"\n";
}

void getValue()
{
	cout<<"1. GET DATA\n2. PRINT DATA\n3. COUNT\n4. EXIT\n";
	cout<<"Enter the choice: ";
}

int main()
{
	class APPLICANT arr[max_size];
	arr[0].get_data();
	int c;
	getValue();
	cin>>c;
	while(c>=1 && c<=3)
	{
		switch(c)
		{
			case 1:
				arr[count].get_data();
				break;
			case 2:
				int id;
				cout<<"Enter the application id: ";
				cin>>id;
				arr[id-1].show_data();
				break;
			case 3:
				show_count();
				break;
			default: 
				cout<<"Wrong Choice!\n";
		}
		getValue();
		cin>>c;
	}
	return 0;
}