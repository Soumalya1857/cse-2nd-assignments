#include<iostream>
#define MAX 10
#define MAX_BOOK_NO 100// defines max number of copies we can have
#define MAX_DIFF_BOOK 100// defines max number of different book possible
using namespace std;

class auto_generate_for_member
{
    static long long a;
    public: 
        long long int id()
        {   
            a++;
            return a;
        }
        friend member::member();
};
int auto_generate_for_member::a = 0;

class auto_id_generate_for_book
{
    long long int a;
    public:
        long long int id()
        {   
            a++;
             return a;
        }
        friend book::get_data();
};
int auto_id_generate_for_book::a = 0;


class member
{   
        long long int member_id;
        string name;
        string email_id;
        string address;
        string member_type;// 1 for faculty 0 for student
    protected:
        int book_number = 0;

    public:
        void get_member_type()//rerturn true for student, flase for faculty
        {
            cout << "Enter member type (either student or faculty): ";
            cin >> member_type;
        }
        void get_name()
        {
            cout << "Enter your name: ";
            cin >> name;
        }
        void get_email_id()
        {
            cout << "Enter your email id: ";
            cin >> email_id;
            cout << endl;
        }
        void get_address()
        {
            cout << "Enter your address: ";
            cin >> email_id;
            cout << endl;
        } 
        member();
        {
            member_id = id();
        }
        void get_status()
        {   
            get_name();
            get_email_id();
            get_address();
            get_member_type();      
        }

        bool check_type()
        {
            if(member_type == "student" || member_type == "Student") return true;
            else return flase;
        }
        int show_member_id()
        {
            return member_id;
        }
};

class student : public member
{
   
    public: 
        bool can_he_get_books()
        {
            if(book_number < 2) return true;
            else return false;
        }
};

class faculty : public member
{
    public:
        bool can_he_get_books()
        {
            if(book_number < 10) return true;
            else return false;
        } 
};

class memberlist
{   
    member* Member[MAX];
    static int count;
    public:
        bool verify_member(int id)// return true if not exists
        {
            int i;
            int flag = -1;
            for(i=0;i<MAX;i++)
            {
                if(Member[i]-> show_member_id() == id)
                {
                    flag = 1;
                    return false;
                }        
            }
            if(flag == -1) return true;

        }
        void add_new_member()
        {
            member* Member[count] = new member;
            Member[count] -> get_status();
            if(Member[count]->check_type())
            {
                new student s;
                Member[count] = &s;
            }
            else
            {
                new faculty s;
                Member[count] = &s;
            }
            count++;
        }
};
int memberlist::count = 0;

class book
{
    int book_id;
    int serial_no;
    public:
        void get_data()
        {
            book_id = id();
        }
};

struct book_data
{
    string name;
    book boi[MAX_BOOK_NO];//serial number should be added
    int current_capacity;
    int available;
};

class booklist
{
   struct book_data b[MAX_DIFF_BOOK];
    public:

        void add_new_book()
        {

        }
};

int main()
{
    return 0;
}
