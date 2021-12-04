#include <stdio.h>
/*including header files for open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*including header file for write*/
#include <unistd.h>
/*including header files for exit*/
#include<stdlib.h>
/*including header files for error no.*/
#include<errno.h>


int main(int argc, char const *argv[])
{
    int fd; //open returns int file descriptor
    fd= open("desd.txt",O_WRONLY);

    if(fd==-1)
    {
        perror("Error occured:\n"); // if error occured then print the reason
        _exit(EXIT_FAILURE);
    }

    write(fd,"HELLO WORLD",11); //write to a file descriptor
    printf("\nfile descriptor value is: %d\n",fd);
    close(fd);
    return 0;
}
