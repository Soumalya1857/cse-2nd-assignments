#include<stdio.h>
#include"singly_linked_list_header.h"
#define MAX 10

int counter = 0;
typedef struct Node
{
    int data;
    struct Node* next;
} node;
node* head_ref[MAX] ;

//function prototypes
void create_a_list();
void print_a_list();


int main()
{    
   while(1)
   {
        printf("\n****************MENU**************\n");
        printf("1. create a list\n");
        printf("2. print the list\n");
        printf("***************************************\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create_a_list();break;
            case 2: 
            default: printf("INVALID CHOICE!!!\n");break;
        }
        
   }
    return 0;
}

void create_a_list()
{
    if(counter >= MAX) 
    {
        printf("CAN'T INITIALIZE A NEW LIST\nMaximum number of list limit rached!!\n");
        return;
    }
    else
    {
        printf("Enter your data: ");
        int info;
        scanf("%d",&info);
        head_ref[counter++] = init_l(info);
        printf("A new list has been created!!\n");
    }
}

void print_a_list()
{
    printf("\n1. print a particular list\n");
    printf("2.print all lists\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: printf("Enter the number of list you want to print: ");
                int choice;
                choice--;
                print_a_particular_list(choice);
                break;
        case 2: print_all_list();break;
        default: printf("INVALID INPUT\n"); break;
    }
}

void print_a_particular_list(int choice)
{
    printf("Enter the number of list you want to print: ");
    int choice;
    choice--;
    node* head = head_ref[choice];
    if(empty_l(head))
    {
        printf("the list is empty!!\n");
    }
    else
    {
        while(head->next != NULL)
        {
            printf("%d->",head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
    
}

void print_all_list()
{

}
