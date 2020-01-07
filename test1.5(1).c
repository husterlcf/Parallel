#include <stdio.h>

/***** Begin *****/
int main()
{
    int i,k;
    long m=0,n=0;
    long t;
   scanf("%d",&i);
   for(k=1;k<i;k++){
         if(k==1){
               printf("1 ");
               n=1;
           }   
         else{
               t=n;
               n=n+m;
               m=t;
               printf("%ld ",n);
           }
    
   }
   // cudaError_t cudaMalloc (void **devPtr, size_t  size );
   // cudaError_t cudaMemcpy ( void* dst, const void* src, size_t count, cudaMemcpyKind kind );
    if(k==1){
     printf("1\n");
     n=1;
    }   
    else   printf("%ld\n",m+n);
   return 0;
}
/***** End *****/

