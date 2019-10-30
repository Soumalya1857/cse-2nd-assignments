#include <stdio.h>
#include <stdlib.h>


struct element
{
        int coeff;
        int degree;
};
  struct element poly[25];
  int pos[11]={0};

/*struct position
{
      int first;
      int last;
};
*/

void addition_of_2_polynomials(struct element* poly, int* pos)
{
        register int i,j;

        printf("enter the 1st polynomial number: ");
        int first;
        scanf("%d",&first);

        printf("enter the 2nd polynomial number: ");
        int second;
        scanf("%d",&second);

        int start1 = pos[first-1];
        int end1 = pos[first];
        int len1 = end1-start1;

        int start2 = pos[second-1];
        int end2 = pos[second];
        int len2 = end2-start2;

       /* int array[20];
        for(i=0;i<20;i++) array[i] = -1;*/

        printf("polynomial after addition: ");

        i=start1;
        j=start2;
        while(i<end1 && j<end2)
        {
                if(poly[i].degree > poly[j].degree && poly[i].degree != 0 && poly[j].degree !=0)
                {
                        printf("%dx^%d+",poly[i].coeff,poly[i].degree);
                        i++;
                }
                else if(poly[i].degree < poly[j].degree && poly[i].degree != 0 && poly[j].degree !=0)
                {
                        printf("%dx^%d+",poly[j].coeff,poly[j].degree);
                        j++;
                }
                else
                {
                        if(poly[i].degree == poly[j].degree && poly[i].degree + poly[j].degree!=0)
                        {
                                int mama = poly[i].coeff + poly[j].coeff;
                                printf("%dx^%d+",mama,poly[i].degree);
                                i++;
                                j++;
                        }
                }
                else if(poly[i].degree + poly[j].degree==0 ||poly[i].degree ==0 || poly[j].degree==0)
                {
                        if(poly[i].degree ==0 && poly[j].degree!=0)
                        {
                                printf("+%dx^%d ",poly[i].coeff,poly[i].degree);
                        }
                        else if(poly[j].degree ==0 && poly[i].degree!=0)
                        {
                               printf("+%dx^%d ",poly[j].coeff,poly[j].degree);

                        }
                        else if(poly[i].degree ==0 && poly[j].degree==0)
                        {
                                int mama = poly[i].coeff + poly[j].coeff;
                                printf("%d",mama);
                        }
                }
        }
        printf("\n");
}

void addition_of_n_polynomial(struct element* poly, int* pos)
{
        printf("\nwould you like to display all polynomials?");
        printf("1 for yes\n0 for no\n");
        printf("Enter your number: ");
        int choice;
        scanf("%d",&choice);

        if(choice == 1) display();

        printf("enter number of %d polynomials: ");
        register int i;
        int a[number];
        int number;
        scanf("%d",&number);

        for(i=0;i<number;i++)
        {
                scanf("%d",&a[i]);
        }

        int power[11]={0};
        for(i=0;i<number;i++)
        {
                int p = pos[a[i]-1];
                while(p < pos[a[i])
                {
                        power[poly[p].degree] += power[p].coeff;
                        p++;
                }
        }

        int check=0;
        for(i=0;i<11;i++)
        {
                if(power[i]!=0) break;
                else check++;
        }

        for(i=11;i>check;i--)
        {
                if(power[i]!=0) printf("%dx^%d+",power[i],i);
        }

        if(check==0) printf("%d \n",power[0]);
        else printf("%dx^%d \n",power[check],check);

}

void multiplication(struct element* poly,int* pos)
{
       int power[21]={0};//ith element contains coeff of x^i

        printf("\nwould you like to display all polynomials?");
        printf("1 for yes\n0 for no\n");
        printf("Enter your number: ");
        int choice;
        scanf("%d",&choice);

        if(choice == 1) display();

        printf("\n Enter serial no of 1st polynomial: ");
        int first;
        scanf("%d",&first);

        printf("\n Enter serial no of 2nd polynomial: ");
        int second;
        scanf("%d",&second);

        register int i,j;
        for(i=pos[first-1],i<pos[first],i++)
        {
                for(j=pos[second-1],j<pos[second],j++)
                {
                        int temp = poly[i].degree + poly[j].degree;
                        int temp1 = poly[i].coeff*poly[j].coeff;

                        power[temp] += temp1;
                }
        }

        int check=0;
        for(i=0;i<20;i++)
        {
                if(power[i]==0) check++;
                else break;
        }
        printf("polynomial after multiplication: ");
        for(i=20,i>=0;i--)
        {
                if(power[i]!=0)
                {
                        printf("%dx^%d+",power[i],i);
                }
        }

        printf("0\n\n");

}

int main()
{

        printf("\n\nEnter number of polynomial you want to add: ");
        int num;
        scanf("%d",&num);

        //using 0 indexing
       // struct position pos[10];
       // pos[0].first = 0;



        register int i,j;
        int count=0;
        printf("\n///***Enter the values of polynomials with decending power of degrees***///\n");
        for(i=0;i<num;i++)
        {
                printf("enter the no of terms in polynomial %d: ",i+1);
                int term;
                scanf("%d",&term);
                for(j=0;j<term;j++)
                {
                        printf("enter the degree of element %d: ",j+1);
                        scanf("%d",&poly[count].degree);

                        printf("enter the coefficient of element %d: ",j+1);
                        scanf("%d",&poly[count].coeff);

                        count++;
                }

                pos[i+1] = pos[i]+term;//contains start and end of each polynomial...
        }

        return 0;
}
