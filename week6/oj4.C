# include<stdio.h>

int main(void){

    long long int n;
    scanf("%lld",&n);
    if (n==0)
    {
        printf("No");
    }
    else
    {
        if (  (n & (n - 1)) == 0)
        {
            printf("Yes");
        }
        else{
            printf("No");
        }
    }
    

    
    return 0;
}