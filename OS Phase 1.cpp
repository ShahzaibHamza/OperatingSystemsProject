//os project p1
//shahzaib hamza
//sarfaraz soomro

#include <iostream> //standard input output stream
#include <algorithm>  //allow for sorting searching etc
#include <iomanip> //manupulating the output
#include <string.h>  //string usability
using namespace std;

struct process {
    int pno;  //process id
    int atime; //arrival time
    int btime; //burst time
    int priority; //priority
    int c_time; //completion time
    int t_time; //turn around time
    int w_time; //waiting time
    int r_time; //response time
    int start_time; //when process started
};
//=====================================================================================================//

int main() {
printf("----OS Project Phase 1----(Shahzaib Hamza/Sarfaraz Soomro)\n\n");


    int num;
    int tit=0; //idle time of cpu when no process enter 
    struct process p[100]; //max 100
    float avg_tatime; //avg turn around time
    float avg_wtime; //avg waiting time 
    float avg_rtime; //avg respose time
    int total_ttime = 0; //total turn around time
    int total_wtime = 0; //total waiting time
    int total_rtime = 0; //total response time
    int burst_remaining[100]; //remaining burst time for premptive
    int is_completed[100]; //check process completion
    memset(is_completed,0,sizeof(is_completed)); //memset is used to fill a block of memory with a particular value.

//========================================================================================================//
//input processes and details of processes

 printf("how many processes you want to process: \n");
    scanf("%d",&num);

    for(int i = 0; i < num; i++) {
      
        printf("Enter Arrial Time Of Process %d: ",i+1);
        scanf("%d",&p[i].atime);
        
        printf("Enter Burst Time Of Process %d: ",i+1);
        scanf("%d",&p[i].btime);
        
        printf("Enter priority Time Of Process %d: ",i+1);
        scanf("%d",&p[i].priority);
        
        p[i].pno=i+1;
        burst_remaining[i] = p[i].btime;
        printf("\n");
        
    }
//=========================================================================================================//
//main Logic

 int cur_time = 0; //current time of proces
    int cmpltd = 0; //process completed
    int prev = 0; //previous process

    while(cmpltd != num) {
        int idc = -1; //current process id
        int max = -1; //max priority process id
       
	    for(int i = 0; i < num; i++) {
            if(p[i].atime <= cur_time && is_completed[i] == 0) {
                if(p[i].priority > max) {
                    max = p[i].priority;
                    idc = i;
                }
                if(p[i].priority == max) {
                    if(p[i].atime < p[idc].atime) {
                        max = p[i].priority;
                        idc = i;
                    }
                }
            }
        }

        if(idc != -1) {
            if(burst_remaining[idc] == p[idc].btime) {
                p[idc].start_time = cur_time;
                tit += p[idc].start_time - prev;
            }
            burst_remaining[idc] -= 1;
            cur_time++;
            prev = cur_time;
            
            if(burst_remaining[idc] == 0) {
                p[idc].c_time = cur_time;
                p[idc].t_time = p[idc].c_time - p[idc].atime;
                p[idc].w_time = p[idc].t_time - p[idc].btime;
                p[idc].r_time = p[idc].start_time - p[idc].atime;

                total_ttime += p[idc].t_time;
                total_wtime += p[idc].w_time;
                total_rtime += p[idc].r_time;

                is_completed[idc] = 1;
                cmpltd++;
            }
        }
        else {
             cur_time++;
        }  
    }
	//===============================================================================================================
	//formulas
	avg_tatime = total_ttime / num; //calculating average turn around time
    avg_wtime =(float) total_wtime / num;  //calculating average waiting timr
    avg_rtime = total_rtime / num;  //calculating average response time
    
    //===============================================================================================================
	//printing Output table
	printf("\n\t\t\t\t==Output Table==\n");
	printf("\npid\tAT\tBT\tPR\tCT\tTAT\tWT\tRT");
	 for(int i = 0; i < num; i++) {
    printf("\n");  
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].atime,p[i].btime,p[i].priority,p[i].c_time,p[i].t_time,p[i].w_time,p[i].r_time);
	printf("\n");
	}
	
	//================================================================================================================
	//Final Output
	printf("\n\t\t\t\t==Averages==\n");
	printf("Average Waiting Time: %f\n",avg_wtime);
	printf("Average Response Time: %f\n",avg_rtime);
	printf("Average Turn Around Time: %f\n",avg_tatime);
	}//main end 
