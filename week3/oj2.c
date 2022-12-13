#include <stdio.h>
#include<math.h>

int main(void){
	
	int num;
	int count =0;
	int temp;
	scanf("%d",&num);
	int numStr[num];
	for(int i=0;i<num;i++){
		scanf( "%d",&numStr[i]);
	}
	for(int i=0;i<num;i++){
		temp = sqrt(numStr[i]);
		temp = pow(temp,2);
		if(temp == numStr[i]){
			count += 1;
		}
	}
	
	printf("%d",count);
	return 0;
}
