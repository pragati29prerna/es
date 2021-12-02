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


int main(int argc, char const *argv[])
{
    pid_t id;
    unsigned char buff[16];
    int fd[2]; //file descriptor
    pipe(fd); //single pipe
    id=fork(); //fork calling

   if(id == 0)
   {
       close(fd[1]); //close writing
       printf("child reading data\n"); 
       read(fd[0],buff,16); //child reading from parent writing
       printf("%s",buff); //prints buffer 
       printf("\nRead on child done successfully\n");

   }
   else
   {
   	close(fd[0]); //close reading
      printf("Parent writing data \n"); 
      write(fd[1],"HELLO WORLD\n",13); //parent writing 
      
   }
    return 0;
}
