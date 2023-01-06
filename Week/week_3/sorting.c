#include<stdio.h>
void swap(int *p,int *q);
void main()
{
	int i,j,n;
	int arr[] = {3,7,8,5,2,1,9,5,4};
	printf("Your array is \n");
	for(i=0;i<9;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
  /*      for (i = 0; i < n-1; i++){               
		for (j = 0; j < n-i-1; j++){	     
	    		if (arr[j] > arr[j+1]){                       
			    	swap(&arr[j], &arr[j+1]);
			}
		}
	}
*/
        for (i = 0; i < n-1; i++){               
		for (j = 0; j < n-i-1; j++){	     
	    		if (arr[j] < arr[j+1]){                       
			    	swap(&arr[j], &arr[j+1]);
			}
		}
	}
	printf("Displaying the array after sorting using bubble sort\n");
	for(i=0;i<9;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void swap(int *p,int *q){
int temp = *p;
*p = *q;
*q = temp;
}
