#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int left,int mid,int right){

	int n1=mid-left+1;
    	int n2=right-mid;
    	int L[n1],R[n2];
    	for(int i=0;i<n1;i++)
        	L[i]=arr[left+i];
    	for(int j=0;j<n2;j++)
        	R[j]=arr[mid+1+j];
    	int i=0,j=0,k=left;
    	while (i<n1&&j<n2) 
    	{
        	if(L[i]<=R[j]) 
        	{
            		arr[k]=L[i];
            		i++;
        	} 
        	else 
       		{
            		arr[k]=R[j];
            		j++;
        	}
        	k++;
    	}
    	while (i<n1) 
    	{
        	arr[k]=L[i];
        	i++;
        	k++;
    	}
    	while (j<n2) 
    	{
        	arr[k]=R[j];
        	j++;
        	k++;
    	
	}
}
void mergeSort(int *arr,int left,int right){
    	if(left<right) 
   	{
        	int mid=left+(right-left)/2;
        	mergeSort(arr,left,mid);
        	mergeSort(arr,mid+1,right);
        	merge(arr,left,mid,right);
    	}
}

void displayArray(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	if(n==1)
	{
		printf("Only 1 element. Original and sorted array will remain the same.");
		return 0;
	}
	else if(n==0)
	{
		printf("No elements to sort.\n");
		return 0;
	}
	int *arr;
	arr=(int *)malloc(n* sizeof(int));
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Original array: ");
	displayArray(arr,n);
	mergeSort(arr,0,n-1);
	printf("Sorted array: ");
	displayArray(arr,n);
	free(arr);
	return 0;
}
