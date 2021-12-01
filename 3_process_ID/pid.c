#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{

printf("ID: %d\n",getpid()); //returns the process ID (PID) of the calling process.

printf("Parent ID: %d\n",getppid()); //returns the process ID of the parent of the calling process.
    return 0;
}
