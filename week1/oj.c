#include <stdio.h>
// #include <math.h>

int main(void){

    int a[3][3];
    int b[3][3];

    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++)
        {
            scanf("%d",&a[y][x]);
        }
    }
    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++)
        {
            scanf("%d",&b[y][x]);
        }
    }

    
    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++)
        {
            printf("%d\t",a[y][x] + b[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++)
        {
            printf("%d\t",a[y][x] - b[y][x]);
        }
        printf("\n");
    }

    printf("\n");
    int sum;   
    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++)
        {
            sum = 0;
            for(int i=0; i<3; i++){
                sum += a[y][i]*b[i][x];               
            }
            printf("%d\t",sum);
        }
        printf("\n");
    }
    printf("\n");
    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++)
        {
            printf("%d\t",a[x][y]);
        }
        printf("\n");
    }
    
    // printf("\n");

    return 0;
}