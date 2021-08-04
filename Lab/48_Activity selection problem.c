#include<stdio.h>
#include<conio.h>

void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

int partition(int arr[], int low, int high, int s[], int act[]) 
{ 
	int i,j,p;
	p = arr[high]; 
	i = (low - 1);
	for(j = low; j <= high- 1; j++) 
	{ 	
		if(arr[j] < p) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]);
			swap(&s[i], &s[j]);
			swap(&act[i], &act[j]);			
		} 
	} 
	swap(&arr[i + 1], &arr[high]);
	swap(&s[i + 1], &s[high]);
	swap(&act[i + 1], &act[high]);	
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high, int s[], int act[]) 
{ 
	int pi;
	if (low < high) 
	{ 
		pi = partition(arr, low, high,s,act); 
		quickSort(arr, low, pi - 1,s,act); 
		quickSort(arr, pi + 1, high,s,act); 
	} 
} 

void main ()
{
	printf(".....Activity Selection Problem.....\n");
	int s[50], f[50], i, n, act[50];
	printf("Enter number of activity: ");
	scanf("%d", &n);
	printf("\n");
	for(i = 0; i < n; i++)
	{
    	printf("Enter the Starting Time of Activity A[%d]: ", i + 1);
    	scanf("%d", &s[i]);
    	printf("Enter the Finishing Time of Activity A[%d]: ", i + 1);
   		scanf("%d", &f[i]);
    	printf("\n");
    }
	for(i = 0; i < n; i++)
    {
    	act[i] = i + 1;
    }
	printf("\nUser Input : \n");
	for(i = 0; i < n; i++)
    {
    	printf("Activity: A%d  : Starting Time: %d : Finishing Time: %d\n", act[i], s[i], f[i]);
    }
	printf("\n");
	quickSort(f, 0, n-1, s, act);
	printf("\nSorting using Quick Sort : \n");
	for(i = 0; i < n; i++)
    {
    	printf("Activity: A%d  : Starting Time: %d : Finishing Time: %d\n", act[i], s[i], f[i]);
    }
	printf("\n");
	int fa[20], fs[20], ff[20], l = 0;
	fa[l] = act[0];
	fs[l] = s[0];
	ff[l] = f[0];
	int k = 0;
	for(i = 1; i < n; i++)
    {
    	if (f[k] <= s[i])
		{
			l = l + 1;
	  		fa[l] = act[i];
	  		fs[l] = s[i];
	  		ff[l] = f[i];
	  		k = i;
		}
    }
	printf("\nResult : \n");
	for(i = 0; i <= l; i++)
    {
    	printf("Activity: A%d  : Starting Time: %d : Finishing Time: %d\n", fa[i], fs[i], ff[i]);
    }
	getch();
}
