#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int pid;
	int bt;
}process;

int cmp(const void *a, const void *b){
	return ( ((process *)a)->bt - ((process *)b)->bt);
}

int main(){
	printf("Enter No. of Processes : ");
	int n,i;
	scanf("%d",&n);
	process *p = (process *)malloc(n * sizeof(process));
	for(i=0;i<n;i++){
    	printf("Enter Process Id :  ");
    	scanf("%d",&p[i].pid);
    	printf("Enter Burst Time :  ");
    	scanf("%d",&p[i].bt);
	}
    
	qsort(p,n,sizeof(process),cmp);
    
	for(i=0;i<n;i++){
    	printf("%d %d\n",p[i].pid,p[i].bt);
	}
    
	int *wt = (int *)malloc(n * sizeof(int));
	int *tat = (int *)malloc(n * sizeof(int));
    
	int sum = 0;
    
	for(i=0;i<n;i++){
    	wt[i] = sum ;
    	sum += p[i].bt;
    	tat[i] = sum ;
   	 
	}
    
	int tot_wt=0,tot_tat = 0;
	for(i=0;i<n;i++){
    	printf(" Process %d Waiting Time : %d TurnaroundTime : %d\n",p[i].pid,wt[i],tat[i]);
    	tot_wt += wt[i];
    	tot_tat += tat[i];
	}
	printf("Avg Waiting time : %f and Avg turn around time %f \n",((float)tot_wt)/n,((float)tot_tat)/n);
    
    
    
    
	return 0;
}

