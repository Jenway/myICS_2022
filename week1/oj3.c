#include <stdio.h>
#include <math.h>

int main(){
	int a[3][3],b[3][3];
	//输入矩阵
	for(int y=0;y<=2;y++){
		for(int x=0;x<=2;x++){
			scanf("%d",&a[x][y]);
		}
	}
	for(int y=0;y<=2;y++){
		for(int x=0;x<=2;x++){
			scanf("%d",&b[x][y]);
		}
	}
	//开始输出
	//加法
	for(int y=0;y<=2;y++){
		for(int x=0;x<2;x++){
			printf("%d\t",a[x][y]+b[x][y]);
		}
		printf("%d\n",a[2][y]+b[2][y]);
	}
	printf("\n");
	//减法
	for(int y=0;y<=2;y++){
		for(int x=0;x<2;x++){
			printf("%d\t",a[x][y]-b[x][y]);
		}
		printf("%d\n",a[2][y]-b[2][y]);
	}
	printf("\n");
	//乘法
	for(int y=0;y<=2;y++){
		for(int x=0;x<2;x++){
			printf("%d\t",a[0][y]*b[x][0]+a[1][y]*b[x][1]+a[2][y]*b[x][2]);
		}
		printf("%d\n",a[0][y]*b[2][0]+a[1][y]*b[2][1]+a[2][y]*b[2][2]);
	}
	printf("\n");
	//转置
	for(int y=0;y<=2;y++){
		for(int x=0;x<2;x++){
			printf("%d\t",a[y][x]);
		}
		printf("%d\n",a[y][2]);
	}
	return 0;
}