#include<stdio.h>

int jump(int n);

int main(void){
    int n;
    int ways;
    scanf("%d",&n);
    ways = jump(n);
    printf("%d",ways);



    return 0;
}

// 

int jump(int n){ 
    if (n < 1 )
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
  	else if(n==2)
    {
    return 2;
    }
    else if(n==3)
    {
    return 4;
    }

	int a = 1;
	int b = 2;
	int c = 4;
	int temp = 0;
	for (int i = 4; i <= n; i++)
	{
		temp = a+b+c;
		a = b;
		b = c;
		c = temp;
	}
	
	return temp;

}