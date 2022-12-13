#include <stdio.h>
#include <math.h>

typedef struct goods{
int sign;
int weight;
int value;
}good;

int main() 
{
    int capacity,item_num;
    scanf("%d%d",&capacity,&item_num);
    // int capacity = 150;
    // int item_num = 7;
    good goods[item_num];
    // goods[0].weight=10;
    // goods[1].weight=40;
    // goods[2].weight=30;
    // goods[3].weight=50;
    // goods[4].weight=35;
    // goods[5].weight=40;
    // goods[6].weight=30;
    // goods[0].value=35;
    // goods[1].value=30;
    // goods[2].value=6;
    // goods[3].value=50;
    // goods[4].value=40;
    // goods[5].value=10;
    // goods[6].value=25;
    for (int i = 0; i < item_num; i++)
    {
        scanf("%d",&goods[i].weight);
    }
        for (int i = 0; i < item_num; i++)
    {
        scanf("%d",&goods[i].value);
    }
    int wayList[(int)pow(2,item_num)-1][item_num];
    int *listFinal,*itemlist;
    int temp,sum,flag,sumWeight,sumValue,weightFinal,valueFinal;

    for (int i = 1; i < pow(2,item_num); i++)
    {
        temp = i;
        sum =0;
        flag=0;
        while (temp>0 && flag<=item_num)
        {
            // sum +=((temp % 2)*pow(10,flag));
            wayList[i-1][flag] = (temp % 2);
            temp /=2;
            flag++;
        }
        // wayList[i-1] = sum;
    }
    
    for (int i = 0; i < pow(2,item_num)-1; i++)
    {
        for (int j = 0; j < item_num; j++)
        {
            if (wayList[i][j]==0 || wayList[i][j]==1)
            {}
            else
            {
                wayList[i][j]=0;
            }                                
        }    
    }
    
    for (int i = 0; i < pow(2,item_num)-1; i++)
    {
        sumValue = 0,sumWeight = 0,itemlist =NULL;
        for (int j = 0; j < item_num; j++)
        {
            if (wayList[i][j]==1)
            {
                if (sumWeight + goods[j-1].weight>capacity)
                {
                    break;
                }
                
                sumWeight +=  goods[j-1].weight;
                sumValue += goods[j-1].value;
                itemlist = wayList[i];
            }
            else
            {}                                
        }   
        weightFinal =(valueFinal>sumValue)? weightFinal:sumWeight;
        valueFinal =(valueFinal>sumValue)? valueFinal:sumValue;
        listFinal =(valueFinal>sumValue)? listFinal:itemlist;
    }

    for (int i = 0; i < item_num-1; i++)
    {
        if (listFinal[i] == 1)
        {
            printf("%d ",i);
        }
        
    }
    

    printf("%d %d",weightFinal,valueFinal);


}