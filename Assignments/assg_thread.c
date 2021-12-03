#include <stdio.h>
/*including header file for thread*/
#include <pthread.h>

void *hello_thread (void *arg) 
{
    printf("In Hello_thread: HELLO\n");
    return 0;
}
void *bye_thread (void *arg) 
{
    printf("In bye_thread: BYE\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t helloID; //opaque datatype
    pthread_t ByeID;

    printf("****before calling Hello thread****\n");
    pthread_create(&helloID,NULL,hello_thread,NULL); //calling a new thread
    pthread_join(helloID,NULL);
    printf("****After calling Hello thread****\n");
    
    printf("****before calling Bye thread****\n");
    pthread_create(&ByeID,NULL,bye_thread,NULL); //calling a new thread
    pthread_join(ByeID,NULL);
      printf("****After calling bye thread****\n");

    return 0;
}
