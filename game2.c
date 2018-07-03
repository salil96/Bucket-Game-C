#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include <time.h>


//****************************************************************
void pat(int a[],int n,int po)
	{	static int cou=0;
		int k=0,i,j;
		if(cou%2==0 || po==0)
		system("clear");
		cou++;
		//printf("\n\n\n\n");
		for(j=0;j<n;j++)
		{
			for(i=0;i<n && k<n;i++,k++)
			{
			 	printf("   || %d ||   ",a[i]);
		        }
		if(j==0)
		printf("\n");
		printf("   ||___||   ");
		}printf("\n");
		for(i=0;i<po;i++)
		{
			if(i==0)
			printf("       ");
			else
			printf("             ");
		}
		if(po>0);
		printf("*\n\n");
	}
//*****************************************************************
void mychance(int a[],int n,int *sum)
{
	int i,ans=0,dif=0,po,flag,box,fla;

	for(i=0;i<n;i++)
		ans=ans^a[i];

	for(i=0;i<n;i++)
	{
		if((ans^a[i])<a[i])
		{
		 dif=a[i]-(ans^a[i]);
		 po=i+1;
		 a[i]-=dif;
		 *sum-=dif;
		 pat(a,n,po);
		printf("\nSYSTEM CHOSEN BOX = %d\n",po);
		printf("AND TOOK FRUIT = %d\n\n",dif);
		break;
		}	
	}
	if(i==n)
	{        do
		{
			box=(rand()%n);
			if(a[box]==0)
			    fla=1;
			
			else
			    fla=0;
		}while(fla);
		//for(i=0;i<n;i++)
		//if(a[i]!=0)
		{
		 	do
			{
				 dif=rand()%(a[box]+1);
				 if(dif==0)
				  flag=1;
				 else
				 flag=0;
			}while(flag);
			
		 // box=i;
		 a[box]-=dif;
		 *sum-=dif;
		 pat(a,n,box+1);
		printf("SYSTEM CHOSES BOX = %d\n",box+1);
		printf("AND TOOK FRUIT = %d\n\n",dif);
		//break;	
		}	
	}
}
	
int main()
{
	int n,i,a[100]={0},count=0,sum=0,po,te,flag=0,cho,max;
	printf("\t\t\tBOX GAME \n\n");
	        printf("   ||   ||      ||   ||      ||   ||   \n");
		printf("   ||___||      ||___||      ||___||   \n");
		printf("HOW MANY BOX U WANT: = ");
		scanf("%d",&n);
		pat(a,n,0);
		printf("\nINSERT FRUIT IN EACH BOX\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			//a[i]=random(max)%10;
			sum+=a[i];
			
			
			
		}pat(a,n,0);
		
		printf("\n\nTHERE ARE TWO PLAYER \n1: SYSTEM\n2: YOU\n");
		printf("CHOSE YOUR CHANCE\nCHANCE:1\nCHANCE:2");
		scanf("%d",&cho);
		switch(cho)
		{
		 case 1:
		      count=1;
		      break;
		 case 2:
		      count=2;
		      break;
		}
		 while(sum!=0)
		{   
			if(count%2==0)
			{
			 printf("SYSTEM CHANCE\n\n");

			 // for time delay 
			 for (int c = 1; c <= 32767; c++)
			       for (int d = 1; d <= 32767; d++)
			       {}
			 mychance(a,n,&sum);
			}
			else
			{
		 		printf("\nYOUR CHANCE\n\n");
				do
				{
		 			printf("CHOSE YOUR BOX = ");
		 			scanf("%d",&po);
		  			printf("HOW MANY FRUIT U WANT TO TAKE= ");
					scanf("%d",&te);
					
					if(te>a[po-1] || te<=0)
					{
				 		flag=1;
				 		printf("AGAIN\n");
					}
					else
					{
						a[po-1]-=te;
						flag=0;
						sum-=te;
						pat(a,n,po);
					}
				}while(flag);
			}
			count++;
			if(sum==0)
			{
			 if(count%2==0)
			     printf("\n\nYOU WON THE GAME\n\n");
			 else
			     printf("\n\nYOU LOSE THE GAME\n\n");
			}
			
		}

}
