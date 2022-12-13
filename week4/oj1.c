#include<stdio.h>

int main(void){
    int m,n; //共有m组，每组n个数。
    scanf("%d%d",&m,&n);
    int nums[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&nums[i][j]);
        }
        
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (nums[i][j] > nums[i][j+1])
            {
                nums[i][j+1] = nums[i][j];
            }
            else if (nums[i][j] == nums[i][j+1])
            {
                nums[i][j+1] = 0;
            }
            else
            {
                continue;
            }
            
        }
        
    }
    
    for (int i = 0; i < m-1; i++)
    {
        if (nums[i][n-1]>nums[i+1][n-1])
        {
            nums[i+1][n-1] = nums[i][n-1];
        }
        else if (nums[i][n-1] == nums[i+1][n-1])
        {
            nums[i+1][n-1] = 0;
        }
        else
        {
            continue;
        }
        
    }
    

    if (nums[m-1][n-1] != 0)
    {
        printf("%d",nums[m-1][n-1]);
    }
    else{

        printf("%d",-1);
    }



    return 0 ;
}

//1 个整数，如果有胜利的数则输出该数，如果没有胜利的数，则输出 -1。
