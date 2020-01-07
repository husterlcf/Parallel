#include<stdio.h>
#include<math.h> 
int main(){
	int n;
	scanf("%d",&n);
	int k=(int)sqrt((1+8*n))/2.0-0.5;
	printf("%d\n",k);
	int i; 
	int a[n];
	int b[n]; 
	int j=0;
	for(i=2;i<=k;i++){
	    if((!((2*n-i*i)%i))&&(2*n-i*i)/i>1)
	    	{
	    		
	    		if(!(((2*n-i*i)/i+1)%2))
	    		{
				a[i]=((2*n-i*i)/i+1)/2;
	    		b[j]=i;
	    		j++;}
			}
	    
    	
    
         
       
	}
	for(i=0;i<j;i++){
		printf("%d %d\n",a[i],b[i]);
	}
	
	return 0;
}


