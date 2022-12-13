#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct goodTh
{
    int weight;
    int value;
}good;

int main(void){
    int maxWeight,num,weightSum,valueSum,weightFinal,valueFinal,item_tagP,item_tag;
    weightSum = 0;
    valueSum = 0;
    item_tagP=0;

    //  ////////////////////////
    maxWeight = 150;
    num = 7;
    
    // scanf("%d%d",&maxWeight,&num);
    good Ogoods[num];
    int itemlist[num];
    int *listFinal;

    Ogoods[0].weight=10;
    Ogoods[1].weight=40;
    Ogoods[2].weight=30;
    Ogoods[3].weight=50;
    Ogoods[4].weight=35;
    Ogoods[5].weight=40;
    Ogoods[6].weight=30;
    Ogoods[0].value=10;
    Ogoods[1].value=40;
    Ogoods[2].value=30;
    Ogoods[3].value=50;
    Ogoods[4].value=35;
    Ogoods[5].value=40;
    Ogoods[6].value=30;
    // for (int i = 0; i < num; i++)
    // {
    //     scanf("%d",&Ogoods[i].weight);
    // }
    // for (int i = 0; i < num; i++)
    // {
    //     scanf("%d",&Ogoods[i].value);
    // }

    for (item_tagP = 0;item_tagP< num;item_tagP++)
    {
        
        for (int item_num = 1; item_tagP+item_num <= num; item_num++)
        {
            // place items of item_num
            weightSum = 0;
            valueSum = 0;
            item_tag = item_tagP;
            for (int loopNum = 0; loopNum < item_num && item_tag<num; loopNum++,item_tag++)
            {      
                // begin with item_tag
                    weightSum += Ogoods[item_tag].weight;
                    if (weightSum>maxWeight)
                    {
                        weightSum = 0;
                        valueSum = 0;
                        item_tag = item_tagP;
                        break;
                    }
                    itemlist[loopNum]=item_tag+1;                    
                    valueSum += Ogoods[item_tag].value;
            }
            valueFinal = (valueFinal > valueSum) ? valueFinal : valueSum;
            weightFinal = (valueFinal > valueSum) ? weightFinal : weightSum;
            listFinal = (valueFinal > valueSum) ? listFinal : itemlist;
        }
    }

    for (int i = 0; i < num && listFinal[i]< num && listFinal[i]>0; i++)
    {
        printf("%d ",listFinal[i]);
    }
    printf("%d ",weightFinal);
    printf("%d\n",valueFinal);


    
    
}