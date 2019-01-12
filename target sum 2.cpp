#include<stdio.h> 

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 

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

int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2;  
		if (arr[mid] == x) 
			return mid; 

		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		return binarySearch(arr, mid + 1, r, x); 
	} 

	return -1; 
} 


int main() 
{ 
	int n,sum ;
	printf("Enter number of elements you want to enter in array(no duplicate allowed)\n");
	scanf("%d",&n);
	int arr[n] ;
	printf("enter your array\n");
	for (int i = 0 ;i < n ; i += 1)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the sum you want to get \n");
	scanf("%d",&sum); //ex 2 
	quickSort(arr, 0, n-1); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	for(int i = 0 ; i < n ; i++)
	{
		int result = -1;
		if((2 - arr[i] ) != 1)
			result = binarySearch(arr , 0, n - 1, sum - arr[i]);
		if (result != -1)
			printf("[%d , %d]\t", arr[i], arr[result]);
		
	}
	return 0; 
} 


