#include <stdio.h>
#include <string.h>
/*including header files for open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*including header file for write*/
#include <unistd.h>
/*including header files for exit*/
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd[2],fdr[2],i;
    
    unsigned int sum,a,b;

    pipe(fdr); // create 1st pipe descriptors
    pipe(fd); // create 2nd pipe
 
    printf("Enter two numbers \n"); //user input
    scanf("%d %d",&a,&b);
    
     int id = fork(); //calling fork
    
    if (id != 0)  // fork() returns 0 for child process, child-pid for parent process.
    {
        close(fd[0]); // parent: writing only, so close read-descriptor.

        write(fd[1],&a, 20); // send the value on the write-descriptor.
        write(fd[1],&b, 20); 
        printf("Parent: writing 2 values are => %d %d\n", a,b); 

        
        close(fd[1]);// close the write descriptor

        
        close(fdr[1]); // child: reading only, so close the 2nd write-descriptor

        
        read(fdr[0],&sum, 20); // read the send value from child after summation
        printf("Parent: Read sum value => %d\n",sum);
        
        close(fdr[0]); // close the 2nd read-descriptor
    }
    else
    {   
        close(fd[1]); // child: reading only, so close the write-descriptor

        // read the two values send by the parent
        read(fd[0],&a, 20);
        read(fd[0],&b, 20);
        printf("child: Read the send value from parent => %d %d\n", a,b);
        
        close(fd[0]); // close the read-descriptor

        close(fdr[0]); //close the 2nd read descriptor
        
        sum =a+b; //summation of two parent given values
        
        write(fdr[1],&sum,20); // write the sum value
        printf("child: Writing sum value is: %d\n", sum);

        
        close(fdr[1]); // close the 2nd write descriptor

    }
    return 0;
}
