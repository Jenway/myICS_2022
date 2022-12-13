#include<stdio.h>
#define MAX(a,b) ( (a) > (b) ?(a) : (b) )

int main(void){
    int n;scanf("%d",&n);
    int nums[n];
    int dp,ans =0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&nums[i]);
    }
    dp=nums[0];
    for (int i = 1; i < n; i++)
    {
       dp=MAX(nums[i],nums[i]+dp);
       ans=MAX(dp,ans);
    }
    printf("%d",ans);

}

