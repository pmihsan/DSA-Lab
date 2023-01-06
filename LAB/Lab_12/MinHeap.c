#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int *n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < *n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < *n && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        heapify(arr, (int *)n, smallest);
    }
}

void buildHeap(int arr[], int n)
{
	int startIndex = (n / 2) - 1;
	for (int i = startIndex; i >= 0; i--) {
		heapify(arr, &n, i);
	}
}

void deleteRoot(int arr[], int *n)
{
    int lastElement = arr[*n - 1];
    printf("Deleting Element %d\n",arr[0]);
    arr[0] = lastElement;
    *n = *n - 1;
    heapify(arr, (int *)n, 0);
}

void printHeap(int arr[], int n)
{
	printf("Array representation of Heap is:\n");
	for (int i = 0; i < n; ++i){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
	int arr[] = {15 , 17 , 9 , 11 , 5 , 19 , 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Inserting the elements into the heap\n");
	buildHeap(arr, n);
	printHeap(arr, n);
	printf("\n");
    int k = n;
    for(int i=0;i<k;i++){
    deleteRoot(arr,&n);
    printHeap(arr, n);
    }
	return 0;
}

