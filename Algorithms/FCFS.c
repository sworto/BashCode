#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//PCB Structure
typedef struct block{
    int pid;
    int at;
    int bt;
    int complete;
}process;
//Processes and the Readyq Declaration
process processq[5];
process readyq[5];
process running;
//Enqueue and dequeue operations
int front=0;
int rear=-1;
void enqueue(process current)
{
    rear++;
    readyq[rear]=current;
}
process dequeue()
{
    process out=readyq[front];
    for(int i=1;i<5;i++)
    {
        readyq[i-1]=readyq[i];
    }
    rear--;
    return out;
}
int main(){
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        processq[i].pid=i;
        printf("| PID- %d |",processq[i].pid);
        processq[i].at=rand()%10;
        printf(" AT- %d |",processq[i].at);
        processq[i].bt=rand()%10;
        printf(" BT- %d |",processq[i].bt);
        processq[i].complete=0;
        printf("\n");
    }
    int time=0;
    int occupied=0;
    int completion=time;
    int flag;
    while(1)
    {
        flag=0;
        for(int i=0;i<5;i++)
        {
            if(processq[i].complete==0)
            {
                flag=1;
            }
            if(processq[i].at==time)
            {
                enqueue(processq[i]);
            }
        }
        if(completion<=time&&occupied==0&&rear!=-1)
        {
            occupied=1;
            running=dequeue();
            completion=time+running.bt;
            printf("Process %d completed at %d units\n",running.pid,completion);
            for(int i=0;i<5;i++)
            {
                if(running.pid==processq[i].pid)
                {
                    processq[i].complete=1;
                }
            }
        }
        if(completion==time&&occupied==1)
        {
            occupied=0;
        }
        if(flag==0)
        {
            printf("End process.\n");
            break;
        }
        time++;
    }
    return 0;
}