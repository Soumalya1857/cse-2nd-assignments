/*programe to build a string using array without sentinel*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 100
#define max 10 // contains maximum number of strings to be stored at once

char string[LEN];
int available = LEN;
int head[max];
int pointer = 0;// contains starting index of a string
int head_count = 0;

//function prototypes
void create_string();
void display_string();
void display_one_string();
void display_all_string();


int main()
{
    while(1)
    {
        printf("\n********MENU********\n");
        printf("1. Create a new string.\n");
        printf("2. merge two strings.\n");
        printf("3. display strings\n");
        printf("4.delete a particular string\n");
        printf("9.show available space left\n");
        printf("10. exit the programe\n");
        printf("--------------------------------------\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create_string(); break;
            case 2: 
            case 3:display_string(); break; 
            case 9: printf("Available space: %d\n",available); break;
            case 10: goto out; break;
            default: printf("INVALID CHOICE :(\n"); break;
        }
    }
    out: ;
    return 0;
}

void create_string()
{
    printf("Enter your string: ");
    char temp[LEN];
    getchar();
    scanf("%[^\n]s",temp);
    int length = strlen(temp);
    if(length > available)
    {
        printf("NO AVAILAVLE SPACE!! TRY A SHORTER STRING\n");
        return ;
    }
    else if(head_count >= (max-1))
    {
        printf("MAX NUMBER OF STRING LIMIT REACHED!!!\n");
        return;
    }
    else
    {
        available -= length;
        head[head_count++] = pointer;
        int store = pointer;
        pointer += length;
        int i;
        for(i=0;i<length;i++)
        {
            string[store++] = temp[i];
        }
    }
}

void display_string()
{
    printf("\n1. display one particular string\n");
    printf("2. display all strings\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:display_one_string();break;
        case 2: display_all_string();break;
        default: printf("INVALID CHOICE\n"); break;
    }
}

void display_one_string()
{
    printf("Enter which string you want to display: ");
    int num;
    scanf("%d",&num);
    if(num >= max) 
    {
        printf("STRING DOESN'T EXIST\n");
        return;
    }
    else
    {
        int i;
        int end = head[num];
        int start = head[num-1];
        printf("Your string is: ");
        for(i=start;i<end;i++)
            printf("%c",string[i]);
        printf("\n");
    }
    
}

void display_all_string()
{
    int i,j=1;
    
}