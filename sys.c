#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

	// make two process which run same
	// program after this instruction
	int m=fork();

	printf("Hello world!\n");
	return 0;
}
