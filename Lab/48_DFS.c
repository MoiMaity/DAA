#include <stdio.h>
#include<stdlib.h>

int top=0,s[20],visit[20],n,a[20][20],i,j,u;

void dfs(int v)
{
	if(top>-1)
    {
    	if(!visit[v])
		{
        	printf("V%d  ",v);
    	}
    	visit[v]=1;
    	for(u=1;u<=n;u++)
		{
        	if(!visit[u] && a[v][u])
			{
            	s[top]=u;
            	top++;
        	}
    	}
    	top--;
    	dfs(s[top]);    
   }
}

void main()
{ 
    printf("....DFS ALGORITHM.....\n\n");
    printf("Enter the no. of Vertices : ");
    scanf("%d",&n);
    printf("\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		printf("From V%d to V%d :",i,j);
    		scanf("%d",&a[i][j]);
    		printf("\n");
    	}
	}
	printf("\n");
    printf(".......ADJACENCY MATRIX.......\n\n");
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
		{
		 	printf(" %d\t",a[i][j]);	
		}
		printf("\n\n");	
	}
    for(i=1;i<=n;i++)
	{
        visit[i]=0;
        s[i]=0;
    }
    s[top]=1;
    top++;
    printf("TRAVERSAL SEQUENCE OF GRAPH USING DFS : \n");
  	dfs(1);
	getch();
}
