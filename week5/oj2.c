#include<stdio.h>
#include<math.h>

typedef struct good
{
    int No;      ///物品编号
    float weight;  //物品重量
    float value;   //物品价值
    float pw;    //物品单位重量的价值； pw=value/weight;
}good;

void greedy(good goods[], int n);

int money(int *num,int left,int right);
int max(int *num,int temp,int n);
int bioSea(int *num,int tag,int left,int right);

int main(void){

    int capacity,amount;
    scanf("%d %d",&amount,&capacity);
    good goods[amount];
    for (int i = 0; i < amount; i++)
    {
        goods[i].No = i;
        scanf("%f",&goods[i].weight);
        scanf("%f",&goods[i].value);
        goods[i].pw = goods[i].value / goods[i].weight;
    }
    greedy(goods,amount);
    float tempValue =0,tempWeight =0;
    int ans =0;
    for (ans = 0; ans < amount; ans++)
    {
        if ( tempWeight + goods[ans].weight > capacity)
        {
            break;
        }
        
        tempValue += goods[ans].value;
        tempWeight += goods[ans].weight;
    }
    printf("%lg\n%lg",tempWeight,tempValue);
    return 0;
}

void greedy(good goods[],int n){

    good temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (goods[j].pw < goods[j+1].pw)
            {
                temp = goods[j+1];
                goods[j+1] =goods[j];
                goods[j] = temp;
            }
            
        }
        
    }
    
}

int money(int *num,int left,int right){
    int temp1 =0,temp2=0;
    int key = (left+right)/2;
    if (left == right -1)
    {
        return (num[left]<num[right])?left:right;
    }
    
    for (int i = 0; i <= key-left; i++)
    {
        temp1 +=num[left+i];
        temp2 += num[right-i];
    }
    if(temp1 == temp2){
        return key;
    }
    if (temp1>temp2)
    {
            return money(num,key,right);             
    }
    else if (temp1<temp2)
    {      
        return money(num,left,key);
    }

    
    

}

int max(int *num,int temp,int n){
    if (n== -1)
    {
        return temp;
    }
    else
    {
        temp = (temp>num[n])?temp:num[n];
        return max(num,temp,n-1);
    }
    
    
}

int bioSea(int *num,int tag,int left,int right){
    int key =(left +right)/2;
    if (left>=right)
    {
        if(num[key]== tag){
            return key;
        }
        else
        {
            return -1;
        }
        
        
    }
    if (num[key]>tag)
    {
        return bioSea(num,tag,left,key-1);
    }
    else
    {
        return bioSea(num,tag,key+1,right);
    }
}