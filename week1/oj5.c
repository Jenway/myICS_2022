#include<stdio.h>

    typedef struct goodTh
{
    int weight;
    int order;
    int value;
    double density;
}good;

int main(void){
    int maxWeight,num,sumWeight,sumValue;
    
    // maxWeight = 150;
    // num = 7;
    int sign=0;
    scanf("%d%d",&maxWeight,&num);

    int tagList1[num];
    int tagList2[num];
    good Ogoods[num];
    good goods[num];

    /////////////////
    // Ogoods[0].weight=10;
    // Ogoods[1].weight=40;
    // Ogoods[2].weight=30;
    // Ogoods[3].weight=50;
    // Ogoods[4].weight=35;
    // Ogoods[5].weight=40;
    // Ogoods[6].weight=30;
    // Ogoods[0].value=35;
    // Ogoods[1].value=30;
    // Ogoods[2].value=6;
    // Ogoods[3].value=50;
    // Ogoods[4].value=40;
    // Ogoods[5].value=10;
    // Ogoods[6].value=25;

    /////////////////
        for (int i = 0; i < num; i++)
    {
        scanf("%d",&Ogoods[i].weight);
        Ogoods[i].order = i+1;
    }
        for (int i = 0; i < num; i++)
    {
        scanf("%d",&Ogoods[i].value);
    }
        for (int i = 0; i < num; i++)
    {
        Ogoods[i].density = ((double)Ogoods[i].value / (double)Ogoods[i].weight);
    }
    float temp =0;
    int tempsign = 0;
    while (sign<num)
    {
        temp = 0.0;
        for (int i = 0; i < num; i++)
        {
            if (temp < Ogoods[i].density)
            {
                temp = Ogoods[i].density;
                tempsign =i;
            }               
        }
        goods[sign].weight= Ogoods[tempsign].weight;
        goods[sign].value= Ogoods[tempsign].value;
        goods[sign].order = Ogoods[tempsign].order;

        Ogoods[tempsign].density = 0;
        sign++;       
    }
    sumValue = 0;
    sumWeight = 0;
    for (int i = 0; i < num; i++)
    {
        if ((sumWeight + goods[i].weight) > maxWeight)
        {
            continue;
        }
        
        sumWeight += goods[i].weight;
        sumValue += goods[i].value;
        tagList1[i] = goods[i].order;
    }
    
        for (int i = 0; i < num && tagList1[i]< num && tagList1[i]>0; i++)
    {
        printf("%d ",tagList1[i]);
    }
    printf("%d ",sumWeight);
    printf("%d\n",sumValue);



}