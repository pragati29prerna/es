#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr=0x4000; //pointing to specific address
    
    ptr= (int *)malloc(sizeof(int) * 10); //allocating memory
    printf("Address =%d\n",*ptr);
    
    free(ptr); //free the allocated memory
    return 0;
}
