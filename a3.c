#include<stdio.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	printf("%d",stirling(n,k));
} 

int stirling(int n,int k){
	
	if(n==1 && k==0) return 1;    
	else if( k==1 || n==k ) return 1;    
	else return stirling(n-1, k)*k+stirling(n-1, k-1); 

}
