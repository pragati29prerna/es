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
//#define MAX 16

int main(int argc, char const *argv[])
{
int fd;
printf("writing\n");
fd =open("desfifo",O_WRONLY);
write(fd,"WELCOME",8);

if(fd==-1)
    {
        perror("Error occured:\n"); // if error occured 
        exit(EXIT_FAILURE);
    }
    
close(fd);

    return 0;
}
