/* including standard header file*/
#include <stdio.h>
/*including fork header file*/
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    pid_t id; //opaque data type

    printf("Before fork \n"); //print only parent id
    id=fork(); //calling fork

    if(id==0) //true for child
    {
        printf("child PID:%d\n",getpid()); //gets the child ID
        printf("child PPID:%d\n",getppid()); //gets the child's parent ID
    }
    
    else
    {
         printf("parent PID:%d\n",getpid());//gets the parent ID
         printf("parent PPID:%d\n",getppid());//gets the parent's parent ID
         sleep(10);
         printf("parent finished\n");
    }
    return 0;
}
