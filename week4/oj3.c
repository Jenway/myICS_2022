#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>


#define MAX 10000

char *double_to_string(double d, int decimal);

int main(void){

    int n;          scanf("%d",&n);
    char num1[n];   scanf("%s",num1);
    int m;          scanf("%d",&m); 
    char num2[m];   scanf("%s",num2);

    int HMfloat1 = -1,HMfloat2 =-1; //where is the '.'?
    for (int i = 0; i < n; i++)
    {
        if (num1[i]=='.')
        {
            HMfloat1 = i;
            break;;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        if (num2[i]=='.')
        {
            HMfloat2 = i;
            break;;
        }
    }

    int status; // status =
    if (HMfloat1 == -1 && HMfloat2 == -1)
    {
        status=-1;
    }else
    {
        status=1;
    }
    
    char num1_int[MAX];
    char num2_int[MAX];
    char num1_float[MAX];
    char num2_float[MAX];
    for (int i = 0; i < MAX; i++)
    {
        num1_int[i] ='0';
        num2_int[i] ='0';
        num1_float[i] ='0';
        num2_float[i] ='0';

    }
    

    for (int i = 0,count=0,flag=1; i < n; i++)
    {
        if (i == HMfloat1)
        {
            flag*=-1;
            continue;
        }else{}
        if (flag>0)
        {
            num1_int[i]= num1[i];
        }
        else
        {
            num1_float[count]= num1[i];
            count++;
        }  
    }

    for (int i = 0,count =0,flag=1; i < m; i++)
    {
        
        if (i == HMfloat2)
        {
            flag*=-1;
            continue;
        }else{}
        if (flag>0)
        {
            num2_int[i]= num2[i];
        }
        else
        {
            num2_float[count]= num2[i];
            count ++;
        }  
    }
    
    int amount1 = n - HMfloat1;
    int amount2 = m - HMfloat2;
    int amountF = (amount1>amount2)?amount1:amount2;
    int locaF =(n-HMfloat1>m-HMfloat2)?n-HMfloat1:m-HMfloat2;
    int amountFloat =amountF;
    char ans_float[amountF-1];

    double num1_double=0,num2_double=0;
    for (int i = n - HMfloat1-2,count=0; i >=0; i--)
    {
        num1_double += (double)(pow(10,count)*(double)(num1_int[i]-'0'));
        count++;
    }
        for (int i = m - HMfloat2 -1,count=0; i >=0; i--)
    {
        num1_double += (double)(pow(10,count)*(double)(num2_int[i]-'0'));
        count++;
    }
        for (int i = 0,count=-1; i < n - HMfloat1; i++)
    {
        num1_double += (double)(pow(10,count)*(double)(num1_float[i]-'0'));
        count--;
    }
            for (int i = 0,count=-1; i < m - HMfloat2; i++)
    {
        num1_double += (double)(pow(10,count)*(double)(num2_float[i]-'0'));
        count--;
    }
    // printf("%.0lf",num1_double);
    // if (status == -1)
    // {
        amount1 = HMfloat1;
        amount2 = HMfloat2;
        amountF = (amount1>amount2)?amount1:amount2;
        char * lucy;
        lucy  = double_to_string(num1_double,6);
        // printf("%s",lucy);
        int daxx = strlen(lucy);
    // }
    for (int i = daxx-1; i >=0; i--)
    {
        if (lucy[i]=='0')
        {
            daxx -=1;
        }
        else if (lucy[i]=='.')
        {
            break;
        }
        else if (lucy[i]!='0')
        {
            break;
        }
        
    }
    for (int i = 0; i < daxx; i++)
    {
        printf("%c",lucy[i]);
    }
    

    
    // long long int ians_int =  (int)num1_double;
    // long long int ians_float = floor(num1_double*100000)/100000;
    // printf("%ld.%ld",ians_int,ians_float);



    return 0;
}

char *double_to_string(double d, int decimal)
{
 
        decimal = decimal < 0 ? 0 : decimal;
        char *p;
        char dd[26];
        switch (decimal) {
        case 0:
                sprintf(dd, "%.0lf", d);
                break;
        case 1:
                sprintf(dd, "%.1lf", d);
                break;
        case 2:
                sprintf(dd, "%.2lf", d);
                break;
        case 3:
                sprintf(dd, "%.3lf", d);
                break;
        case 4:
                sprintf(dd, "%.4lf", d);
                break;
        case 5:
                sprintf(dd, "%.5lf", d);
                break;
        default:
                sprintf(dd, "%.6lf", d);
                break;
 
        }
        p = malloc(strlen(dd));
        strcpy(p,dd);
        return p;
}