#include<stdio.h>
struct process{
	char pname[10];
	int bt,rt,wt,tt;
}p[10],t;

void main(){
	int t[15];
	int temp,tq,n,i;
	int count,sq,times=0;
	float sum=0.0,sum1=0.0;
	printf("Enter the value for quantum time: ");
	scanf("%d",&tq);
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the process number: ");
		scanf("%s",&p[i].pname);
		printf("Enter burst time: ");
		scanf("%d",&p[i].bt);
	}
	for(i=0;i<n;i++){
		p[i].rt=p[i].bt;
	}
	printf("Gantt chart: \n");
	sq=0;
	while(1){
		for(i=0,count=0;i<n;i++){
			temp = tq;
			if(p[i].rt==0){
				count++;
				continue;
			}
			else{
				if(p[i].rt>=tq){
					p[i].rt=p[i].rt-tq;
				}
				else if(p[i].rt>0){
					temp=p[i].rt;
					p[i].rt=0;
				}
				t[times++]=sq;
				sq+=temp;
				p[i].tt=sq;
			}
			printf("   p%s\t",p[i].pname);
			t[times]=sq;
		}
		if(count==n)
			break;
	}
		for(i=0;i<n;i++){
			p[i].wt=p[i].tt-p[i].bt;
			sum=sum+p[i].wt;
			sum1=sum1+p[i].tt;
		}
		printf("\n");
		printf("0\t");
		for(i=1;i<=times;i++)
		{
			printf("%d\t",t[i]);
		}
	printf("\nThe average waiting time=%f",sum/n);
	printf("\nThe average turn around time=%f",sum1/n);
}