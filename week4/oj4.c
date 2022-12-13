#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void readLoca(int *intSize,char *num,int n);
void readNum(char* origin,int* num_int,int* num_float,int intSize,int num);
void addFloat(int* tempInt,int* num1,int * num2,int *num_float,int size,int size1,int size2);
void addInt(int* tempInt,int* num1,int * num2,int *num_int,int size,int size1,int size2);
void printAns(int *num_int,int *num_float,int intSize,int floatSize);

int main(void){
    int n;          scanf("%d",&n);char num1[n];   scanf("%s",num1);
    int m;          scanf("%d",&m); char num2[m];   scanf("%s",num2);
    int intSize1,intSize2;
    readLoca(&intSize1,num1,n);readLoca(&intSize2,num2,m);
    int intSize3 = (intSize1>intSize2)?intSize1:intSize2; 
    int floatSize3 =(n-intSize1-1>m-intSize2-1)?n-intSize1-1:m-intSize2-1;
    int floatSize1 = n-intSize1-1;
    int floatSize2 = m-intSize2-1;

    int num_int1[intSize1],num_float1[n-intSize1-1];
    int num_int2[intSize2],num_float2[m-intSize2-1];

    readNum(num1,num_int1,num_float1,intSize1,n);
    readNum(num2,num_int2,num_float2,intSize2,m);

    int tempInt=0;
    int ansInt[intSize3+1];int ansFloat[floatSize3];

    addFloat(&tempInt,num_float1,num_float2,ansFloat,floatSize3,floatSize1,floatSize2);
    addInt(&tempInt,num_int1,num_int2,ansInt,intSize3,intSize1,intSize2);
    printAns(ansInt,ansFloat,intSize3,floatSize3);
    return 0;
}

void readLoca(int *intSize,char *num,int n){
    for (int i = 0; i < n; i++)
    {
        if (num[i]=='.')
        {
            *intSize = i;
            return;
        }
    }
    *intSize = n;
}
void readNum(char* num,int* num_int,int* num_float,int HMfloat,int n){
        for (int i = 0,count =0,flag =1; i < n; i++)
    {
        if (i == HMfloat)
        {
            flag*=-1;
            continue;
        }else{}
        if (flag>0)
        {
            num_int[i]= num[i]-'0';
        }
        else
        {
            num_float[count]= num[i]-'0';
            count ++;
        }  
    }
}
void addFloat(int* tempInt,int* num1,int* num2,int *num,int size,int size1,int size2){
    int temp = (size1>size2)?size1:size2; // larger one
    int temp2 = (size1>size2)?size2:size1;
    int *tempNum = (size1>size2)?num1:num2;
    int *tempNum2= (size1>size2)?num2:num1;
    int count =0;
    for (int i = size-1; i >= 0; i--)
    {
        if (temp==temp2)
        {
            num[i] = (tempNum[i] + tempNum2[temp2-count-1] + *tempInt)% 10;
            *tempInt =(tempNum[i] + tempNum2[temp2-count-1]+ *tempInt)/ 10;
            count++;
        }
        else
        {
            if(i >= temp2){
                num[i] = tempNum[i];
                *tempInt=0;
            }
            else
            {
                num[i] = (tempNum[i] + tempNum2[temp2-count-1] + *tempInt)% 10;
                *tempInt =(tempNum[i] + tempNum2[temp2-count-1]+ *tempInt)/ 10;
                count++;
            }
        }    
    }
}
void addInt(int* tempInt,int* num1,int * num2,int *num,int size,int size1,int size2){
    int tempSize = (size1>size2)?size1:size2;  // larger one
    int tempSize2 = (size1>size2)?size2:size1; // smaller one
    int *tempNum = (size1>size2)?num1:num2; // larger one
    int *tempNum2= (size1>size2)?num2:num1; // smaller one
    int count =0;
    for (int i = size-1; i >=0; i--)
    {
        if (tempSize == tempSize2)
        {
            num[i+1] = (tempNum[i] + tempNum2[tempSize2-1-count]+ *tempInt)%10;
            *tempInt = (tempNum[i] + tempNum2[tempSize2-1-count]+ *tempInt)/10;
            count++;
        }
        else
        {
            if (i < (tempSize-tempSize2))
            {
                num[i+1] = (tempNum[i] + *tempInt)%10;
                *tempInt = (tempNum[i] + *tempInt)/10;
            }
            else
            {
                num[i+1] = (tempNum[i] + tempNum2[tempSize2-1-count]+ *tempInt)%10;
                *tempInt = (tempNum[i] + tempNum2[tempSize2-1-count]+ *tempInt)/10;
                count++;
            }
        }
    }
    num[0]= *tempInt;
}
void printAns(int *num_int,int *num_float,int intSize,int floatSize){
    // 小数位全是0则flag =1
    int flag =1;
    for (int i = 0; i < floatSize; i++)
    {
        if (num_float[i]!=0)
        {
            flag=-1;
            break;
        }
    }
    int flagTail =0; // flagtail 为小数位最后一位有效数字位数
    int ansSize;// 如果不全为零，则寻找末尾的无效零
    if (flag == -1)
    {
        for (int i = floatSize-1; i >=0; i--)
        {
            if (num_float[i]!=0)
            {
                flagTail =i+1;
                break;
            }    
        }  
        if (num_int[0]==0)
        {
            ansSize = intSize+1+flagTail+1;
        }
        else
        {
            ansSize = 1+intSize+1+flagTail+1;
        }
    }
    else
    {   
        if (num_int[0]==0)
        {
            ansSize = intSize+1;
        }
        else
        {
            ansSize = 1+intSize+1;
        }    
    }
    char *ans = malloc (sizeof (char) * (ansSize));
    int count =0;
    for (int i = 0; i<= intSize; i++)
    {
        if (i==0 && num_int[0]==0)
        {
            continue;
        }
        ans[count]='0'+num_int[i];
        count++;
    }

    if (flag==-1)
    {
        ans[count]='.';
        count++;
        for (int i = 0; i < flagTail; i++)
        {
            ans[count]='0'+num_float[i];
            count++;
        }
    }
    ans[ansSize-1] = '\0';//结束字符串
    printf("%s\n",ans);
    free(ans);

}
