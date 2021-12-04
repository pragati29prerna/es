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
#define MAX 64

int main(int argc, char const *argv[])
{
    int fdr, fdw;
    unsigned char buff[MAX];
    
    /*write in source file*/
    fdr = open("src.txt",O_WRONLY);
    write(fdr,"EMBBEDED OPERATING SYSTEM\n",MAX);
    close(fdr);

    fdr = open("src.txt",O_RDONLY);
    printf("fd:%d\n",fdr);
    
   // if error occured 
     if(fdr==-1)
    {
        perror("Error occured:\n"); 
        exit(EXIT_FAILURE);
    }

    // Destination file
    fdw = open("ds.txt",O_WRONLY|O_CREAT); //if file doesn't exist then create a file
    
    while(read(fdr,buff,MAX))
    {
        write(fdw,buff,MAX); //copy the content in destination file
    }
    printf("Read the file:%s\n",buff); //print what is copied
    return 0;

}
