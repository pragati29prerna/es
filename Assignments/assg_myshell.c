
#include <stdio.h>
#include <sys/types.h>
/*including header file exec API*/
#include <unistd.h>
#include <stdlib.h>
/*ncluding header file of string*/
#include <string.h>
#define MAX 32

   int main(int argc, char const *argv[])
    {
     pid_t id; //opaque datatype
     int fd[2];//file descriptor
     pipe(fd); //pipe
     unsigned char cmd[MAX];

    printf("myshell:~$");
    scanf("%s",cmd);

     id=fork();

    if(id==0)
    {
    //Read in child

    printf("\nchild:before execl\n");
    read(fd[0],&cmd,MAX);
    printf("child:%s\n",cmd);

        if(strcmp(cmd,"ls")==0) 
        {
        execl("/bin/ls","/bin/ls","-a","-l",NULL); //ls command
        }
        else if(strcmp(cmd,"env")==0)
        {
        execl("/usr/bin/env","/usr/bin/env",NULL); //env command
        }
        else if(strcmp(cmd,"pwd")==0)
        {
         execl("/usr/bin/pwd","/usr/bin/pwd",NULL); //pwd command
        }
        else
        printf("[ERROR] is not a valid command.\n"); //error
    }
  
    else
    {
        //write in parent
        
        write(fd[1],&cmd,MAX);
        printf("parent:%s\n",cmd);
    }
        return 0;
     }
  
