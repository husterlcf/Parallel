#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <string.h>

/***** Begin *****/
int main(int argv,char* argc[])
{
	

    int numprocs, myid, source ,n;
    MPI_Status status;
  //scanf("%d",&n)
  
int i;
  long int a[argv];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    if (myid != 0) {  //非0号进程发送消息
  
        a[myid]= (long int)((1.0/sqrt(5.0))*(pow(((1.0+sqrt(5.0))/2.0),(myid+1))-pow(((1.0-sqrt(5.0))/2.0),(myid+1))));
    }
   
   else {   // myid == 0，即0号进程接收消息
       for(i=0;i<n;i++)
    {
        printf("%ld",a[i]);
        if(i<n-1) printf(" ");
        if(i==n-1) printf("\n");
       
    }
    }
    MPI_Finalize();

 
	return 0;
}
/***** End *****/

