#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int n=6;
    printf("\nI am executing execDemo.c called by execvp()%d ",n);
    return 0;
}