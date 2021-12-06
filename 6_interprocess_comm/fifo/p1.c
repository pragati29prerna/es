
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
#define MAX 16

int main(int argc, char const *argv[])
{
unsigned char buff[MAX];
int fd;

printf("reading\n");
fd =open("desfifo",O_RDONLY);
read(fd,&buff,MAX);
printf("read is :%s\n",buff);

if(fd==-1)
    {
        perror("Error occured:\n"); // if error occured 
        exit(EXIT_FAILURE);
    }

close(fd);

    return 0;
}
