#include <stdio.h>
/*including shared_memory header files*/
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
/*including ftruncate header files*/
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>

int* count;

int main(int argc, char const *argv[])
{
int shmd;

shmd= shm_open("/WELCOME",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
ftruncate(shmd,sizeof(int));
count = (int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shmd, 0);
while(1)
{
    
    printf("count =%d\n",*count);
    sleep(2);
}
return 0;
}