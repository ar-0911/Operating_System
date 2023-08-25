#include<stdio.h>
//7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
int main(){
	int i,j=0,n,a[50],frame[10],no_frame,k,avail,count=0;
	int hit=0,fault=0;
	
	printf("\nEnter the number of page numbers in the reference string: ");
	scanf("%d",&n);
	
	printf("\nEnter the Page reference String: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("Enter number of Frames: ");
	scanf("%d",&no_frame);
	
	for(i=0;i<no_frame;i++){
		frame[i]=-1;
	}
	printf("Page\tFrames\n");
	printf("--------------\n");
	for(i=0;i<n;i++){
		avail=0;
		printf("%d\t",a[i]);
		for(k=0;k<no_frame;k++){
			if(a[i]==frame[k]){
				avail=1;
				hit++;
			}
		}
		if(avail==0){
			fault++;
			frame[j]=a[i];
			j=(j+1)%no_frame;
		}
		for(k=0;k<no_frame;k++){
			printf("%d\t",frame[k]);
		}
		printf("\n");
	}
	printf("\nNo of page faults = %d\nNo of page hits = %d",fault,hit);
	printf("\nHit ratio = %f",(double)hit/n);
}