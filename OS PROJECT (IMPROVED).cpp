#include<stdio.h>
struct p{
	int pid;
	int priority;
	int burst;
	int arrival;
	int rem_burst;
	int start_time;
	int comp_time;
	int turn_around_time;
	int waiting_time;
	int final_comp_time;
};

main(){
	struct p p[100]; //structure array
	int pid; //process id
	int num; //how many processes
	float ts; //time slice
	int temp=0; //temporary variable
	int burst; //burst time
	int priority;
	int rem_burst; //remaining burst time
	int temp2=0; //temporary variable 2
	int start_time;
	int comp_time; //completion time in a time slice
	int i; //for loops
	int turn_around_time;
	int arrival=0;
	int waiting_time;
	int final_comp_time; //final completion of all processes
	
//====================================================================================================	
    printf("\n************************************************************************************************\n");
	printf("OS PROJECT [An Improved Priority Scheduling Algorithm Tominimize Response Time Using Time Slice]");
	printf("\nMembers : Shahzaib Hamza / Sarfaraz Illahi Soomro");
	printf("\n************************************************************************************************\n");
	 
	 
	//taking input data from user
	printf("\nHOW MANY PROCESSES YOU WANT TO PROCESS?\n");
	scanf("%d",&num);
	
	for(int i=0;i<num;i++){
		printf("enter Arrival Process: ",i);
		scanf("%d",&p[i].pid);
		
		printf("enter burst time for process P%d: ",p[i].pid);
		scanf("%d",&p[i].burst);
		
		printf("enter priority for process P%d: ",p[i].pid);
		scanf("%d",&p[i].priority);
		
		printf("\n");
	}
	//close taking data
//==================================================================================================



	
//=================================================================================================	
	//calculating time slice
//time slice = highest burst_time + lowest burst_time / 2;

//variable declarations;

int lowest=p[0].burst;
int highest=p[0].burst;

//finding lowest and highest numbers of burst time in n number of processes
for(int i = 0; i < num; i++) {
        		if(p[i].burst>highest)
			highest=p[i].burst;
		else
                {
			if(p[i].burst<lowest)
				lowest=p[i].burst;
		}
		}
printf("\n\n============Time Slice=============\n");	
	printf("\nHighest Burst Time is:  %d",highest);
	printf("\nLowest Burst Time iS:  %d",lowest);
	
//calculating time slice;
float sum=highest+lowest;
ts=sum/2;

printf("\nTime Slice will be %.2f for this data\n",ts); //%.2f used for restrict only 2 values to print after point
printf("\n=========================================\n\n");
//=================================================================================================





//=================================================================================================	
	//setting priorities
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			if(p[i].priority<p[j].priority){
			    temp=p[i].pid;      //wrt process id
				p[i].pid=p[j].pid;
				p[j].pid=temp;
			
				temp=p[i].burst;    //wrt burst time
				p[i].burst=p[j].burst;
				p[j].burst=temp;
				
				temp=p[i].priority;  //wrt priority
				p[i].priority=p[j].priority;
				p[j].priority=temp;
			}
		}
	}
	//close setting priorities
//=================================================================================================



	
	
//=================================================================================================	
//burst reamining code	
for(i=0;i<num;i++){
	p[i].rem_burst=p[i].burst-ts;}	


for(i=0;i<num;i++){
	if(p[i].rem_burst<0){
		p[i].rem_burst= -p[i].rem_burst;
	}
printf("",p[i].pid,p[i].rem_burst);
}


	for(i=0;i<num;i++){
		temp+=ts;
		
		
		if(p[i].burst>ts)
		{
		printf("",temp);
		}
		if(p[i].burst<ts)
		{
			temp2=temp-p[i].rem_burst-ts;
			printf("",temp2);
		}
		}
	//burst reamining done	
//===============================================================================================


		


//===============================================================================================
//time slice run logic
 int result;
 p[0].comp_time=ts;
 printf("",p[0].comp_time);
for(i=1;i<num;i++){
	p[i].comp_time=p[i-1].comp_time+ts;
}
for(i=0;i<num;i++){
	printf("",p[i].pid,p[i].comp_time);
}
//===============================================================================================





//===============================================================================================
//print completion time;
printf("",p[0].pid,p[0].comp_time);
for(i=1;i<num-1;i++){
	p[i].final_comp_time=p[i].comp_time-p[i].rem_burst;
	printf("",p[i].pid,p[i].final_comp_time);}
	printf("",p[4].pid,p[4].comp_time-ts);
p[4].comp_time=p[4].comp_time-ts;
//done with time slice run logic
//==============================================================================================




//==============================================================================================
//start time for turn around time
p[0].start_time=0;
p[1].start_time=p[0].comp_time;
	printf("",p[0].pid,p[0].start_time);
    printf("",p[1].pid,p[1].start_time);	
for(i=2;i<num;i++){
	p[i].start_time=p[i-1].comp_time-p[i-1].rem_burst;
	printf("",p[i].pid,p[i].start_time);
}
//done with start time
//=============================================================================================




//=============================================================================================
//turn around time
for(i=0;i<num;i++){
	p[i].arrival=0;
}
p[4].final_comp_time=p[4].comp_time-ts;
p[0].final_comp_time=ts;

for(i=0;i<num;i++){
p[i].turn_around_time=p[i].final_comp_time-p[i].arrival;
printf("",p[i].turn_around_time);	
}
//done TAT
//================================================================================================




//================================================================================================
//for completion time after running time slice once
for(i=0;i<num;i++){
	if(result>p[i].burst){
		printf("",p[i].final_comp_time);
	}
}
//done
//=================================================================================================





//=================================================================================================
//waiting time

for(i=0;i<num;i++){
//wrt WT=TAT-BT
	p[i].waiting_time=p[i].turn_around_time-p[i].burst;
	if(p[i].waiting_time<0) { p[i].waiting_time=0;} //if value is negative it means process dont have to wait
	}

//done with waiting time
//=================================================================================================





//=================================================================================================
//printing results in table form
printf("\n\n======================Result=====================\n");
printf("Pid\tAT\tBT\tCT\tWT\tTAT\tRT");
printf("\n=======================================================");
printf("\n");

for(i=0;i<num;i++){
printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].final_comp_time,p[i].waiting_time,p[i].turn_around_time,p[i].start_time);
}
//done printing
//==================================================================================================




//==================================================================================================
//calcaulate sum of totals
//var declarations
int avg_TAT,avg_RT,avg_WT;
int total_WT,total_RT,total_TAT;

for(i=0;i<num;i++){
	total_WT+=p[i].waiting_time;
}
for(i=0;i<num;i++){
	total_RT+=p[i].start_time;
}
for(i=0;i<num;i++){
	total_TAT+=p[i].turn_around_time;
}

//formulas for averages
avg_TAT=total_TAT/num;
avg_RT=total_RT/num;
avg_WT=total_WT/num;

//printing averages
printf("\n\n===========Averages===========\n");
printf("\n Average Response Time Is %d",avg_RT);
printf("\n Average Waitime Time Is %d",avg_WT);
printf("\n Average Turn Around Time Is %d",avg_TAT);
//==================================================================================================


}//main close







