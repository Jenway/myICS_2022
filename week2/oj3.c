#include<stdio.h>
#include<math.h>



int main(void){
    int i,a;//第一行为正整数i和电动车能通过的坡高度a，
    scanf("%d %d",&i,&a);
    int num[i];    //第二行为代表斜坡的i个正整数。
    for (int j = 0; j <i ;j++)
    {
        scanf("%d",&num[j]);   
    }
    
    int flag=0;
    for (int j = 0; j <i-1 ;j++)
    {
        if (abs(num[j+1]-num[j])>a)
        {
            flag =1;
            break;
        }
        
    }
    if (flag==0)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    

    return 0;
}