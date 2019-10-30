#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int i;
    char num[15];
    FILE *fp;
    fp = fopen("mynumber.txt","w+");
    for(i=0;i<1000;i++)
    {
          num = rand()%1000000;
          fprintf(fp,"%s",num);
          fprintf("\n");
    }
    fclose(fp);

    }
    return 0;
}
