#include<stdio.h>


int main(){
	int alloc[5][3],max[5][3],need[5][3],available[3],request[3],completed[5],safe_sequence[5];
	int n,r,i,j,process_no,count = 0,process;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter number of resource types: ");
	scanf("%d",&r);
	
	printf("\nEnter the Allocation for each Process\n");
	for(i=0;i<n;i++){
		printf("Enter resources for Process %d: ",i);
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	
	printf("\nEnter the Max for each Process\n");
	for(i=0;i<n;i++){
		printf("Enter resources for Process %d: ",i);
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("Enter available resources: ");
	for(i=0;i<r;i++){
		scanf("%d",&available[i]);
	}
	
	printf("Enter process number making request: ");
	scanf("%d",&process_no);
	
	printf("Enter request: ");
	for(i=0;i<r;i++){
		scanf("%d",&request[i]);
		available[i]-=request[i];
		alloc[process_no][i]+=request[i];
	}
	
	//need matrix
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	
	
	//printing all the matrix
	printf("Max matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			printf("%d ",max[i][j]);
		}
		printf("\n");
	}
	printf("Allocation matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			printf("%d ",alloc[i][j]);
		}
		printf("\n");
	}
	printf("Need matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	
	
	for(i=0;i<n;i++){
		completed[i]=0;
	}
	
	do{
		process = -1;
		for(i=0;i<n;i++){
			if (completed[i]==0){
				process = i;
				for(j=0;j<r;j++){
					if(available[j]<need[i][j]){
						process = -1;
						break;
					}
				}
				if(process != -1)
					break;
			}
		}
		if(process != -1){
			safe_sequence[count]=process;
			count++;
			printf("Process %d has completed its execution\n",process);
			printf("Avaiable=");
			for(i=0;i<r;i++){
				available[i]+= alloc[process][i];
				printf("%d",available[i]);
				max[process][i]=0;
				alloc[process][i]=0;
				completed[process]=1;
			}
			printf("\n");
		}
	}while(count != n && process != -1);
	if(count==n){
		printf("The system is in safe state and resource can be grantd immediately.\n");
		printf("Safe sequnce: <");
		for(i=0;i<n;i++){
			printf("%d ",safe_sequence[i]);
		}
		printf(">\n");
	}
	else{
		printf("The system is not in safe state and the request cannot be granted immediately.\n");
	}
	
}