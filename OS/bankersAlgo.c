#include <stdio.h>
int main() {
	int Max[10][10], need[10][10], alloc[10][10], req[10], avail[10], completed[10], safeSequence[10];
	int p, r, i, j, process, count;
	int ch,pno;
	count = 0;
	printf(" BanKer's Algorithm\n");
	printf(" *------------------*\n");
	printf("\n1.Safety Algorithm\n2.Resource Request Algorithm\n");
	printf("\nEnter ur choice\n");
	scanf("%d",&ch);
	switch(ch) {
		case 1: {
			printf("Enter the no of processes : ");
			scanf("%d", &p);
			for(i = 0; i< p; i++)
				completed[i] = 0;
			printf("\n\nEnter the no of resources : ");
			scanf("%d", &r);
			printf("\n\nEnter the Max Matrix for each process : ");
			for(i = 0; i < p; i++) {
				printf("\nFor process %d : ", i + 1);
				for(j = 0; j < r; j++)
					scanf("%d", &Max[i][j]);
			}
			printf("\n\nEnter the allocation for each process : ");
			for(i = 0; i < p; i++) {
				printf("\nFor process %d : ",i + 1);
				for(j = 0; j < r; j++)
					scanf("%d", &alloc[i][j]);
			}
			printf("\n\nEnter the Available Resources : ");
			for(i = 0; i < r; i++)
				scanf("%d", &avail[i]);
			for(i = 0; i < p; i++)
				for(j = 0; j < r; j++)
					need[i][j] = Max[i][j] - alloc[i][j];
			printf("\n Max matrix:\tAllocation matrix:\n");
			for(i = 0; i < p; i++) {
				for( j = 0; j < r; j++)
					printf("%d ", Max[i][j]);
				printf("\t\t");
				for( j = 0; j < r; j++)
					printf("%d ", alloc[i][j]);
				printf("\n");
			}
			printf("\nNeed Matrix is:\n");
			for (i = 0; i < p; i++) {
				for (j = 0; j < r; j++)
					printf("%d ", need[i][j]);
				printf("\n");
			}
			do {
				process = -1;
				for(i = 0; i < p; i++) {
					if(completed[i] == 0) { //if not completed
						process = i ;
						for(j = 0; j < r; j++) {
							if(avail[j] < need[i][j]) {
								process = -1;
								break;
							}
						}
					}
					if(process != -1)
						break;
				}
				if(process != -1) {
					printf("\nProcess %d completes the execution!", process + 1);
					safeSequence[count] = process + 1;
					count++;
					printf("\nAvailable= ");
					for(j = 0; j < r; j++) {
						avail[j] += alloc[process][j];
						printf("%d ", avail[j]);
						alloc[process][j] = 0;
						Max[process][j] = 0;
						completed[process] = 1;
					}
				}
			} while(count != p && process != -1);
			if(count == p) {
				printf("\nSafe Sequence : < ");
				for( i = 0; i < p; i++)
					printf("P%d ", safeSequence[i]);
				printf(">\n");
				printf("\nThe system is in safe state!!\n");
			} else
				printf("\nSafe sequence is not exists!!!! \n\nThe system is in unsafe state!!");
		}
		break;
		case 2: {
			printf("Enter the no of processes : ");
			scanf("%d", &p);
			for(i = 0; i< p; i++)
				completed[i] = 0;
			printf("\n\nEnter the no of resources : ");
			scanf("%d", &r);
			printf("\n\nEnter the Max Matrix for each process : ");
			for(i = 0; i < p; i++) {
				printf("\nFor process %d : ", i + 1);
				for(j = 0; j < r; j++)
					scanf("%d", &Max[i][j]);
			}
			printf("\n\nEnter the allocation for each process : ");
			for(i = 0; i < p; i++) {
				printf("\nFor process %d : ",i + 1);
				for(j = 0; j < r; j++)
					scanf("%d", &alloc[i][j]);
			}
			printf("\n\nEnter the Available Resources : ");
			for(i = 0; i < r; i++)
				scanf("%d", &avail[i]);
			printf("\n Enter the Process number which is requesting resources now");
			scanf("%d",&pno);
			printf("\n\nEnter the current request : ");
			for(i = 0; i < r; i++)
				scanf("%d", &req[i]);
			for(i = 0; i < r; i++) {
				avail[i]-=req[i];
				alloc[pno-1][i]+=req[i];
			}
			for(i = 0; i < p; i++)
				for(j = 0; j < r; j++)
					need[i][j] = Max[i][j] - alloc[i][j];
			printf("\n Max matrix:\tAllocation matrix:\n");
			for(i = 0; i < p; i++) {
				for( j = 0; j < r; j++)
					printf("%d ", Max[i][j]);
				printf("\t\t");
				for( j = 0; j < r; j++)
					printf("%d ", alloc[i][j]);
				printf("\n");
			}
			printf("\nNeed Matrix is:\n");
			for (i = 0; i < p; i++) {
				for (j = 0; j < r; j++)
					printf("%d ", need[i][j]);
				printf("\n");
			}
			do {
				process = -1;
				for(i = 0; i < p; i++) {
					if(completed[i] == 0) { //if not completed
						process = i ;
						for(j = 0; j < r; j++) {
							if(avail[j] < need[i][j]) {
								process = -1;
								break;
							}
						}
					}
					if(process != -1)
						break;
				}
				if(process != -1) {
					printf("\nProcess %d completes the execution!", process + 1);
					safeSequence[count] = process + 1;
					count++;
					printf("\nAvailable= ");
					for(j = 0; j < r; j++) {
						avail[j] += alloc[process][j];
						printf("%d ", avail[j]);
						alloc[process][j] = 0;
						Max[process][j] = 0;
						completed[process] = 1;
					}
				}
			} while(count != p && process != -1);
			if(count == p) {
				printf("\nSafe Sequence : < ");
				for( i = 0; i < p; i++)
					printf("P%d ", safeSequence[i]);
				printf(">\n");
				printf("\nThe system will be in safe state!!\nSo the request can be granted immediately!!");
			} else
				printf("\nSafe sequence will not exist!!!! \n\nSo the request cannot be grantedimmediately!!");
			}
		break;
	}
}