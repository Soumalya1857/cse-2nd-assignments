#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
        srand(time(0));
        FILE *fp;
        fp = fopen("mystring.txt","w+");
        int i=0,j=0;
        for(i=0;i<10000;i++)
        {
                for(j=0;j<10;j++)
                {
                        char c = rand()%26 + 65;
                        fprintf(fp,"%c",c);
                }
                fprintf(fp,"\n");
        }
        fclose(fp);

        return 0;
}
