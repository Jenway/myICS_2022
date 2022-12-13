#include<stdio.h>
#include<stdlib.h>

void stdNum(int*num,int size);
int main(void){
    int n;          scanf("%d",&n);
        char *cnum1 = malloc(n*sizeof(char));   scanf("%s",cnum1);
    int m;          scanf("%d",&m);
        char *cnum2 = malloc(m*sizeof(char));   scanf("%s",cnum2);
    int num1[n],num2[m];
    for (int i = 0; i < n; i++)
    {
        num1[i] = cnum1[i]-'0';
    }
    for (int i = 0; i < m; i++)
    {
        num2[i] = cnum2[i]-'0';
    }
    
    int tempSize1 =(n>m)?n:m,tempSize2 =(n>m)?m:n;
    int *tempNum1 =(n>m)?num1:num2,*tempNum2 =(n>m)?num2:num1;
    int ans[tempSize2][m+n+1];
    for (int i = 0; i < tempSize2; i++)
    {
        stdNum(ans[i],m+n+1);
    }
    

    // printf("%d %s %d %s",tempSize1,tempNum1,tempSize2,tempNum2);
    int temp=0;
    for (int j = 0; j < tempSize2; j++)
    {   temp=0;
        for (int i = m+n,count =0; i > tempSize2; i--,count++)
        {
                ans[j][i-j]= ((tempNum1[tempSize1-count-1])*(tempNum2[tempSize2-j-1])+ temp)%10 ;
                temp = ((tempNum1[tempSize1-count-1])*(tempNum2[tempSize2-j-1]) + temp)/10;
        }
        ans[j][tempSize2-j] = temp;
    }
    int ansF[m+n+1];

                    

                    
    int tempInt =0;
    for (int i = m+n; i >=0; i--)
    {
        ansF[i]=0;
        ansF[i]+=tempInt;
        for (int j = 0; j < tempSize2; j++)
        {
            ansF[i]+=(ans[j][i]);
        }
        tempInt = (ansF[i])/10;
        ansF[i] = (ansF[i])%10;
        // printf("%d ",i);
        // printf("%c\n",ansF[i]);
    }
    ansF[0]=tempInt;
                    //     int ansDebug[m+n+1];
                    // for (int i = 0; i < m+n+1; i++)
                    // {
                    //     ansDebug[i]=ansF[i];
                    // }
    int sizeF =(ansF[1]!=0)?m+n:m+n-1;
    char ansFF[sizeF+1];
    for (int i = 1; i <= sizeF; i++)
    {
        ansFF[sizeF-i] = ansF[m+n+1-i]+'0';
        // printf("%d ",m+n+1-i);
        // printf("%c\n",ansF[m+n+1-i]);
    }
    ansFF[sizeF]='\0';
    printf("%s",ansFF);
    return 0;
}

void stdNum(int*num,int size){
    for (int i = size-1; i >=0 ; i--)
    {
            num[i]=0;
    }
}