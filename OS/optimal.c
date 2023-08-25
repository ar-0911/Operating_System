#include<stdio.h>


int find(int refstring[],int frame[], int n,int f,int index){
	int farthest = -1,ind = index;
	int i,j;
	int position=-1;
	for(i=0;i<f;i++){
		for(j=ind;j<n;j++){
			if(frame[i] == refstring[j]){
				if(j>farthest){
					farthest = j;
					position = i;
				}
				break;
			}
		}
		if(j==n){
			return i;
		}
	}
	if(position==-1){
		return 0;
	}
	else{
		return position;
	}
	
}

int main(){
	int n,f,refstring[22],frame[10],i,j,pos, occupied, avail, hit=0, fault=0;
	printf("Enter number of pages in page reference string: ");
	scanf("%d",&n);
	printf("Enter page reference string: ");
	for(i=0;i<n;i++){
		scanf("%d",&refstring[i]);
	}
	printf("Enter number of frames: ");
	scanf("%d",&f);
	
	for(i=0;i<f;i++){
		frame[i] = -1;
	}
	
	occupied = 0;
	printf("Page\tframe\n");
	printf("--------------------------------------------\n");
	for(i=0;i<n;i++){
		avail = 0;
		printf("%d\t",refstring[i]);
		for(j=0;j<f;j++){
			//hit
			if(frame[j] == refstring[i]){
				avail = 1;
				hit++;
				break;
			}
		}
		//fault
		if(avail == 0 && occupied < f){
			frame[occupied] = refstring[i];
			fault++;
			occupied++;
		}
		else if(avail == 0){
			pos = find(refstring,frame,n,f,i);
			frame[pos] = refstring[i];
			fault ++;
		}
		for(j=0;j<f;j++){
			printf("%d\t",frame[j]);
		}
		printf("\n");
	}
	
	printf("No of page faults: %d\n",fault);
	printf("No of page hits: %d\n",hit);
	printf("hit ratio : %f",(double)hit/n);
}