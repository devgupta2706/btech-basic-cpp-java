#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<sys/ipc.h>
int n_or_squareof_n, i;
void *process_1(void *args);
void *process_2(void *args);
void *process_1(void *args)
{
    int *myID = (int *)args;
    pthread_t T;
    //srand(time(0));
    n_or_squareof_n = 1 + rand() % 500;
    // to getting random number between 1 to 500
    printf("Number we get is: %d\n", n_or_squareof_n);
    pthread_create(&T, NULL, &process_2, NULL);
    pthread_join(T, NULL);
    printf("Square of the Number is :%d\n\n", n_or_squareof_n);
    return 0;
}
void *process_2(void *args)
{
    int *myID = (int *)args;
    n_or_squareof_n = pow(n_or_squareof_n, 2);
    return 0;
}
int main()
{
    pthread_t T1;
    key_t ftok("process",65);
    int shm=shmget(key,1024,0666|IPC_CREAT);
    printf("Before Execution \n\n");
    for (i = 0; i < 5; i++)
    {
        printf("Case %d\n", i + 1);
        pthread_create(&T1, NULL, &process_1, NULL);
        pthread_join(T1, NULL);
    }
    printf("\nAfter Execution ");
    pthread_exit(NULL);
    return 0;
}