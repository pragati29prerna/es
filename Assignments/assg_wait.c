//C program to demonstrate working of wait()

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
    pid_t id; //opaque datatype
    id =fork(); //calling fork

    if (id== 0) //child
    {
         printf("Child: hello from child\n");
    }
       
    else //parent
    {
        printf("Parent: hello from parent\n");
        wait(NULL);
        printf("child has terminated\n"); //this will print after sometime due to wait API
    }
 
    printf("Bye\n");
    return 0;
}