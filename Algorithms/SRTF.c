#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 5
//Process Definition
typedef struct block{
    int pid;
    int at;
    int bt;
    int completed;
}process;
//process and ready queue construction.
process processq[N];
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
        printf("\n");
    }
    process* running=NULL;
    int time=0;
    int occupied=0;
    int smallest;
    int flag;
    while(1){
        smallest=INT_MAX;
        flag=0;
        for(int i=0;i<N;i++){
            if(processq[i].at<=time&&!running&&processq[i].completed==0&&processq[i].bt<smallest){
                smallest=processq[i].bt;
                running=(processq+i);
            }
            if(processq[i].completed==0){
                flag=1;
            }
        }
        if(flag==0){
            printf("Completed!!\n");
            break;
        }
        if(running){
            running->bt=(running->bt)-1;
        }
        if(running&&running->bt==0){
            printf("Time %d: Process %d completed.\n",time+1,running->pid);
            running->completed=1;
            running=NULL;
        }
        if(running&&running->bt>0){
            printf("Time %d: Process %d preempted.\n",time+1,running->pid);
            running->completed=0;
            running=NULL;
        }
        time++;
    }
    return 0;
}