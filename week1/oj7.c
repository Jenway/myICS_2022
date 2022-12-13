#include<stdio.h>

#define MAX 100

typedef struct goods{
int sign;
int weight;
int value;
}good;

int bestValue = 0;
int sumWeight = 0;
int curValue = 0;
int curWeight = 0;
int n = 7; 
int capacity = 150;   
int X[MAX],cx[MAX];
good goods[MAX];

int Force(int i);

int main()
{
    goods[0].weight=10;
    goods[1].weight=40;
    goods[2].weight=30;
    goods[3].weight=50;
    goods[4].weight=35;
    goods[5].weight=40;
    goods[6].weight=30;
    goods[0].value=35;
    goods[1].value=30;
    goods[2].value=6;
    goods[3].value=50;
    goods[4].value=40;
    goods[5].value=10;
    goods[6].value=25;


    int list[n];
    for (int i = 0; i < n; i++)
    {
        list[i] = i;
    }
    
    int sumValue = Force(0);
    sumWeight=0;
    for (int i = 0; i < n; i++)
    {
        if (X[i]==1)
        {
            sumWeight += goods[list[i]].weight;
        }
        
    }
    
    for(int i=0;i<n;i++){
        if (X[i]==1)
        {
            printf("%d ",list[i]+1);
        }
        }
        printf("%d ",sumWeight);
        printf("%d\n",sumValue);
    return 0;
}

int Force(int i){
    if(i+1>n){
        if(bestValue < curValue && curWeight + goods[i].weight <= capacity){
            for(int k=0;k<n;k++)
                X[k] = cx[k];
            bestValue = curValue;
        }
        return bestValue;
    }

    curWeight += goods[i].weight;
    curValue += goods[i].value;
    cx[i] = 1;//装入背包

    Force(i+1);

    curWeight -= goods[i].weight;
    curValue -= goods[i].value;
    cx[i] = 0;//不装入背包
    
    Force(i+1);
    return bestValue;
}

// 矩阵 是否存在 x列最大，y行最小的point