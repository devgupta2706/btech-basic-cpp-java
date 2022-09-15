#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int n, sum, evensum;
void *getnaturalsum(void *args)
{
    int *myID = (int *)args;
    sum = n * (n + 1) / 2;
    printf("Sum of N natural numbers=%d\n", sum);
    return NULL;
}
void *evennumbersum(void *args)
{
    int *myID = (int *)args;
    evensum = (n / 2) * ((n / 2) + 1);
    printf("Sum of N/2 even natural numbers=%d\n", evensum);
    return NULL;
}
int main()
{
    pthread_t T1, T2;
    printf("Enter the number to get sum upto that number\t");
    scanf("%d", &n);
    printf("Before Execution \n");
    pthread_create(&T1, NULL, &getnaturalsum, NULL);
    pthread_create(&T2, NULL, &evennumbersum, NULL);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    printf("After Execution \n");
    printf("-------Part2---------------\n");
    printf("The difference between Natural Sum and Even Numbers sum :%d", sum - evensum);
    pthread_exit(NULL);
    return 0;
}
/*--------------this is the output-----------------------
Enter the number to get sum upto that number    19
Before Execution
Sum of N natural numbers=190
Sum of N/2 even natural numbers=90
After Execution
-------Part2---------------
The difference between Natural Sum and Even Numbers sum :100
*/