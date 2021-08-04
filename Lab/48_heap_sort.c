#include <stdio.h>
#include<conio.h>

void swap(int *a, int *b) 
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
  
void heap(int arr[],int n,int i) 
{
	int parent=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[left]>arr[parent])
    	parent=left; 
    if(right< n && arr[right]>arr[parent])
    	parent=right;
    if(parent!=i)
	{
    	swap(&arr[i],&arr[parent]);
    	heap(arr,n,parent);
    }
}
  
void heapSort(int arr[],int n) 
{
	int i;
    for(i=n/2-1;i>=0;i--)
    	heap(arr,n,i);
	for(i=n-1;i>=0;i--) 
	{
    	swap(&arr[0],&arr[i]);
    	heap(arr,i,0);
    }
}

void printArray(int arr[],int n)
{
	int i;
    for(i=0;i<n;++i)
    	printf("%d ",arr[i]);
    printf("\n");
}

void main() 
{
    int arr[50],n,i;
    printf("Enter number of elements :");
    scanf("%d",&n);
	printf("Enter array elements :");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);    
  	heapSort(arr,n);
  	printf("Sorted array is :");
    printArray(arr,n);
    getch();
}
