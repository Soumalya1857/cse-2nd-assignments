/*singly linked list header file*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* next;
} node;

// fundtion prototypes
node* init_l(int);//initialise a list
bool atend_l(struct Node*);//boolean function to return true if cur points the end of the list
bool empty_l(node* head);
void insert_front(node** head, node* target);
void insert_after(node* prev, node* target);
void delete_front(node** phead);



node* init_l(int info)
{
    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL) 
    {
        printf("Malloc error!!\n");
        return;
    }
    else
    {
        head->data = info;
        head->next = NULL;
        return head;
    }
}
bool atend_l(node* curr)
{
    if(curr->next == NULL) return true;
    else return false;
}
bool empty_l(node* head)
{
    if(head->data == NULL && head->next == NULL)
        return true;
    else return false;
}
void insert_front(node** phead, node* target)
{
    target->next = *phead;
    *phead = target;
}
void insert_after(node* prev, node* target)
{
    target->next = prev->next;
    prev->next = target;
}
void delete_front(node** phead)
{
    node* temp;
    temp = *phead;
    *phead = temp->next;
    free(temp);
}

void delete_after(node* prev)
{
   if(atend_l(prev))
   {
       printf("current at the end if the list\n");
       return;
   }
   else
   {
        node* curr;
        curr = prev->next;
        prev->next = curr->next;
        free(curr);
   }  
}
