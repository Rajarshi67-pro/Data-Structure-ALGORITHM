#include<stdio.h>

int main(){
	int n,i,j,temp;
  	int arr[100];
  	printf("Enter the number of elements want to sort:");
  	scanf("%d",&n);
  	for(i=0;i<n;i++){
  		printf("Enter integer number - '%d' :",i+1);
    		scanf("%d",&arr[i]);
 	 }
 	 for(i=1;i<n;i++){
    		j=i;
    		while(j>0 && arr[j-1] > arr[j]){
      			temp=arr[j];
      			arr[j]=arr[j-1];
      			arr[j-1]=temp;
      			j--;
    		}
  	}
  	printf("Shorted list in assending order using insertion sort : ");
  	for(i=0;i<n;i++){
    		printf("%d ",arr[i]);
  	}
  	printf("\n");
return 0;
}
