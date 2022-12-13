#include<stdio.h>

int main(void){
    int a[5] = {};
    // int a[5][5]={};
    int *ptr1;
    int **ptr2;
    ptr1 = a[0];
    ptr2 = &ptr1[0];
    for (int i = 0; i < 5; i++)
    {
        // for (int j = 0; j < 5; j++)
        // {
        //     // a[i][j] = i*j;
        // }
        a[i]=i;
    }
    
    printf("%d",a[2]);

}