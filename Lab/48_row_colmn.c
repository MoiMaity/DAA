#include<stdio.h>

void row_sort(int arr[][20], int n, int m)
{	
	int i,j,k,temp;
	for(k=0;k<n;k++)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<m-1-i;j++)
			{
				if(arr[k][j]>arr[k][j+1])
				{
					temp=arr[k][j+1];
					arr[k][j+1]=arr[k][j];
					arr[k][j]=temp;
				}
			}
		}	
	}		
}

void col_sort(int arr[][20], int n, int m)
{
	int i,j,k,temp;
	for (k=0;k<m;k++)
	{
		for (i=0;i<n;i++) 
		{
			for (j=0;j<n-1-i;j++) 
			{
				if (arr[j][k]>arr[j + 1][k]) 
				{
					temp=arr[j+1][k];
					arr[j+1][k]=arr[j][k];
					arr[j][k]=temp;
				}
			}
		}
	}
}

void display(int arr[][20],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int n,m;
	int i,j;
	int arr[20][20];
	printf("Enter Number of Rows: ");
	scanf("%d",&n); 
	printf("Enter Number of Columns: ");
	scanf("%d",&m);
	printf("\n");
	printf("Enter Array Elements :\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			printf("Enter arr[%d][%d] :",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\n");
	printf("Given matrix is :");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	row_sort(arr,n,m);
	printf("Array After Sorting Row-wise: \n");
	display(arr,n,m);
	printf("\n\n");
	col_sort(arr, n, m);
	printf("Array After Sorting Column-wise: \n");
	display(arr,n,m);
	getch();
}
