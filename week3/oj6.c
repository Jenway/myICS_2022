#include<stdio.h>

int main(void){
	int n;
	int key;
	scanf("%d%d",&n,&key);
	int nums[n];
	for(int i = 0;i<n;i++){
		//TODO
		scanf("%d",&nums[i]);
	}

	int left = 0;
	int right = n-1;
	int try;
	while(left <= right){
		//TODO
		try = (left + right) /2;
		if(nums[try] > key){
			right = try-1;	
		}
		else if(nums[try]< key){
			left = try+1;
		}
		else if (nums[try]== key)
		{
			printf("%d",try);
			return 0;
		}

	}
	printf("-1");
	return 0;
}

