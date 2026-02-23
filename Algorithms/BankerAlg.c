#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
typedef struct block{
    int pid;
    int allocated;
    int needed;
    int finished;
}process;
process p[10];

//This is how martin scorsese felt writing the wolf of wall street 
int* sequence(int* array,int size){
    int flag;
    int temp;
    for(int i=0;i<size;i++){
        flag=0;
        while(flag==0){
            temp=rand()%size;
            if(i==0){
                flag=1;
            }
            for(int j=0;j<i;j++){
                flag=1;
                if(array[j]==temp){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                array[i]=temp;
                break;
            }
        }
    }
    return array;
}

int main(){
    //Function seeding:
    srand(time(NULL));

    //Declaration and initialisation:
    int resources=INT_MIN;
    for(int i=0;i<10;i++){
        p[i].pid=i;
        p[i].allocated=rand()%11;
        p[i].needed=10-p[i].allocated;
        if(p[i].needed>resources){
            resources=p[i].needed;
        }
        p[i].finished=0;
        printf("PID: %d | Allocated: %d | Needed: %d | Finished: %d |\n",p[i].pid,p[i].allocated,p[i].needed,p[i].finished);
    }
    //Total available resources:
    resources=1;
    printf("Total Avl Free Resources: %d\n\n",resources);

    //Checking for each sequence.
    int count=0;
    int flag=0;
    process copy[10];
    int resourcecopy;
    while(count<1000&&flag==0){
        if(count%100==0&&count!=0){
            resources++;
            printf("Too Little Resources!!\n\n");
        }
        //Initialisation
        resourcecopy=resources;
        int* seq=(int *)malloc(10*sizeof(int));
        seq=sequence(seq, 10);
        for(int i=0;i<10;i++){
            copy[i].pid=p[i].pid;
            copy[i].allocated=p[i].allocated;
            copy[i].needed=p[i].needed;
            copy[i].finished=p[i].finished;
        }

        //Printing
        printf("Sequence %d: ",count);
        for(int i=0;i<10;i++){
            if(i==9){
                printf("%d\n",seq[i]);
            }
            else printf("%d->",seq[i]);
        }

        //Checking
        for(int i=0;i<10;i++){
            if((p[seq[i]].needed)>resourcecopy){
                printf("Invalid!!\n\n");
                break;
            }
            else{
                resourcecopy=resourcecopy+copy[seq[i]].allocated;
                copy[seq[i]].needed=0;
                copy[seq[i]].allocated=0;
                copy[seq[i]].finished=1;
                flag=1;
            }
        }
        count++;
    }
    printf("Final State: \n");
    for(int i=0;i<10;i++){
        printf("PID: %d | Allocated: %d | Needed: %d | Finished: %d |\n",copy[i].pid,copy[i].allocated,copy[i].needed,copy[i].finished);
    }
    return 0;
}
