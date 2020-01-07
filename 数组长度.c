#include<stdio.h>
int main(){
	int a[][2]={{1,2},{2,3},{2,3},{2,3},{2,3},{2,3},{2,3},{2,3}};
	printf("%d\n",sizeof(a)/sizeof(int));//数组的大小 
	printf("%d\n",sizeof(a[0])/sizeof(int));//数组有多少列；
	printf("%d\n",(sizeof(a)/sizeof(int))/(sizeof(a[0])/sizeof(int)));//数组有多少行 
	 
} 
