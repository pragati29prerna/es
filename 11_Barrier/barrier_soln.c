

#include <stdio.h>
/*including thread header file*/
#include <pthread.h>
#include<unistd.h>

pthread_barrier_t barrier; //opaque datatype

void *I2C_thread(void *arg)
{
    printf("Init:I2C\n");
    sleep(2);
    pthread_barrier_wait(&barrier); //barrier wait to finish all the threads together
    printf("finish:I2C\n");
}
void *SERIAL_thread(void *arg)
{
    printf("Init:SERIAL\n");
    sleep(6);
    pthread_barrier_wait(&barrier);//barrier wait
    printf("finish:SERIAL\n");
}
void *ADC_thread(void *arg)
{
    printf("Init:ADC\n");
    sleep(4);
    pthread_barrier_wait(&barrier);//barrier wait
    printf("finish:ADC\n");
}

int main(int argc, char const *argv[])
{
    pthread_t I2C,SERIAL,ADC; //opaque datatype

    pthread_barrier_init(&barrier,NULL,3); //initalize barrier
    pthread_create(&I2C,NULL,I2C_thread,NULL);//create new I2C thread
    pthread_create(&SERIAL,NULL,SERIAL_thread,NULL);//create new SERIAL thread
    pthread_create(&ADC,NULL,ADC_thread,NULL);//create new ADC thread
    //join threads
    pthread_join(I2C,NULL);
    pthread_join(SERIAL,NULL);
    pthread_join(ADC,NULL);
    return 0;
}
