#include<stdio.h>

int gcd (int a,int b);
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int temp=a[0];
	for(i=0;i<n;i++){
		if(temp==a[i])
		temp=a[i];
		
		else{
			temp= gcd(temp ,a[i]);
		}
	}
	
	int sum=0;
	
	for(i=0;i<n;i++){
		
		sum=sum+a[i]/temp;
		
	} 

	printf("%d",sum);
	return 0;
	
	
} 


int gcd (int a,int b)
{
	int c;
	while(a!=b){
		if(a<b)
		{
			c=a;
			a=b;
			b=c;
		}
		a=a-b;
	}
	
	return b;
}
