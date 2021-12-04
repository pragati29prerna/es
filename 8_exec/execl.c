
/*including standard header file */
#include <stdio.h>
/*including header file exec API*/
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("before\n");
    execl("/home/pprerna/today/exec","/home/pprerna/today/exec",NULL); //call execl i.e l varient which can pass n no. of arguments
    printf("After\n"); 
    return 0;
}
