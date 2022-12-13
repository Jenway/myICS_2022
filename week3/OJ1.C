#include<stdio.h>

int main(void){
	int romPla,num,flag;
	num = 0;
	flag = 1;
	scanf("%d",&romPla);
	char romNum[romPla];
	scanf("%s",romNum);
	
	for(int i=romPla-1;i>=0;i--){
		if(romNum[i]=='I'){
			num += flag;
		}
		else if(romNum[i] == 'V'){
			num += 5;
			flag *= -1;
		}
		else if(romNum[i]=='X'){
			num += 10;
			flag *= -1;
		}
	}
	printf("%d\n",num);
	
	return 0;
}
