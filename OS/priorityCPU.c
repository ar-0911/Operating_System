#include<stdio.h>

struct process{

    int num;

    int burst_time;

    int priority;

    int waiting_time;

    int taround_time;

};



struct process read(int i){

    struct process p;

    printf("\nFor process no: %d\n",i);

    p.num = i;

    printf("Enter burst time: ");

    scanf("%d",&p.burst_time);

    printf("Enter priority: ");

    scanf("%d",&p.priority);

    return p;

};



int main(){

    struct process p[10], temp;

    int n, gantt_time[10];

    float avg_taround_time = 0.0;

    float avg_waiting_time=0.0;

    printf("Enter number of processes: ");

    scanf("%d",&n);



    int i,j;

    for(i=0;i<n;i++){

        p[i] = read(i);

    }



    //arranging them in the array based on their PRIORITY

    for(i=0;i<n;i++){

        for(j=i;j<n;j++){

            if(p[i].priority > p[j].priority){

                temp=p[i];

                p[i]=p[j];

                p[j]=temp;

            }

        }

    }



    //calculating gantt chart chart time

    gantt_time[0] = 0; //gantt chart time for p[0] is 0

    for(i=0;i<n;i++){

        gantt_time[i+1] = gantt_time[i] + p[i].burst_time;

    }



    //calculating waiting time and turn around time for each process

    //wt = lsv - at

    //tat = wt + bt

    for(i=0;i<n;i++){

        p[i].waiting_time = gantt_time[i];

        p[i].taround_time = p[i].waiting_time + p[i].burst_time;

    }


	printf("\n");
    printf("+-------------+-------------------+-----------------+------------------+-------------------------+\n");

    printf("|   process   |      priority     |   burst time    |    waiting time  |    turn around time     |\n");
    printf("|-------------|-------------------|-----------------|------------------|-------------------------|\n");



    for(i=0;i<n;i++){

       printf("|     p%d      |       %02d          |       %02d        |        %02d        |          %02d             |\n",p[i].num,p[i].priority,p[i].burst_time,p[i].waiting_time,p[i].taround_time);

    }



    printf("+-------------+-------------------+-----------------+------------------+-------------------------+\n");



    //calculating average waiting time and average turn around time

    for(i=0;i<n;i++){

        avg_waiting_time += p[i].waiting_time;

        avg_taround_time += p[i].taround_time;

    }

    avg_waiting_time /= n;

    avg_taround_time /= n;
    
    printf("\nGANTT CHART\n\n");
    for(i=0;i<n;i++){
    	printf("\tp[%d]\t",p[i].num);
	}
	printf("\n");
	printf("0");
	for(i=1;i<n;i++){
		printf("\t\t%d",gantt_time[i]);
	}
	int last_time = gantt_time[n-1]+p[n-1].burst_time;
	printf("\t\t%d",last_time);

    printf("\n\nThe Average waiting time is: %f\n", avg_waiting_time);

    printf("The Average turn around time is: %f\n",avg_taround_time);

    return 0;

}

