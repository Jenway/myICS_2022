#include<stdio.h>
#include<stdlib.h>

int main(void){
    int seed,n,m;
    m = 0;
    scanf("%d%d",&seed,&n);
    double setx[n];
    double sety[n];
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        setx[i]=1.0+((double) rand() / RAND_MAX );
        sety[i]=(double) rand() / RAND_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        if ((1.0/setx[i])>sety[i])
    {
        m+=1;
    }
    }
    
    printf("%lf",(double)m/(double)n);
    
    return 0;
}


