# include<stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int nums[n];
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&nums[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
       printf("%d ",nums[i]);
    }
    
    

    return 0;
}