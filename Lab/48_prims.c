#include <stdio.h>  
#include <limits.h>  

int i,j;
  
int minimum_key(int k[], int mst[], int n)  
{  
	int minimum=INT_MAX,min,i;  
	for (i=0; i<n; i++)
	{ 
    	if (mst[i]==0 && k[i]<minimum)  
        	minimum=k[i], min=i; 
	}
   return min;  
}  
  
void prim(int g[][50], int n)  
{  
    int parent[n];   
    int k[n];     
    int mst[n];    
    int i,count,u,v,s=0;   
    for (i=0; i<n; i++)
	{  
        k[i]=INT_MAX, mst[i]=0;
	}
    k[0]=0;       
    parent[0]=-1;   
    for (i=0; i<n-1; i++)  
	{  
    	u=minimum_key(k, mst, n);  
        mst[u]=1;  
        for (v=0; v<n; v++)
		{
        	if (g[u][v] && mst[v] == 0 && g[u][v] < k[v])  
            	parent[v]=u, k[v]=g[u][v]; 
		}
    }  
	printf("\n Source\tDestination\tCost\n");
	printf("------\t-----------\t----\n\n");
	for (i=1; i<n; i++)
	{
		printf("   %d        %d           %d \n",parent[i],i,g[i][parent[i]]); 
		s=s+g[i][parent[i]];
	}
	printf("\n Total Cost of MST : %d",s);
}  
   
void main()  
{  
	int n;
	int s,f,c;
	int g[50][50];
	printf("------PRIM'S ALGORITHM TO FIND MINIMUM SPANNING TREE------\n\n");  
	printf("Enter the number of vertices: ");
	scanf("%d",&n);	
	printf("\n Enter the cost values (999 for infinite) :\n");
	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			if (i==j)
				g[i][j] = 0;	
			else
			{			
				printf("Between pair %d ---> %d:\t", i+1, j+1);
				scanf("%d", &g[i][j]);
				g[j][i] = g[i][j];
			}
		}
	}	
	printf("\n Minimum Spanning Tree:\n");
    prim(g,n);  
    getch();
}
