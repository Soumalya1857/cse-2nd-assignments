#include<stdio.h>
#include<malloc.h>
typedef struct 
{
    int roll;
    char name[30];
    int score;
}student;

struct node
{
    student s;
    struct node *nptr;
};

void get_data(student *st)
{
    printf("Enter the student details: \n");
    printf("Name: ");
    scanf("%s",st->name);
    printf("Roll: ");
    scanf("%d",&st->roll);
    printf("Score: ");
    scanf("%d",&st->score);
}

void create(struct node **hp)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->nptr=NULL;
    get_data(&(p->s));
    *hp=p;
}

void append(struct node *h)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->nptr=NULL;
    get_data(&(p->s));
    while(h->nptr!=NULL)
    {
        h=h->nptr;
    }
    h->nptr=p;
    printf("Record successfully added!\n");
}

void del(struct node **hp,int k)
{
    struct node *pre,*cur;
    cur=*hp;
    if((cur->s).roll==k)
    {
        *hp=(*hp)->nptr;
        free(cur);
        printf("Record successfully deleted!\n");
    }
    else
    {
        pre=cur;
        cur=(*hp)->nptr;
        while(cur!=NULL)
        {
            if(((cur)->s).roll==k)
                break;
            pre=cur;
            cur=(cur)->nptr;
        }
        if(cur==NULL)
        {
            printf("No such record exists!\n");
        }
        else
        {
            (pre)->nptr=(cur)->nptr;
            free(cur);
            printf("Record successfully deleted!\n");
        }
    }
}

void dis(student st)
{
    printf("Name: %s\nRoll: %d\nScore: %d\n.............................................\n",st.name,st.roll,st.score);
}

void display_list(struct node *hp)
{
    if(hp==NULL)
    {
        printf("No records present!\n");
    }
    else
    {
        while(hp!=NULL)
        {
            dis(hp->s);
            hp=hp->nptr;
        }
    }
}

void del_list(struct node *hp)
{
    struct node *p;
    while(hp!=NULL)
    {
        p=hp;
        free(p);
        hp=hp->nptr;
    }
}

int main()
{

    struct node *head;
    head=NULL;

    printf("For the first student: \n");
    create(&head);

    printf("Press the following for the corresponding operations: ........ \n");
    int c;
    int k=0;
    while(1)
    {
        printf("1.......Add a new student\n");
        printf("2.......Delete an existing student\n");
        printf("3.......Display the list of existing students\n");
        printf("PRESS ANY OTHER BUTTON TO EXIT!\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:   if(head==NULL)
                            create(&head);
                        else
                        {
                            append(head);
                        }
                        break;

            case 2:     if(head==NULL)
                        {
                            printf("No records present!\n");
                            break;
                        }
                        else
                        {
                            printf("Enter the roll of the student who has to be deleted: ");
                            scanf("%d",&k);
                            del(&head,k);
                            break; 
                        }

            case 3:     display_list(head);

                        break;
            default:    del_list(head);
                        return 0;
        }
    
    }

    return 0;
}
