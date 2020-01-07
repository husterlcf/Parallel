#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
void* func(void *pa);

/***** Begin *****/
int main()
{
	//线程标识符
    pthread_t th;
    //pthread_create的返回值，当为0时表示创建线程成功
    int ret; 
    //累加和的参数
    int n ;
    scanf("%d",&n);
    ret = pthread_create(&th, NULL, func, (void *)&n);
    if( ret != 0 ){
        printf("Create thread error!\n");
        return -1;
    }
    //主线程等待th这个线程退出
    pthread_join(th, NULL);
    return 0;
	
}

void* func( void *pa){
	
    int  *s=(int *) pa;
    int n=*s;
	long  int a[n];
    a[0]=1;
    a[1]=1;
    int i;
    for(i=2;i<n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    for(i=0;i<n;i++)
    {
        printf("%ld",a[i]);
        if(i<n-1) printf(" ");
        if(i==n-1) printf("\n");
       
    }
} 
/***** End *****/

