#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

int x[20],i;

bool place(int k,int j,int n)
{ 
    for(i=1;i<=k-1;i++)
	{
        if((x[i]==j)||(abs(x[i]-j)==abs(i-k)))
		{
            return false;
        }
    }
    return true;
}

int nqueen(int k,int n)
{
    int j;
    for (j=1;j<=n;j++)
	{
        if(place(k,j,n))
		{
            x[k]=j;
            if(k==n)
			{
                for(i=1;i<=n;i++)
				{
                    printf(" %d ",x[i]);
                }
                printf("\n");
            }
            else
			{
                nqueen(k+1,n);
            }
        } 
    }
}

void main()
{
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
        x[i]=0;
    }   
    printf("\nPossible solution sets : \n\n");
    nqueen(1,n);
    getch();
}
