#include<stdio.h>
#include<math.h>

int main(void){

    int num;
    int adds;
    scanf("%d",&num);
    // num = 10;
    int nums[num];
    // int nums[10] = {9,8,2,5,9,8,7,7,1,2};
    scanf("%d",&adds);
    // adds =7;
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&nums[i]);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = (i+1); j < num; j++)
        {
            if (nums[i] + nums[j] == adds)
            {
                printf("%d %d",i,j);
                return 0;
            }
            
        }
        
    }
    
    
    


}