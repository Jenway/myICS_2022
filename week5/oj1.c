#include<stdio.h>

int fabo(int n);
int main(void){

    int n;
    scanf("%d",&n);
    printf("%d",fabo(n));
}

int fabo(int n){

    if(n==1){
        return 0;
    }
    else if (n ==2)
    {
        return 1;
    }
    else if(n>2)
    {
        return (fabo(n-1)+fabo(n-2));
    }
    else
    {
        return 0;
    }
    
    
}