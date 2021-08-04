#include<stdio.h>
#include<stdlib.h>

int i,j;

void solve(int arr[], int mat[][50], int s[][50], int n)
{
	int k,q,l;
	for(i=1;i<n;i++)
	{
    	mat[i][i]=0;
  	}
  	for(l=2;l<=n;l++)
  	{
    	for(i=1;i<=n-l+1;i++)
		{
      		j=i+l-1;
      		mat[i][j]= 9999999;
      		for(k=i;k<=j-1;k++)
	  		{
        		q = (mat[i][k]+mat[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
        		if(q<mat[i][j])
				{
          			mat[i][j]=q;
          			s[i][j]=k;
        		}
      		}
    	}
  	}
  	printf("\nResultant M matrix is:\n");
  	for(i=1;i<=n;i++)
  	{
    	for(j=1;j<=n;j++)
		{
      		if(i>j)
	  		{
        		printf("-1 ");
      		}
      		else 
	  			printf("%d ",mat[i][j]);
    	}
    	printf("\n");
  	}
  	printf("\nResultant S matrix is:\n");
  	for(i=1;i<=n;i++)
  	{
    	for(j=1;j<=n;j++)
		{
      		if(i>j)
	  		{
        		printf("-1 ");
      		}
      		else 
		  		printf("%d ",s[i][j]);
    	}
    	printf("\n");
  	}  
}

void print_paranthesis(int s[][50],int i,int j)
{
	if(i==j)
  	{
    	printf("A[%d]",i);
  	}
  	else
  	{
    	printf("(");
    	print_paranthesis(s,i,s[i][j]);
    	print_paranthesis(s,s[i][j]+1,j);
    	printf(")");
  	}
}

void main()
{
  	int n, v, p[50], mat[50][50], s[50][50];
  	printf("Enter number of matrices: ");
  	scanf("%d",&n);
  	v = n+1;
  	printf("Enter the dimensions: ");
  	for(i=0;i<v;i++)
  	{
    	scanf("%d",&p[i]);
  	}
  	printf("Input dimensions are: ");
  	for(i=0;i<v;i++)
  	{
    	printf("%d ",p[i]);
  	}
  	solve(p,mat,s,n);
  	printf("\nOptimal Parenthesis Solution is: ");
  	print_paranthesis(s,1,n);
  	printf("\nNumber of multiplication is: %d",mat[1][n]);
  	getch();
}

