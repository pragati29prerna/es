#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>
/*including header file for semaphore*/
#include <semaphore.h>

int a,b,sum;
sem_t semCount;

void *input_thread (void *arg) 
{
    
    sem_wait(&semCount); //lock 
    printf("enter the number a:"); //user input
    scanf("%d",&a);
    printf("enter the number b:"); //user input
    scanf("%d",&b);
    sem_post(&semCount);  //unlock
   
    return 0;
}
void *add_thread (void *arg) 
{
    
    sem_wait(&semCount); //lock
    sum=a+b;
    printf("The sum is:%d\n",sum); //sum value
    sem_post(&semCount);  //unlock   
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t addID, inputID; //opaque datatype

    printf("Main:before calling thread\n");
    sem_init(&semCount,0,1); //initalizing semaphore
    pthread_create(&inputID,NULL,input_thread,NULL); //calling a new thread
    pthread_create(&addID,NULL,add_thread,NULL); //calling a new thread
    pthread_join(inputID,NULL);
    pthread_join(addID,NULL);
    sem_destroy(&semCount); //destroying semaphore
    printf("Main:After calling thread\n");

    return 0;
}
