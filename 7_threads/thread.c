#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>

void *hello_thread (void *arg) 
{
    printf("In Hello thread: HELLO\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t helloID; //opaque datatype

    printf("before calling Hello thread\n");
    pthread_create(&helloID,NULL,hello_thread,NULL); //calling a new thread
    pthread_join(helloID,NULL);
    printf("After calling Hello thread\n");

    return 0;
}

