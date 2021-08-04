#include<stdio.h>

int largest(int dl[], int n);
void swap(int *xp, int *yp);
int min(int max, int a);
void printArray(int dl[], int n);

int largest(int dl[], int n)
{
	int i,max=dl[0];
	for(i=1;i<n;i++)
	{
		if(max<dl[i])
		{
			max=dl[i];
		}
	}
	return (max);
}

int min(int max, int a)
{
	if(max>a)
	{
		return a;
	}
	else
	{
		return max;
	}
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int dl[], int n)
{
    int i;
    for (i=1; i <= n; i++)
    {	
		printf("%d ", dl[i]);
	}
    printf("\n");
}

void main()
{
	printf(">>> Job sequencing problem with deadline <<<");
	printf("\n\n");
	int dl[50],p[50],i,j,n,max,tsj[20],tsdl[20],tsp[20],k,job[50];
	printf("Enter number of jobs: ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the deadline of job A%d : ",i+1);
		scanf("%d",&dl[i]);
		printf("Enter the profit of job A%d : ",i+1);
		scanf("%d",&p[i]);printf("\n");
	}
	for(i=0;i<n;i++)
	{
		job[i]=i+1;
	}	
	printf("\nUser Input : \n");
	for (i=0; i<n; i++)
    {
		printf("Job: A%d  -> Deadline: %d -> Profit: %d\n", job[i],dl[i],p[i]);
	}
    printf("\n");
	max = largest(dl,n);
	int max_idx;
    for (i = 0; i < n-1; i++)
    {
        max_idx = i;
        for (j = i+1; j < n; j++)
          if (p[j] > p[max_idx])
            max_idx = j;
        swap(&dl[max_idx], &dl[i]);
        swap(&p[max_idx], &p[i]);
        swap(&job[max_idx], &job[i]);   
    }	
	for(i=0;i<max;i++)
	{
		tsj[i]=i+1;
	}
	printf("\nAfter arranging : \n");
    for (i=0; i<n; i++)
    {
		printf("Job: A%d  -> Deadline: %d -> Profit: %d\n", job[i],dl[i],p[i]);
	}
    printf("\n");   
    printf("\nTotal number of time slots user can access: %d \n",max);  
    for(i=0;i<=n;i++)
	{	
    	tsdl[i]=0;
    	tsp[i]=0;	
	}	
    int l;
    for(i=0;i<n;i++)
	{
    	k=min(max,dl[i]);
    	while(k>=1)
		{
    		if(tsp[k]==0)
			{
    			tsj[k]=job[i];	
    			tsdl[k]=dl[i];
    			tsp[k]=p[i];
				break;		
			}
			k=k-1;
		}
    }
	int tp=0;
	printf("\nResult: \n");	
	printf("Time slot      status       Deadline        Profit  \n");
	printf("------------------------------------------------------\n");
	for(i=1; i<=max ; i++)
	{
		printf("   %d            A%d            %d              %d\n",i,tsj[i],tsdl[i],tsp[i]);
	}
	printf("------------------------------------------------------\n");
	printf("\n");
	printf("Job sequence : ");
	for(i=1; i<=max ; i++)
	{
		printf(" A%d ",tsj[i]);
	}
	printf("\n");
	for (i=0; i<=max; i++)
    {
		tp=tp+tsp[i];
	}
    printf("\nTotal profit: %d",tp);    
	getch();
}

