#include<stdio.h>

int main() {
    int nums[]={5,6,8,2,4,6,9};
    int k = 4;
    int n = sizeof(nums)/sizeof(nums[0]);
    int found = 0 ;

    for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
        if(nums[i]== nums[j]&&(j-1)<=k){
            printf("Duplicate elements found: Elements %d repeats at distance %d which is  <=%d\n",nums[i],j-i,k);
            found = 1;
            break ;
        }
     }
        if(found)
        break;
    }

     if(!found){
        printf("No duplication found within distance %d\n",k);
     }   

    return 0;
    
}