#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>

int count =10;

void *inc_thread (void *arg) 
{
    while(1)
    {
    count++;
    printf("In increment thread:%d\n",count);
    }
    return 0;
}
void *dec_thread (void *arg) 
{
    while(1)
    {
    count--;
    printf("In decrement thread:%d\n",count);
    return 0;
    }
}

int main(int argc, char const *argv[])
{
    pthread_t decID, incID; //opaque datatype

    printf("before calling thread\n");
    pthread_create(&incID,NULL,inc_thread,NULL); //calling a new thread
    pthread_create(&decID,NULL,dec_thread,NULL); //calling a new thread
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);
    printf("After calling thread\n");

    return 0;
}
