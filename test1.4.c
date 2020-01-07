#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <string.h>
/*********Begin*********/

long long a[200];
long long r[200];
int max_len=70;

long long fib(int n)
{
    
    return (pow((1+sqrt((double)5)),n)-pow((1-sqrt((double)5)),n))/(pow((double)2,n)*sqrt((double)5));
}

int main(int argv,char* argc[])
{
    int myid,numprocs,namelen;
    
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    
    MPI_Init(&argv,&argc);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Status status;
    
    memset(a, 0, sizeof(long long)*max_len);
    memset(r, 0, sizeof(long long)*max_len);
    
    
    int N = max_len/(numprocs-1);
    if(max_len%(numprocs-1) != 0)
        N++;
    if(myid != 0)
    {
        for(int i = (myid-1)*N; i < myid*N; i++)
        {
            a[i] = fib(i);
        }
        MPI_Send(a, max_len, MPI_LONG_LONG_INT, 0, 0, MPI_COMM_WORLD);
    }
    else
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i < numprocs; i++)
        {
            MPI_Recv(r, max_len, MPI_LONG_LONG_INT, i, 0, MPI_COMM_WORLD, &status);
            for(int j = (i-1)*N; j < i*N; j++)
            {
                a[j] = r[j];
            }
        }
        for(int i = 1; i < n; i++)
            printf("%lld ", a[i]);
        if (n != 1)
            printf("%lld\n", a[n]);
        else
            printf("1\n");
    }
    MPI_Finalize();
    return 0;
}
/*********End*********/

//标准答案
// #include <stdlib.h>
// #include <stdio.h>
// #include <mpi.h>
// #include <math.h>
// #include <string.h>
// /*********Begin*********/

// long long data[200];
// long long recv[200];
// int max_len=60;
// long long Fib(int n)
// {
//     double gh5=sqrt((double)5);
//     return (pow((1+gh5),n)-pow((1-gh5),n))/(pow((double)2,n)*gh5);
// }
// int main(int argv,char* argc[])
// {
//         int myid;
//         int numprocs;
//         int namelen;
//         char processor_name[MPI_MAX_PROCESSOR_NAME];
//         MPI_Init(&argv,&argc);
//         MPI_Comm_rank(MPI_COMM_WORLD,&myid);
//         MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
//         MPI_Status status;
//         // long long* data = (long long*)malloc(sizeof(long long)*max_len);
//         // long long* recv = (long long*)malloc(sizeof(long long)*max_len);
//         memset(data, 0, sizeof(long long)*max_len);
//         memset(recv, 0, sizeof(long long)*max_len);
//         int localN = max_len/(numprocs-1);
//         if(max_len%(numprocs-1) != 0)
//                 localN++;
//         if(myid != 0)
//         {
//             for(int i = (myid-1)*localN; i < myid*localN; ++i)
//             {
//                 data[i] = Fib(i);
//             }
//             MPI_Send(data, max_len, MPI_LONG_LONG_INT, 0, 0, MPI_COMM_WORLD);
//         }
//         else
//         {
//             int input_num = 0;
//             scanf("%d", &input_num);
//             for(int i = 1; i < numprocs; ++i)
//             {
//                 MPI_Recv(recv, max_len, MPI_LONG_LONG_INT, i, 0, MPI_COMM_WORLD, &status);
//                 for(int j = (i-1)*localN; j < i*localN; ++j)
//                 {
//                     data[j] = recv[j];
//                 }
//             }
//             for(int i = 1; i < input_num; ++i)
//             {
//                     printf("%lld ", data[i]);
//             }
//             if (input_num != 1)
//             {
//                 printf("%lld\n", data[input_num]);
//             }
//             else
//             {
//                 printf("1\n");
//             }
//             // free(data);
//             // free(recv);
//         }
//         MPI_Finalize();
//         return 0;
// }
/*********End*********/

