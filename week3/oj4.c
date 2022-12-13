#include <stdio.h>
#include<math.h>
#define MAX 1000
#define FALSE 1
#define TRUE 0

void toWei(double numTail,int num,int tWei);

int main(void){
	
	int oWei;
	int tWei;
	char oNum[10] = {0};
	int temp=0;
	double tempFloat =0.0;
	char tNUm[10];
	int place;// 位数
	int flag;// . 位置
	int ifFloat = FALSE;
	scanf("%d%d%s",&oWei,&tWei,oNum);

	for (int j = 0;oNum[j] != 0; j++)
	{
		if (oNum[j] == '.')
		{
			flag = j;
			ifFloat = TRUE;
		}
		place=j;
	}
	
	// 小数部分
	if (ifFloat == TRUE)
	{
		for (int i = flag+1;i<=place; i++)
		{
			if (oNum[i] >= 'a')
				tempFloat+= pow(oWei,flag-i)*(oNum[i]-'a'+10);
			else
				tempFloat+= pow(oWei,flag-i)*(oNum[i]-'0');
		}
	}
	else
		flag = place+1;

	// 整数部分
	for (int i = flag-1;i>=0; i--)
	{	
		if (oNum[i] > '9')
			temp+= pow(oWei,flag-i-1)*(oNum[i]-'a'+10);
		else
			temp+= pow(oWei,flag-i-1)*(oNum[i]-'0');
	}
	
		toWei(tempFloat,temp,tWei);
	return 0;
}

void toWei(double numTail,int num,int tWei){
	char ans[MAX];
	int flag;		
	if (num ==0)
		{
			printf("0");
		}
	else
		{
			for (int i =0; num >0;i++)
			{
				if (num %tWei>=10)
					ans[i] = num %tWei +'a' -10;

				
				else
					ans[i] = (num % tWei)+'0';
					flag = i;
					num/=tWei;
			}

			for (int j = flag; j>=0; j--)
			{
				printf("%c",ans[j]);
			}		/* code */
		}

	if (numTail == 0)
	{
		return;
	}
	printf(".");

	for (int i = 0; i < 8; i++)
	{
		numTail *= tWei;
		if (numTail < 1&&numTail>0)
		{
			printf("0");
		}
		else
		{					
			if (numTail == 0 || numTail<pow(tWei,-8+i))
			{
				return;
			}
			else if ((int)numTail>=10)
			{
				printf("%c",(int)numTail-10+'a');
			}
			else
			{
				printf("%d",(int)numTail);
			}		
			numTail -= (int)numTail;
		}
	}
}