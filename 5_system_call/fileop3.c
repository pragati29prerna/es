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
    int fd;
/*if file doesn't exist, open() system call creates the file and give permission*/
    open("fd.txt",O_WRONLY|O_CREAT|S_IRUSR|S_IWUSR);

    if(fd==-1)
    {
        perror("ERROR OCCURED:\n"); //if error occured then print the reason
    
    }

    write(fd,"SUCCESSFUL",10); //write to a file descriptor
    printf("\nfile descriptor value is: %d\n",fd);

    close(fd); 
    return 0;
}
