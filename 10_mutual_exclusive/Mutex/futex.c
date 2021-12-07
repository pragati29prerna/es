#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>

int count =10;
pthread_mutex_t mutexCount;

void square()
{
    printf("grabbing:function calling\n");
    pthread_mutex_lock(&mutexCount);
    printf("calling funt:Inside mutex CS\n");
    count =count *count;
    printf("releasing:function calling\n");
    pthread_mutex_unlock(&mutexCount);
}

void *inc_thread (void *arg) 
{
    while(1)
    {
    printf("inc:grabbing mutex\n");
    pthread_mutex_lock(&mutexCount); //lock
    printf("inc:inside mutex CS\n");
    count++;
    square();  //calling function
    printf("In increment thread:%d\n",count);
    printf("inc:releasing mutex\n");
    pthread_mutex_unlock(&mutexCount); //unlock
    }
    return 0;
}
void *dec_thread (void *arg) 
{
    while(1)
    {
    printf("dec:grabbing mutex\n");
    pthread_mutex_lock(&mutexCount); //lock
    printf("dec:inside mutex CS\n");
    count--;
    printf("In decrement thread:%d\n",count);
     printf("dec:releasing mutex\n");
    pthread_mutex_unlock(&mutexCount);  //unlock
    
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t decID, incID; //opaque datatype

    printf("before calling thread\n");
    pthread_mutex_init(&mutexCount,NULL);
    pthread_create(&incID,NULL,inc_thread,NULL); //calling a new thread
    pthread_create(&decID,NULL,dec_thread,NULL); //calling a new thread
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);
    pthread_mutex_destroy(&mutexCount);
    printf("After calling thread\n");

    return 0;
}
