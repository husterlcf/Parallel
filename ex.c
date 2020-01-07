#include<stdio.h>
 int jie( int n) ;
 int zuhe(int n,int m);
int main(){
	int N;
	scanf("%d",&N);
	int a[N+1];
	int i;
	for(i=1;i<=N;i++){
		if(i==1) a[i]=jie(N);
		else if(i>1&&i<N)
		{
			a[i]=zuhe(N,i)*jie((N-i+1));
		}
		else a[i]=1;
	}
	 int sum=0;
	for(i=1;i<=N;i++){
		sum=sum+a[i];
	}
	printf("%d",sum);
} 

 int jie( int n) 
{
    int sum=1;
	int i;
	for(i=1;i<=n;i++){
		sum=sum*i;
		
	}
	
	return sum;
}

int zuhe(int n,int m){
	
	
	int i;
	int sum=1;
	for(i=0;i<m;i++){
		sum=sum*(n-i);
	}
	
	sum =sum/jie(m);
	return sum;
}
