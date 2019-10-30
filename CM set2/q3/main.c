#include <stdio.h>
#include <stdlib.h>
#define max 20
#define head_count 5

struct node
{
        int data;
        int next;
};

struct node s[max];
int head[head_count];
int list_no = 0;
int size = max; // contain no of available nodes
int available = 0;


// function prototypes
void new_list();
void display_one_list();
void display_all_list();
void display();
void display_size();
void insert_a_new_data();
void enter_before_head(int,int);
void enter_at_a_position(int,int);
void enter_at_end(int,int);
void delete_something();
void delete_first_element(int num);


int main()
{

    register int i;

    // initially all are vacant
    for(i=0;i<max-1;i++)
    {
            s[i].next = i+1;
    }
    s[max-1].next = -1;


    while(1)
    {
        printf("\n\n//*************MENU*********///\n");
        printf("1. Enter a new list\n");
        printf("2.Enter a number in a particular list\n");
        printf("3. delete\n");
        printf("9.display\n");
        printf("10.display max no of element you can enter\n");
        printf("11.exit\n");
        printf("*************************************\n\n");



        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
                case 1:new_list(); break;
                case 2:insert_a_new_data();break;
                case 3:delete_something();break;
                case 9:display(); break;
                case 10:display_size();break;
                case 11:goto out; break;
        }
    }
        out: ;

    return 0;
}


void new_list()
{
        if(list_no>=head_count || size <= 0)
        {
                printf("not enough space!!!\n\n");
                return;
        }
        else
        {
                int num;
                printf(" enter number of elements you want to enter: ");
                scanf("%d",&num);

                size -= num;
                if(size <= 0)
                {
                      printf("no more space left!!!\n\n");
                      size += num;
                      return ;
                }
                else
                {
                        head[list_no]=available;
                        list_no++;
                        int i;
                        printf("Enter %d numbers: ",num);
                        for(i=0;i<num;i++)
                        {
                                int temp;
                                scanf("%d",&temp);
                                s[available].data = temp;
                                if(i != num-1) available = s[available].next;
                                if(i== num-1)
                                {
                                        int papa = s[available].next;
                                        s[available].next = -1;
                                        available = papa;
                                }
                        }
                }
        }

}

void display_one_list()
{
        printf("Enter which list you want to display: ");
        int a;
        scanf("%d",&a);
        a--;
        int index = head[a];
        printf("\nlist is: ");

        while(s[index].next != -1)
        {
                printf(" %d ->",s[index].data);
                index = s[index].next;
        }

        if(s[index].next == -1) printf(" %d-> NULL\n\n",s[index].data);

}

void display_all_list()
{
        int temp = list_no;
        int a = 0;
        while(temp--)
        {
                int index = head[a];
                printf("list no %d: ",++a);
                while(s[index].next != -1)
                {
                        printf(" %d ->",s[index].data);
                        index = s[index].next;
                }
                if(s[index].next == -1) printf(" %d-> NULL\n",s[index].data);
        }
}

void display()
{
        printf("\n1. display only one list");
        printf("\n2. display all list\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
                case 1: display_one_list(); break;
                case 2: display_all_list(); break;
                default: printf("invaiid entry:(\n"); break;
        }

}

void display_size()
{
        printf("number of element left: %d\n",size);
}

void insert_a_new_data()
{
     printf("Enter the number of list: ");
     int a;
     scanf("%d",&a);
     a--;

     printf("Enter the data: ");
     int datam;
     scanf("%d",&datam);

     printf("\n1. enter data before 1st number\n");
     printf("2. enter data at a particular positon\n");
     printf("3. enter data at the end\n\n");

     int choice;
     printf("Enter your choice: ");
     scanf("%d",&choice);
     switch(choice)
     {
           case 1: enter_before_head(datam,a);break;
           case 2: enter_at_a_position(datam,a);break;
           case 3: enter_at_end(datam,a);break;
           default: printf("!!INVALID CHOICE!! :( \n"); return;
     }
}

void enter_before_head(int datam,int a) //a contains the head position of the list
{
        int temp;
        s[available].data = datam;
        temp = s[available].next;
        s[available].next = head[a];
        head[a] = available;
        available = temp;
}

void enter_at_a_position(int datam, int a)
{
        printf("enter the position: ");
        int pos;
        scanf("%d",&pos);

        int temp = s[head[a]].next;

        int i;
        for(i=1;i<pos-1;i++)
        {
                temp = s[temp].next;
        }
        int store,temp1;
        s[available].data = datam;
        store = s[available].next;
        temp1 = s[temp].next;
        s[temp].next = available;
        s[available].next = temp1;
        available = store;
}

void enter_at_end(int datam, int a)
{
        int temp = s[head[a]].next;
        while(s[temp].next != -1)
        {
                temp = s[temp].next;
        }

        s[available].data = datam;
        int store = s[available].next;
        s[available].next = -1;
        s[temp].next = available;
        available = store;
}

void delete_something()
{
        printf("Enter the list number: ");
        int num;
        scanf("%d",&num);
        num--;

        printf("\n1. delete first element\n");
        printf("2. delete a particular element\n");
        printf("3. delete last element\n");
        printf("4. delete an entire list\n\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
                case 1: delete_first_element(num); break;
               // case 2: delete_nth_element(num);break;
               // case 3: delete_last_element(num);break;
               // case 4: delete_entire_list(num);break;
                default: printf("INVALID OPERATION :(\n"); return;
        }
}

void delete_first_element(int a)
{
       s[head[a]].data = '\0';
       int store = s[head[a]].next;
       s[head[a]].next = available;
       available = head[a];
       head[a] = store;
}

/*void delete_nth_element(int a)
{
        printf("Enter the number of the element: ");
        int n;
        scanf("%d",&n);


}*/









