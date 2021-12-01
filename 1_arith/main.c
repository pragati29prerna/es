/*including the standard header file and user defined header file*/

#include<stdio.h>
#include"arith.h"


int main(int argc, char const *argv[])
{
    int result=0;//initialize the local variable

    result=add(40,50); //calling add function
    printf("Addition =%d\n",result);

    result=sub(100,50);//calling sub function
    printf("Substraction =%d\n",result);

    return 0;
}
