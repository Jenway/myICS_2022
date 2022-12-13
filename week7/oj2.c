#include<stdio.h>
#include <stdlib.h>

void judge(int n);
int main(void){

    int m; //第一行一个数 M，代表数据的组数。
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int n;
        scanf("%d",&n);
        judge(n);
    }
    return 0;
}

void judge(int n ){
    int num[n];
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(num[i]>num[(i+1)%n])
        flag++;
    }
    const char *str= (flag<2)?"Yes\n":"No\n";
    printf("%s",str);
}