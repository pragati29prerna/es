
/*including standard header file*/
#include <stdio.h>
/*including header files for open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*including header file for write*/
#include <unistd.h>
/*including header file for close*/
#include<stdlib.h>
#define SIZE 16

int main(int argc, char const *argv[])
{
    pid_t id;
    unsigned char send[SIZE], receive[SIZE];
    int fd[2]; // (file descriptors) fd[0]->read, fd[1]->write
    int fdr[2]; //(file descriptors) fdr[0]->read, fdr[1]->write
    pipe(fd); //1st pipe
    pipe(fdr); //2nd pipe
    id=fork(); //fork calling

   if(id == 0)
   {
       /*child receiving data*/
       close(fd[1]); //close writing
       read(fd[0],receive,SIZE); //child reading from parent written data
       printf("child reading data: %s",receive); 
       printf("Read on child done successfully\n");
       close(fd[0]); //close reading

       /*child sending data*/
      close(fdr[0]); //close reading
      printf("child writing data \n"); 
      write(fdr[1],"BYE WORLD\n",SIZE); //child writing
      close(fdr[1]); //close writing

   }
   else
   {
      /*parent sending data*/
   	  close(fd[0]); //close reading
      printf("Parent writing data \n"); 
      write(fd[1],"HELLO WORLD\n",SIZE); //parent writing 
      close(fd[1]); //close writing

       /*parent receiving data*/
       
       close(fdr[1]); //close writing
       read(fdr[0],send,SIZE); //parent reading from child written data
       printf("parent read the data:%s",send); 
       printf("Read on parent done successfully\n");
       close(fdr[0]); //close reading
      
   }
    return 0;
}
