#include <stdio.h>

void algo(int a[][30],int n)
{
	int i,j,k;	
	for(i=1;i<=n;i++)
	{
  		a[i][i]=0;
	} 
   	for(k=1;k<=n;k++)
	{
        for(i=1;i<=n;i++)
		{
            for(j=1;j<=n;j++)
			{
                if(a[i][j]>(a[i][k]+a[k][j]))
				{
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
        printf("\nFor A%d :\n",k);
        printing(a,n);     
    }
}

printing(int a[][30],int n)
{	
	int i,j;
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\t\t%d",a[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	printf("....All pairs shortest path....\n\n");
    int n,a[30][30],i,j,k;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\n");
    for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
		{
            printf("Enter the value of row %d and column %d :",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\n");
    printf("Your input (A0) : \n");
    printing(a,n);
    algo(a,n);  
    printf("\n\nResult : \n");
    printing(a,n);
	getch();  
}
