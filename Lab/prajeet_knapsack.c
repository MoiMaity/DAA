#include<stdio.h>
#include<stdlib.h>

void sort(float *arr, int basis, int n)
{
	int i,j;
	float temp;
	if (basis == 1)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n-i-1; j++)
			{
				if (*(arr + j) < *(arr + j + 1))
				{
					temp = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = temp;

					temp = *(arr +  + n + j);
					*(arr + n + j) = *(arr + n + j + 1);
					*(arr + n + j + 1) = temp;

					temp = *(arr + 2*n + j);
					*(arr + 2*n + j) = *(arr + 2*n + j + 1);
					*(arr + 2*n + j + 1) = temp;

					temp = *(arr + 3*n + j);
					*(arr + 3*n + j) = *(arr + 3*n + j + 1);
					*(arr + 3*n + j + 1) = temp;
				}
			}
		}
	}
	else if (basis == 2)
		{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n-i-1; j++)
			{
				if (*(arr + n + j) > *(arr + n + j + 1))
				{
					temp = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = temp;

					temp = *(arr +  + n + j);
					*(arr + n + j) = *(arr + n + j + 1);
					*(arr + n + j + 1) = temp;

					temp = *(arr + 2*n + j);
					*(arr + 2*n + j) = *(arr + 2*n + j + 1);
					*(arr + 2*n + j + 1) = temp;

					temp = *(arr + 3*n + j);
					*(arr + 3*n + j) = *(arr + 3*n + j + 1);
					*(arr + 3*n + j + 1) = temp;
				}
			}
		}
	}
	else if (basis == 3)
		{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n-i-1; j++)
			{
				if (*(arr + 2*n + j) < *(arr + 2*n + j + 1))
				{
					temp = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = temp;

					temp = *(arr +  + n + j);
					*(arr + n + j) = *(arr + n + j + 1);
					*(arr + n + j + 1) = temp;

					temp = *(arr + 2*n + j);
					*(arr + 2*n + j) = *(arr + 2*n + j + 1);
					*(arr + 2*n + j + 1) = temp;

					temp = *(arr + 3*n + j);
					*(arr + 3*n + j) = *(arr + 3*n + j + 1);
					*(arr + 3*n + j + 1) = temp;
				}
			}
		}
	}
}

void strategy( float *arr, int strategy_num, int n, float m)
{
	int i;
	sort(arr,strategy_num,n);
	float *vector = (float *)calloc(n,sizeof(float));
	float total_profit = 0;
	int index;
	float frac;
	printf("\n\n\n\n\n-------------------------Using Strategy %d-------------------------\n",strategy_num);
	printf("Item Added\tNumber of units used\t\tCapacity left\t\t\tProfit\n");
	for ( i = 0; ((i < n) && (m > 0)); i ++)
	{
		if ( *(arr + n + i) <= m )
		{
			total_profit += *(arr + i);
			m -= *(arr + n + i);
			index = (int)*(arr + 3*n + i);
			*(vector + index) = 1.00;
			printf("%d \t\t %d \t\t\t\t %f  \t\t\t %f\n", index + 1, 1, m, *(arr + i));
		}
		else
		{
			frac = m / *(arr + n + i);
			total_profit = total_profit + (frac * (*(arr + i)));
			index = (int)*(arr + 3*n + i);
			*(vector + index) = frac;
			m = 0;
			printf("%d \t\t %f \t\t\t %f  \t\t\t %f\n", index + 1, frac, m, (frac * (*(arr + i))));
		}
	}
	printf("\nTotal profit:%f\n",total_profit);
	printf("\nKnapsack vector:\n{  ");
	for (i = 0; i < n; i ++)
	{
		printf("%f  ",*(vector + i));
		if ( i != n-1)
			printf(",  ");
	}
	printf("}\n");
}

int main()
{
	int n,i,j;
	float profit,weight,m;
	printf("Enter number of items:");
	scanf("%d",&n);
	float *store = (float *)malloc( 4 * n * sizeof(float));
	for ( i = 0; i < n; i++)
	{
		printf("\nEnter profit value of item %d:",i + 1);
		scanf("%f",&profit);
		*(store + i) = profit;
		printf("\nEnter weight value of item %d:",i + 1);
		scanf("%f",&weight);
		*(store + n + i) = weight;
		*(store + 2*n + i) = profit / weight;
		*(store + 3*n + i) = 1.0 * (i);
	}
	printf("Enter total capacity of knapsack:");
	scanf("%f",&m);
	strategy(store,1,n,m);
	strategy(store,2,n,m);
	strategy(store,3,n,m);
}