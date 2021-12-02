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
    printf("After fork: %d\n",id); //prints parent as well as child id

    if(id==0) //true for child
    {
        printf("child\n");
    }
    else
    {
      printf("parent\n");
    }
        

    return 0;
}
