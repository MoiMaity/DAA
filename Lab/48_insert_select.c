#include <math.h> 
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[],int n) 
{ 
    int i,key,j; 
    for (i=1;i<n;i++)
	 { 
        key=arr[i]; 
        j=i-1;
        while (j>=0&&arr[j]>key)
		{ 
            arr[j+1]=arr[j]; 
            j=j-1; 
        } 
        arr[j+1]=key; 
    } 
} 

void swap(int *xp,int *yp) 
{ 
    int temp=*xp; 
    *xp=*yp; 
    *yp=temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i,j,min_idx; 
    for(i=0;i<n-1;i++) 
    { 
        min_idx=i; 
        for(j=i+1;j<n;j++)
		{
        	if(arr[j]<arr[min_idx]) 
        		min_idx=j; 
    	}
        swap(&arr[min_idx],&arr[i]); 
    } 
} 

void printArray(int arr[],int n) 
{ 
    int i; 
    for(i=0;i<n;i++) 
        printf("%d ",arr[i]); 
    printf("\n"); 
} 

void main() 
{ 
    int arr[20],n,i,ch,choice;
    printf("Enter value of n :");
	scanf("%d",&n); 
	printf("Enter array elements :");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	while (ch!=3)
	{
		printf("\n");
		printf("1. Press 1 to sort using INSERTION SORT.\n2. Press 2 to sort using SELECTION SORT.\n3.EXIT\n\n");
		printf("Enter your Choice :");
		scanf("%d",&choice);
		printf("----------------------------------\n");
		switch(choice)
		{
			case 1: insertionSort(arr,n);
					printf("Sorted array: \n");  
    				printArray(arr,n); 
    				break;
			case 2: selectionSort(arr, n); 
    				printf("Sorted array: \n"); 
    				printArray(arr, n); 
    				break;
    		case 3: printf("-----THANK YOU-----\n");
					exit(0);
		}
		printf("\n");
	}
	getch(); 
}
