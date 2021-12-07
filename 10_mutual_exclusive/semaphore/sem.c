#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>
/*including header file for semaphore*/
#include <semaphore.h>

int count =10;
sem_t semCount;

void *inc_thread (void *arg) 
{
    while(1)
    {
    printf("inc:grabbing semophore\n");
    sem_wait(&semCount); //lock 
    printf("inc:inside semophore CS\n");
    count++;
    printf("In increment thread:%d\n",count);
    printf("inc:releasing semophore\n");
    sem_post(&semCount);  //unlock
    }
    return 0;
}
void *dec_thread (void *arg) 
{
    while(1)
    {
    printf("dec:grabbing semophore\n");
    sem_wait(&semCount); //lock
    printf("dec:inside sem CS\n");
    count--;
    printf("In decrement thread:%d\n",count);
     printf("dec:releasing semophore\n");
    sem_post(&semCount);  //unlock
    
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t decID, incID; //opaque datatype

    printf("main:before calling thread\n");
    sem_init(&semCount,0,1); //initalizing semaphore
    pthread_create(&incID,NULL,inc_thread,NULL); //calling a new thread
    pthread_create(&decID,NULL,dec_thread,NULL); //calling a new thread
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);
    sem_destroy(&semCount); //destroying semaphore
    printf("After calling thread\n");

    return 0;
}
