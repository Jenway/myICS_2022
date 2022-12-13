#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 10000
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

    int tempFloat =0;
    int tempInt = 0;
    if (status>0)
    {
        for (int i = amountF-2,count=0; i >= 0; i--)
            {
                ans_float[i] = (num1_float[locaF-count-2] + num2_float[locaF-count-2]-'0'-'0' + tempFloat)%10+'0';
                tempFloat = (num1_float[locaF-count-2] + num2_float[locaF-count-2]-'0'-'0' + tempFloat)/10;
                count++;
            }
    }else{}
    tempInt = tempFloat;

    amount1 = HMfloat1;
    amount2 = HMfloat2;
    amountF = (amount1>amount2)?amount1:amount2;
    char ans_int[amountF];

    for (int i = amountF-1,count = 0; i >=0; i--)
    {
        ans_int[i] =(num1_int[HMfloat1-1-count] +num2_int[HMfloat2-1-count]-'0'-'0'+tempInt)%10+'0';
        tempInt = (num1_int[HMfloat1-1-count] +num2_int[HMfloat2-1-count]-'0'-'0'+tempInt)/10;
        count++;
    }


    int finalCount = 0;
    int bla=(m>n)?m+1:n+1;
    char answer[bla];

    if (tempInt != 0)
    {
        answer[finalCount]= tempInt+'0';
    }else
    {}
    
    
    for (int i = 0; i < amountF; i++)
    {
        answer[finalCount]=ans_int[i];
        finalCount++;
    }
    if (ans_float[0]!='0')
    {
        answer[finalCount] ='.';
        finalCount++;
           for (int i = 0; i < amountFloat; i++)
    {
        
        answer[finalCount]=ans_float[i];
        finalCount++;
    }
    for (int i = finalCount; i >0; i++)
    {
        if (answer[i] == '.')
        {
            break;
        }
        if (answer[i] == '0')
        {
            finalCount-=2;
            break;
        }
        
        
    }
    

    }
    for (int i = 0; i < finalCount; i++)
    {
        printf("%c",answer[i]);
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%c %c %c %c\n",num1_int[i],num1_float[i],num2_int[i],num2_float[i]);
    // }
    
    // printf("%s %s %s %s",num1_int,num1_float,num2_int,num2_float);

    return 0;
}

