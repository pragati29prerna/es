
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int *ptr=NULL; //pointing to zero
    printf("Address =%d\n",*ptr); //segmentation fault because zero is the special address
   
    return 0;
}
