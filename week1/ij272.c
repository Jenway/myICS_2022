#include <stdio.h>

int value[100], weight[100], c, max=0, wei, temp[100]={0}, num[100]={0};

extern void unselect(int count, int wi, int vi); //事先声明unselect函数，否则select函数中无法嵌套unselect

void select(int count, int wi, int vi){
	if(count == -1 || wi == c){  //判断数据是否到达边界需要终止
		if(vi > max){            //如果决定终止，判断本轮循环的value是否目前最大
			max = vi;
			wei = wi;
			for(int i=0; i<=100; i++){
				num[i] = temp[i];  //如果本轮value目前最大，将临时数据存入正式输出数组
			}
		}
		return;
	}
	if(c >= wi + weight[count]){ //如果无需终止，判断背包容量是否足以装下该物品
		wi += weight[count];     //装入后重量
		vi += value[count];      //装入后价值
		temp[count] = count + 1; //在临时数组中记录装入物品编号
	}
		count--;
		select(count, wi, vi);    //下一件物品选择装入（如果可以）
		unselect(count, wi, vi);  //下一件物品选择不装
	
}

void unselect(int count, int wi, int vi){
	if(count == -1 || wi == c){  //判断数据是否到达边界需要终止
		if(vi > max){            //如果决定终止，判断本轮循环的value是否目前最大
			max = vi;
			wei = wi;
		}
		return;
	}
	temp[count] = 0;
	count--;
	select(count, wi, vi);    //下一件物品选择装入（如果可以）
	unselect(count, wi, vi);  //下一件物品选择不装
}

int main(){
	int n, wi=0, vi=0;
	scanf("%d%d", &c, &n); 
	
	for(int i=0; i<n; i++){
		scanf("%d", &weight[i]); //输入重量
	}
	
	for(int i=0; i<n; i++){
		scanf("%d", &value[i]); //输入价值
	}
	//执行递归
	select(n-1, wi, vi);
	unselect(n-1, wi, vi);
	//开始输出答案
	//输出背包中物品编号
	for(int i=0;i<n;i++){
		if(num[i]!=0){
			printf("%d ",num[i]);
		}
	}
	//输出背包重量与价值
	printf("%d %d", wei, max);
	return 0;
}
