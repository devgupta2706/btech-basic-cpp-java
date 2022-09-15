#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char *args[]={"./ipc_create",NULL};
    execvp(args[0],args);
    printf("\nThe End---");
    return 0;
}