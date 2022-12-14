#include<stdio.h>
#define N 7		//物品的个数
#define W 150	//背包容量

int B[N][W] = { 0 };
int w[7] = { 10,40,30,50,35,40,30};	//物品重量
int v[7] = { 35,30,6,50,40,10,25};//物品价值
void knapsack();

int main()
{
	knapsack();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("\n?????\n%4d ", B[i][j]);
		}
		printf("\n");
	}
}

void knapsack()
{
	int k;	//第K个物品
	int C;	//背包剩余重量

	//填表
	for (k = 1; k < N; k++)
	{
		for (C = 1; C < W; C++)
		{
			if (w[k] > C)								//第k件物品放不进去 此时背包的价值 = 判断完上一件物品之后背包的价值
			{
				B[k][C] = B[k - 1][C];
			}
			else
			{
				int value1 = B[k - 1][C - w[k]] + v[k];	//放入第k件物品后 背包总价值 = 先给这件物品留出空间，剩余的背包大小能装进的最大价值 + 这件物品的价值
				int value2 = B[k - 1][C];				//不放入第k件物品 背包总价值 = 不用给这件物品留出空间，当前背包大小能装进的最大价值(就是判断完上一件物品之后背包的价值)

				if (value1 > value2)
				{
					B[k][C] = value1;
				}
				else
				{
					B[k][C] = value2;
					if (value1 < value2)printf("k=%d C=%d\n", k, C);
				}
			}
		}
	}
}