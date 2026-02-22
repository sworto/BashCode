#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define timeslice 2
//Process Definition
typedef struct block{
    int pid;
    int at;
    int bt;
    int completed;
    int inqueue;
}process;
//process and ready queue construction.
process processq[N];
process* readyq[N];
int front=0;
int rear=-1;
int size=0;
void enqueue(process* p){
    if(size==N){
        printf("Invalid Queueing\n");
        return;
    }
    else{
        rear=(rear+1)%N;
        readyq[rear]=p;
        p->inqueue=1;
        size++;
        return;
    }
}
process* dequeue(){
    if(size==0){
        printf("Invalid Dequeue\n");
        return NULL;
    }
    else{
        process* temp=readyq[front];
        temp->inqueue=0;
        front=(front+1)%N;
        size--;
        return temp;
    }
}
int main(){
    srand(time(NULL));
    for(int i=0;i<N;i++){
        processq[i].pid=i;
        printf("PID: %d |",processq[i].pid);
        processq[i].at=rand()%10;
        printf("AT: %d |",processq[i].at);
        processq[i].bt=1+rand()%10;
        printf("BT: %d |",processq[i].bt);
        processq[i].completed=0;
        //printf("Completed: %d |",processq[i].completed);
        processq[i].inqueue=0;
        printf("\n");
    }
    process* running=NULL;
    int flag;
    int time=0;
    int occupied=0;
    while(1){
        if(occupied==time&&running){
            if(running->bt==0){
                running->completed=1;
                printf("Process %d completed at %d Time\n",running->pid,time);
                running=NULL;
            }
            else{
                running->completed=0;
                printf("Process %d preempted at %d Time\n",running->pid,time);
                running=NULL;
            }
        }
        flag=0;
        for(int i=0;i<N;i++){
            if(processq[i].at<=time&&processq[i].completed==0&&processq[i].inqueue==0){
                enqueue(processq+i);
            }
            if(processq[i].completed==0){
                flag=1;
            }
        }
        if(flag==0){
            printf("Completed\n");
            break;
        }
        if(!running&&size!=0){
            running=dequeue();
            if(running){
                running->inqueue=0;
                if(running->bt>timeslice){
                    running->bt=running->bt-timeslice;
                    occupied=time+timeslice;
                    running->at=occupied;
                }
                else{
                    occupied=time+running->bt;
                    running->bt=0;
                    running->at=occupied;
                }
            }
        }
    time++;
    }
    return 0;
}