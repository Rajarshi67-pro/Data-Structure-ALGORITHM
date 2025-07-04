#include<stdio.h>
int main() {
    int nums[] = {2,6,0,9,7,3,1,4,1,10};
    int n = sizeof(nums)/sizeof(nums[0]);
    int target = 15 ;
    int start = 0, end = 0,sum = 0 ;
    int found = 0 ;

    while(end <=n){
        if(sum == target){
            printf("Subarray with given sum:");
            for(int i=start; i<end;i++){
                printf("%d",nums[i]);
            }
            printf("\n");
            found = 1;
            break ;
        }
        else if(sum<target){
            sum+=nums[end];
            end++;
        }
        else {
            sum-= nums[start];
            start++;
        }
    }
    if(!found){
        printf("No subarray with the given sum found.\n");
    }
    return 0 ;
}