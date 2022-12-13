#include<stdio.h>
#include<math.h>
int main(void){
    long long int a;
    int i;
    // scanf("%lld",&a);
    // if (a<=1 || a >=1000)
    // {
    //     return 1;
    // }
    char num[1001]={0};
    scanf("%s",num);
    
    int flag=0;
    for (i = 0; num[i]!=0; i++)
    {
        /* code */
    }
    

    // for (i = 0; a != 0; i++)
    // {
    //     if (a < 10)
    //     {
    //         num[i] = (a%10);
    //     }
    //     else
    //     {
    //     num[i] = (a%10);
    //     }
    //     a /= 10;
    // }
    for (int j = 0; j < (i/2); j++)
    {
        if (num[j] == num[i-j-1])
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
        
        
    }
    
    if (flag == 0)
    {
    printf("Yes");
        }
    else{
        printf("No");
    }
    


    return 0;
}