/* C implementation QuickSort */
#include<stdio.h> 
#include<conio.h>

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int i,j,pivot;
	pivot = arr[high]; // pivot 
	i = (low - 1); // Index of smaller element 
	for (j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	int pi;
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		pi = partition(arr, low, high); 
		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

void main() 
{ 
	int i,r,arr[20];
	printf("Enter the range:\n");
	scanf("%d",&r);
	printf("Enter the elements:\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&arr[i]);
	}
	quickSort(arr, 0, r-1); 
	printf("Sorted array is: \n"); 
	printArray(arr, r); 
	getch(); 
}