#include <stdio.h>
/*msg queue header*/
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>


char buff[128];
int msg_prio;
int main(int argc, char const *argv[])
{

mqd_t mqueue; //opaque datatype for msg_queue

struct mq_attr myqueue_attr; //message queue attributes

myqueue_attr.mq_flags = 0; /* Flags (ignored for mq_open()) */
myqueue_attr.mq_maxmsg =4;  /* Max. # of messages on queue */
myqueue_attr.mq_msgsize =128; /* Max. message size (bytes) */
myqueue_attr.mq_curmsgs =0; /* # of messages currently in queue (ignored for mq_open()) */

mqueue= mq_open("/mqueue",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&myqueue_attr); //Open the queue to receive messages only.

mq_receive(mqueue,buff,128,&msg_prio); //recieved data from prog 1
printf("msg_prio =%d & buff=%s\n",msg_prio,buff); //print received data

mq_close(mqueue); //close message queue
   return 0;
}
