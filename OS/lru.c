#include<stdio.h>
#include<limits.h>

int find_lru(int refstring[],int frame[],int f,int index){
	int backward_length = INT_MAX;
	int position = -1;
	int i,j;
	for(i=0;i<f;i++){
		for(j=index;j>=0;j--){
			if(frame[i] == refstring[j]){
				if(j<backward_length){
					position=i;
					backward_length=j;
				}
				break;
			}
		}
		if(j==0){
			return i;
		}
	}
	if(position == -1){
		return 0;
	}
	else{
		return position;
	}
}
int main(){
	int n,f,refstring[22],frame[10],avail,hit=0,fault=0;
	int i,occupied=0,j,pos;
	printf("Enter number of pages in page reference string: ");
	scanf("%d",&n);
	printf("Enter the references string: ");
	for(i=0;i<n;i++){
		scanf("%d",&refstring[i]);
	}
	
	printf("Enter number of frames: ");
	scanf("%d",&f);
	for(i=0;i<f;i++){
		frame[i] = -1;
	}
	printf("Page\tframe\n");
	printf("--------------------------------------------\n");
	for(i=0;i<n;i++){
		printf("%d\t",refstring[i]);
		avail=0;
		for(j=0;j<f;j++){
			if(frame[j] == refstring[i]){
				avail = 1;
				hit++;
			}
		}
		if(avail == 0 && occupied < f){
			frame[occupied] = refstring[i];
			fault++;
			occupied++;
		}
		else if(avail == 0){
			pos = find_lru(refstring,frame,f,i);
			frame[pos] = refstring[i];
			fault++;
		}
		for(j=0;j<f;j++){
			printf("%d\t",frame[j]);
		}
		printf("\n");
	}
	
	printf("No of page faults: %d\n",fault);
	printf("No of hit: %d\n",hit);
	printf("Hit ratio: %f",(double)hit/n);
}