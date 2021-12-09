
#include <stdio.h>
/*including thread header file*/
#include <pthread.h>

void *I2C_thread(void *arg)
{
    printf("Init:I2C\n");
    sleep(2);
    printf("finish:I2C\n");
}
void *SERIAL_thread(void *arg)
{
    printf("Init:SERIAL\n");
    sleep(6);
    printf("finish:SERIAL\n");
}
void *ADC_thread(void *arg)
{
    printf("Init:ADC\n");
    sleep(4);
    printf("finish:ADC\n");
}

int main(int argc, char const *argv[])
{
    pthread_t I2C,SERIAL,ADC;

    pthread_create(&I2C,NULL,I2C_thread,NULL); //create new I2C thread
    pthread_create(&SERIAL,NULL,SERIAL_thread,NULL);//create new SERIAL thread
    pthread_create(&ADC,NULL,ADC_thread,NULL);//create new ADC thread
    pthread_join(I2C,NULL); //join I2C thread
    pthread_join(SERIAL,NULL);//join SERIAL 
    pthread_join(ADC,NULL);//join ADC
    return 0;
}

