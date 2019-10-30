#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>



struct student{
	
	int roll;
	char name[50];
	int score1;
	int score2;
	//int score3;
	//int score4;
	//int score5;
}s;

void add_data()
{	
	
	FILE *fp;
	fp = fopen("myfile.txt","w+");
	if(fp == NULL){ printf("unable to open\n"); exit(1);}
	else{
		int n;
		printf("Enter number of rec to add: ");
		scanf("%d",&n);
	
	//p = (struct student*)malloc(n*sizeof(s));
	
		int i;
		for(i=0;i<n;i++)
		{	
			struct student p;
			printf("enter the roll number for record %d: ",i+1);
			scanf("%d",&p.roll);
		
			printf("enter the name: ");
			scanf("%s",p.name);
			
			printf("enter the 1st subject score: ");
			scanf("%d",&p.score1);
		
			printf("enter the 2nd subject score: ");
			scanf("%d",&p.score2);
		
			fprintf(fp,"%d\t%s\t%d\t%d\t\n",p.roll,p.name,p.score1,p.score2);
		}
	}
	fclose(fp);
}


void display(){

	FILE *fp;
	fp = fopen("myfile.dat","r");
	
	if(fp == NULL)
	{
		printf("unable to open file \n");
		exit(1);
	}
	else{
		struct student p;
		int count =0;
		while((fread(&p,sizeof(struct student),1,fp))!=0)
		{
			fread(&p,sizeof(struct student),1,fp);
			printf("%d\t%s\t%d\t%d\t\n",p.roll,p.name,p.score1,p.score2);
			count++;
			fseek(fp,count*sizeof(struct student),0);
		}
		
		fclose(fp);
	}
}

void search_data()
{

	int roll;
	FILE *fp;
	fp = fopen("myfile.dat","r");
	if(fp == NULL)
	{
		printf("unable to open file\n");
		exit(1);
	}
	else{
	
		struct student p;
		printf("enter your number: ");
		scanf("%d",&roll);
		int check =0;
		while(fread(&p,sizeof(p),1,fp)!=0)
		{
			if(p.roll == roll)
			{
				check = 1;
				break;
			}
		}
		//printf("checkkkkkkkkkkkkkkk %d\n\n",check);
		if(check == 0) printf("no such roll no exists\n");
		else{
			printf("roll no exists\n");
		}
		
		fclose(fp);
		
	}
}
int main()
{	
	
	
		//add_data();
		//display();
		search_data();
	
	
	return 0;
}


