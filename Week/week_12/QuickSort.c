#include<stdio.h>
int n;
void printArray(int arr[]){
    printf("The Array elements are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void quickSort(int arr[] ,int low ,int high){
    if(low >= high){
        return;
    }
    int s = low;
    int e = high;
    int m = s + (e - s) / 2;
    int pivot = arr[m];
     //arr = {23, 45, 67, 12, 90}
        while (s <= e) {
            //Check the array if it is already sorted
            while (arr[s] < pivot) {
                s++;
            }
            while (arr[e] > pivot) {
                e--;
            }
            //If not sorted swap element smaller than pivot to left half and greater than pivot to right half
            if (s <= e) {
                int temp = arr[s];
                arr[s] = arr[e];
                arr[e] = temp;
                s++;
                e--;
            }
        }
        // now my pivot is at correct index, sort two halves now
        quickSort(arr, low, e);
        quickSort(arr, s, high);
}

int main(){
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    
    int arr[n];
    int start = 0;
    
    printf("Enter the arrays elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printArray(arr);
    
    printf("Quick Sort Algorithm\n");
    quickSort(arr,start,n);
    
    printArray(arr);
    return 0;
}
