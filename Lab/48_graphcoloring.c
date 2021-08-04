#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int i,j;

int mcolor(int k, int g[][50], int x[50],int n, int m)
{
	while(1)
	{
		nextvalue(k,g,x,n,m);
		if(x[k]==0)
		{
			return;
		}
		if(k==n)
		{
			for(i=1;i<=n;i++)
			{
				printf("%d ",x[i]);
			}
			printf("\n\n");
		}
		else
		{
			mcolor(k+1,g,x,n,m);
		}
	}
}

int nextvalue(int k, int g[][50], int x[50], int n, int m)
{
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
		{
			return;
		}
		for(j=1;j<=n;j++)
		{
			if((g[k][j]!=0) && (x[k]==x[j]))
			{
				break;
			}
		}
		if(j==(n+1))
		{
			return;
		}
	}
}

void main()
{
	int n,m,x[50];
	int g[50][50];
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the number of colors: ");
	scanf("%d",&m);
	printf("\nEnter the adjacency values: 1 if connection, 0 if no connection and 0 for self:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nFrom %d to %d: ",i,j);
			scanf("%d",&g[i][j]);
		}
	}
	for(i=1;i<=m;i++)
	{
		x[i]=0;
	}
	printf("\nPossible solution sets are:\n");
	printf("\n");
	mcolor(1, g, x, n, m);
	nextvalue(1, g, x, n, m);
	getch();	
}








