#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>

int count =10; //global variable count
pthread_mutex_t mutexCount; //opaque datatype

void *inc_thread (void *arg) 
{
    while(1)
    {
    pthread_mutex_lock(&mutexCount); //lock 
    count++;
    printf("In increment thread:%d\n",count);
    pthread_mutex_unlock(&mutexCount); //unlock
    }
    return 0;
}
void *dec_thread (void *arg) 
{
    while(1)
    {
    pthread_mutex_lock(&mutexCount); //lock
    count--;
    printf("In decrement thread:%d\n",count);
    pthread_mutex_unlock(&mutexCount); //unlock
    return 0;
    }
}

int main(int argc, char const *argv[])
{
    pthread_t decID, incID; //opaque datatype

    printf("main:before calling thread\n");
    pthread_mutex_init(&mutexCount,NULL); //initailize mutex
    pthread_create(&incID,NULL,inc_thread,NULL); //calling a new thread
    pthread_create(&decID,NULL,dec_thread,NULL); //calling a new thread
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);
    pthread_mutex_destroy(&mutexCount); // destroy mutex
    printf("main:After calling thread\n");

    return 0;
}
