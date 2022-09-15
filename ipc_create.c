#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n_or_squareof_n, i;
void *process_1(void *args);
void *process_2(void *args);
void *process_1(void *args)
{
    int *myID = (int *)args;
    pthread_t T;
    srand(time(0));
    n_or_squareof_n = 1 + (rand()+i*234) % 500;
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
// this is the output
/*Before Execution 

Case 1
Number we get is: 474
Square of the Number is :224676

Case 2
Number we get is: 208
Square of the Number is :43264

Case 3
Number we get is: 442
Square of the Number is :195364

Case 4
Number we get is: 176
Square of the Number is :30976

Case 5
Number we get is: 410
Square of the Number is :168100


After Execution */