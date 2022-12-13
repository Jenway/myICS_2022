#include<stdio.h>
#include<math.h>

typedef struct goodTh
{
    int weight;
    int value;
}good;

int main(void){
    int maxWeight,maxValue,num,weightSum,valueSum;
    weightSum = 0;
    valueSum = 0;
    int tims =0;
    scanf("%d%d",&maxWeight,&num);
    good goods[num];

    int bags[(int)(pow(2,num)-1)][num];

    for (int i = 0; i < num; i++)
    {
        scanf("%d",&goods[i].weight);
    }
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&goods[i].value);
    }


    int item_tag=0;
    while (item_tag <= num)
    {
        // possibility of tims
        for (int item_num = 1; item_num < num; item_num++)
        {
            // place items of item_num
            for (; item_tag < num; item_tag++)
            {
                // the j-st item_tag
                for (int k = 0; k < item_num; k++)
                {
                    // the k-st place
                    bags[tims][k] = item_tag;
                    tims++;
                }
                
            }
            
        }
        item_tag++;
    }
    
    for (int i = 0; i <= (pow(2,num)-1); i++)
    {   
        for (int j = 0;bags[i][j] != 0;j++)
        {
            weightSum += goods[bags[i][j]].weight;
            if (weightSum >= maxWeight)
            {
                break;
            }
            printf("?????????????????\n");        
            valueSum += goods[*bags[i]].value;
            maxValue = (maxValue > valueSum) ? maxValue : valueSum;    
    }
    }
    printf("%d\n",maxValue);
    printf("%d\n",weightSum);
    

}

