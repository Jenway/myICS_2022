#include<stdio.h>
#include<string.h>


int main(void){

    char word[100]={0};
    scanf("%s",&word);
    int len;
    for (len = 0;word[len]!=0; len++)
    {
    }
        if ((word[len-2] == 'c'&&word[len-1] == 'h')||(word[len-2] == 's'&&word[len-1] =='h')
        ||word[len -1] == 's' ||word[len-2] == 'x')
        {
            word[len] = 'e';
            word[len+1] = 's';
        }
        else if (word[len - 1]=='o')
        {
            word[len] = 'e';
            word[len+1] = 's';
        }
        else if (word[len-1] =='y')
        {
            word[len-1] ='i';
            word[len] = 'e';
            word[len+1]= 's';
        }
        else{
            word[len] ='s';
        }
    
    if(word[len+1]==0)
	{
		for(int i=0;i<len+1;i++)
		{
			printf("%c",word[i]);
		}
	}else {
		for(int i=0;i<len+2;i++)
		{
			printf("%c",word[i]);
		}
	}
    return 0;
}
