#include <stdio.h>

// 对char数组进行排序
void charSort(char *charList, int charAmount);

// 对int数组进行排序
void numberSort(int *numberList, int numberAmount);

// 根据记录的位置将对应的字母装入数组str
void loadChar(char *str, char *charList, int *charLoc, int charAmount);

// 根据记录的位置将对应的数字装入数组str
void loadNumber(char *str, int *numberList, int *numberLoc, int numberAmount);

int main()
{
    // 字符串长度，字符串中字母的数量，数字的数量
    int amount, charAmount = 0, numberAmount = 0;
    char str[1001];
    // 记录str数组中字母的下标和数字的下标
    int charLoc[1001], numberLoc[1001];
    // char数组中字母组成的数组
    char charList[1001];
    // str数组中数字组成的数组
    int numberList[1001];

    scanf("%d %s", &amount, str);

    // 遍历str数组
    for (int i = 0; i < amount; i++)
    {
        char ch = str[i];
        // 对每个位置的字符进行分类和统计
        if (ch >= 'A' && ch <= 'Z')
        {
            // 记录所在下标
            charLoc[charAmount] = i;
            // 记录值
            charList[charAmount++] = ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            //记录所在下标
            numberLoc[numberAmount] = i;
            // 记录值
            numberList[numberAmount++] = ch - '0';
        }
    }

    // 调用对应的函数
    charSort(charList, charAmount);
    numberSort(numberList, numberAmount);
    loadChar(str, charList, charLoc, charAmount);
    loadNumber(str, numberList, numberLoc, numberAmount);

    printf("%s", str);
}

void charSort(char *charList, int charAmount){
    //TODO: 对char数组排序
    char temp;
    // printf("%s\n", charList);
    for (int i = 0; i < charAmount-1; i++)
    {
        for (int j = 0; j < charAmount-1; j++)
        {
            if (charList[j] > charList[j+1] )
            {

                temp = charList[j+1];
                charList[j+1] = charList[j];
                charList[j] = temp;

            }
            
        }
        
    }
    
}

void numberSort(int *numberList, int numberAmount){
    int temp;
    // for (int i = 0; i < numberAmount; i++)
    // {
    //     printf("%d",numberList[i]);
    // }
    

    for (int i = 0; i < numberAmount-1; i++)
    {
        for (int j = 0; j < numberAmount-1; j++)
        {
            if (numberList[j] < numberList[j+1] )
            {

                temp = numberList[j+1];
                numberList[j+1] = numberList[j];
                numberList[j] = temp;

            }
            
        }
        
    }
    //     for (int i = 0; i < numberAmount; i++)

    // {
    //     printf("%d",numberList[i]);
    // }
}

void loadChar(char *str, char *charList, int *charLoc, int charAmount){
    for (int i = 0; i < charAmount; i++)
    {
        str[charLoc[i]] = charList[i];
    }
    
}

void loadNumber(char *str, int *numberList, int *numberLoc, int numberAmount){
        for (int i = 0; i < numberAmount; i++)
    {
        str[numberLoc[i]] = numberList[i]+ '0';
    }
}
