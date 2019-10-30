#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct
{
    char name[30];
    int age;
}person;

void get_data(person *arr,int n)
{
    int i=0;

    printf("Enter the data: ");

    for(i=0;i<n;i++)
    {
        printf("\nFor person %d: \n",i+1);
        printf("Name: ");
        scanf("%s",arr[i].name);
        printf("Age: ");
        scanf("%d",&arr[i].age);
    }

}

void sort_age(person *arr,int n)
{
    int i=0,j=0;
    person t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j].age>arr[j+1].age)
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}

void show_data(person *arr,int n)
{
    printf("The data in sorted order according to age: \n");
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("Name: %s\n",arr[i].name);
        printf("Age: %d\n",arr[i].age);
    }

}
void largest_name(person *arr,int n)
{
        int maxi = -1;
        int mini = -1;
        int index_max,index_min;
        int i;
        for(i=0;i<n;i++)
        {
                int mama = strlen(arr[i].name);
                if(mama>maxi)
                {
                      maxi = mama;
                      index_max = i;
                }
                if(mama<mini)
                {
                        mini = mama;
                        index_min = i;
                }
        }
        printf("largest name: %s\n",arr[index_max].name);

        printf("smallest name: %s\n",arr[index_min].name);

}



int main()
{
    int n=0;
    printf("Enter the number of persons to be worked with: ");
    scanf("%d",&n);

    person *arr=(person *)malloc(n*sizeof(person));

    get_data(arr,n);

    sort_age(arr,n);

    show_data(arr,n);

    largest_name(arr,n);

    free(arr);

    return 0;
}
