#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//process definition.
#define n 5
typedef struct block{
    int pid;
    int at;
    int bt;
    int completed;
    int inqueue;
}process;
process processq[n];
process readyq[n];
//process queue construction.
int front=0;
int rear=-1;
void enqueue(process p){
    if(rear>=n-1){
        printf("Invalid Queueing");
        return;
    }
    else{
        rear++;
        readyq[rear]=p;
        for(int i=0;i<n;i++){
            if(p.pid=processq[i].pid){
                processq[i].inqueue=1;
            }
        }
    }
}
process dequeue(){
    process temp=readyq[front];
        for(int i=0;i<n;i++){
            if(processq[i].pid=temp.pid){
                processq[i].inqueue=0;
                temp.inqueue=0;
            }
        }
        for(int i=0;i<rear-1;i++){
            readyq[i]=readyq[i+1];
        }
        rear--;
        return temp;
}
int main(){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        processq[i].pid=i;
        printf("PID: %d |",processq[i].pid);
        processq[i].at=rand()%10;
        printf("AT: %d |",processq[i].at);
        processq[i].bt=1+rand()%10;
        printf("BT: %d |",processq[i].bt);
        processq[i].completed=0;
        printf("Completed: %d |",processq[i].completed);
        processq[i].inqueue=0;
        printf("\n");
    }
    int time=0;
    int timeslice=2;
    int occupied=0;
    process running;
    while(time<200){
        for(int i=0;i<n;i++){
            if(processq[i].at<=time&&(rear<n-1)&&processq[i].completed==0&&running.pid!=processq[i].pid&&processq[i].inqueue==0){
                enqueue(processq[i]);
            }
        }
        if(rear>=0&&occupied<=time){
            running=dequeue();
            for(int i=0;i<n;i++){
                if(running.pid==processq[i].pid){
                    if(running.bt>timeslice){
                        processq[i].bt=processq[i].bt-timeslice;
                        processq[i].at=time+timeslice;
                        printf("Time: %d: Process %d ran for %d units before preempting.\n",time,processq[i].pid,timeslice);
                        occupied=time+timeslice;
                        enqueue(processq[i]);
                        break;
                    }
                    else{
                        processq[i].completed=1;
                        printf("Time: %d: Process %d ran for %d units and completed.\n",time,processq[i].pid,processq[i].bt);
                        occupied=time+processq[i].bt;
                        break;
                    }
                }
            }
        }
        time++;
    }
    return 0;
}