#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
/***** Begin *****/
int main()
{
    int n;
    scanf("%d",&n); 
    long int  a[n];
    a[0]=1;
    a[1]=1;
    int i;
    
    #pragma omp parallel for
    for(i=2;i<n;i++)
    {
        a[i]= (long int)((1.0/sqrt(5.0))*(pow(((1.0+sqrt(5.0))/2.0),(i+1))-pow(((1.0-sqrt(5.0))/2.0),(i+1))));
    }
    
    
    for(i=0;i<n;i++)
    {
        printf("%ld",a[i]);
        if(i<n-1) printf(" ");
        if(i==n-1) printf("\n");
       
    }
	return 0;
}
/***** End *****/
