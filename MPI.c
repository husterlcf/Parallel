#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <string.h>

/***** Begin *****/
void swap(int a[], int low, int high);
int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);

int main(int argv,char* argc[])
{
    int numprocs,myid,source;
    MPI_Status status;
    int n;
    scanf("%d",&n);    
    int i=1;
    if(n<1)
        printf("Wrong input!");
    else if(n==1)
    	printf("1\n");
    else if(n==2)
        printf("1 1\n");
    else{
        MPI_Init(&argv,&argc);
    	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
        long a[n],message;
        int n=0;
        while(i<=n){
        	if(myid!=0){
    			message=(1/sqrt(5))*(pow(((1+sqrt(5))/2),i)-pow(((1-sqrt(5))/2),i));
                i++;
                MPI_Send(message,1,MPI_LONG,0,99,MPI_COMM_WORLD);
        	}
            else{
                for(souce=1;source<numprocs;source++){
                    MPI_Recv(message,1,MPI_LONG,source,99,MPI_COMM_WORLD,&status);
                    a[n]=message;
                    n++;
                }
            }
        }
        quicksort(a,0,n-1);
        	for(i=0;i<n-1;i++)
            printf("%ld ",a[i]);
        printf("%ld\n",a[n-1]);
    }
	return 0;
}


void swap(int a[], int low, int high)
{
    int temp;
    temp = a[low];
    a[low] = a[high];
    a[high] = temp;
}
 
int partition(int a[], int low, int high)
{
    int base = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= base)
        {
            high --;
        }
        swap(a, low, high);
        while(low < high && a[low] <= base)
        {
            low ++;
        }
        swap(a, low, high);
    }
    return low;
}
 
void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int base = partition(a, low, high);
        quicksort(a, low, base - 1);
        quicksort(a, base + 1, high);
    }
}

/***** End *****/

