#include <stdio.h>
#include <stdlib.h>

void main()
{
	printf("....Bellman Ford....\n\n");
    int n,i,j,k=1,v=1,dist[30][30],u,s,a[30][30],cost[30][30];
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\n");
    printf("If there is no connection input ' 9999 ' \n"); 
    for(i=1;i<=n;i++)
	{
    	for(j=1;j<=n;j++)
		{
    		if(i==j)
			{
    			cost[i][j]=0;
			}
			else
			{
    			printf("\n Enter the cost from %d to %d : ",i,j);
    			scanf("%d",&cost[i][j]);
			}
		}
	}
	for(i=1;i<=n-1;i++)
	{
   		for(j=1;j<=n;j++)
		{
   			dist[i][j]=INT_MAX;
	   	}
	} 
	for(i=1;i<=n;i++)
	{
        if(dist[1][i]>cost[v][i])
		{
        	dist[1][i]=cost[v][i];
		}
	}
	for(i=2;i<=n-1;i++)
	{
    	for(j=1;j<=n;j++)
    	{
        	dist[i][j]=dist[1][j];  
    	}
	}
    for(k=2;k<=n-1;k++)
	{
    	for(u=2;u<=n;u++)
		{
            for(i=2;i<=n;i++)
			{
            	if(cost[i][u]<999 && i!=u)
            	{
                	if(dist[k][u]>dist[k-1][i]+cost[i][u])
					{
                    	dist[k][u]=dist[k-1][i]+cost[i][u];  
                	}
           		}      
        	}   
        }
    }
    printf("\n The Result :\n");
    printf("\t");
	for(i=1;i<=n;i++)
	{
		printf("\t%d",i);
	}
	printf("\n\n");
	for(i=1;i<=n-1;i++)
	{
   		printf("\t%d",i);
   		for(j=1;j<=n;j++)
		{		
   			printf("\t%d",dist[i][j]);
		}
		printf("\n");
	}  
 	getch();   
}
