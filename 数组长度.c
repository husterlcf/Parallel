#include<stdio.h>
int main(){
	int a[][2]={{1,2},{2,3},{2,3},{2,3},{2,3},{2,3},{2,3},{2,3}};
	printf("%d\n",sizeof(a)/sizeof(int));//����Ĵ�С 
	printf("%d\n",sizeof(a[0])/sizeof(int));//�����ж����У�
	printf("%d\n",(sizeof(a)/sizeof(int))/(sizeof(a[0])/sizeof(int)));//�����ж����� 
	 
} 
