#include<stdio.h>

int rand(int n,int m,int a,int b,int seed);
int main()
{
    int a,b,m,n,seed;//分别为需产生随机数个数 N，随机数种子 seed，递推公式中 a,b,M;
    scanf("%d%d%d%d%d",&n,&seed,&a,&b,&m);
    int x[n];
    // X(n+1) = (a*X(n)+b) % M
    for (int i = 0; i < n; i++)
    {
        x[i] = rand(i+1,m,a,b,seed);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",x[i]);
    }
    



    return 0;
}

int rand(int n,int m,int a,int b,int seed){
    if (n == 0)
    {
        return seed;
    }
    
    return (a * rand(n-1,m,a,b,seed) + b) % m;
}