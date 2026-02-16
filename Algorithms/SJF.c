#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
//process structure
typedef struct block{
        int pid;
        int at;
        int bt;
        int complete;
    }process;
//process and running state
process processq[5];
process running;
int main(){
    srand(time(NULL));
        for(int i=0;i<5;i++)
        {
            processq[i].pid=i;
            printf("| PID- %d |",processq[i].pid);
            processq[i].at=rand()%10;
            printf(" AT- %d |",processq[i].at);
            processq[i].bt=1+rand()%10;
            printf(" BT- %d |",processq[i].bt);
            processq[i].complete=0;
            printf("\n");
        }
        int time=0;
        int flag;
        //Comparison integer
        int small;
        while(time<100){
            flag=0;
            //Comparison
            small=INT_MAX;
            for(int i=0;i<5;i++){
                if(processq[i].at<=time&&processq[i].bt<=small&&processq[i].complete==0){
                    flag=1;
                    small=processq[i].bt;
                    running=processq[i];
                }
            }
            if(flag!=0){
                printf("Process %d completed at %d units\n",running.pid,time+running.bt);
                for(int i=0;i<5;i++){
                if(processq[i].pid==running.pid){
                    processq[i].complete=1;
                    time=time+running.bt-1;
                }
            }
            }
            time++;
        }
    return 0;
}