#include<stdio.h>
int linearSearch(int arr[]);
int binarySearch(int arr[]);
int main()
{
int i;
int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int res;
res = linearSearch(arr);
printf("No of comparisons in linear Search =  %d\n\n",res);

int result;
result = binarySearch(arr);
printf("No of comparisons in binary Search = %d\n",result);
return 0;
}
int linearSearch(int arr[]){
int i,count = 0;
int target = 12;
for(i=0;i<15;i++){
	if(arr[i] == target)
	{
		printf("The element 12 is found using linear Search\n");
		printf("The element %d is found at index %d\n",arr[i],i);
		return count + 1;
	}
	count++;
}
return count;
}
int binarySearch(int arr[]) {
int start = 0;
int end =  14;
int target = 12;
int count = 0;
while(start <= end){
int mid = (start+end)/2;
if(target < arr[mid]){
	end = mid -1;
}
else if(target > arr[mid]){
start = mid + 1;
}
else{
	printf("The element 12 is found using binary Search\n");
	printf("The element %d is found at index %d\n",arr[mid],mid);
	return count + 1;
}
count++;
}
return count;
}
