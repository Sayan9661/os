#include <bits/stdc++.h> 
  
using namespace std; 
  
int totalprocess;
  
struct process {
    int at,bt,pr,pno; 
}; 
  
process proc[50]; 
  
  
bool comp(process a,process b){ 
    if(a.at == b.at){ 
        return a.pr<b.pr; 
    } 
    else{ 
        return a.at<b.at; 
    } 
} 
  
void get_wt_time(int wt[]){
    int service[50]; 
    service[0]=0; 
    wt[0]=0; 
    for(int i=1;i<totalprocess;i++){ 
        service[i]=proc[i-1].bt+service[i-1];
        wt[i]=service[i]-proc[i].at+1; 
        if(wt[i]<0){ 
            wt[i]=0;
        } 
    } 
  
} 
  
void get_tat_time(int tat[],int wt[]){ 
    for(int i=0;i<totalprocess;i++) { 
        tat[i]=proc[i].bt+wt[i]; 
    }  
} 
  
void findgc(){ 
    int wt[50],tat[50]; 
    double wavg=0,tavg=0; 
    get_wt_time(wt);  
    get_tat_time(tat,wt); 
    int stime[50],ctime[50]; 
    stime[0]=1; 
    ctime[0]=stime[0]+tat[0]; 
    for(int i=1;i<totalprocess;i++){ 
        stime[i]=ctime[i-1]; 
        ctime[i]=stime[i]+tat[i]-wt[i]; 
    } 
      
    cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl; 
      
      
    for(int i=0;i<totalprocess;i++){ 
        wavg += wt[i]; 
        tavg += tat[i]; 
          
        cout<<proc[i].pno<<"\t\t"<< 
            stime[i]<<"\t\t"<<ctime[i]<<"\t\t"<< 
            tat[i]<<"\t\t\t"<<wt[i]<<endl; 
    } 

      
    cout<<"Average waiting time is : "; 
    cout<<wavg/(float)totalprocess<<endl; 
    cout<<"average turnaround time : "; 
    cout<<tavg/(float)totalprocess<<endl; 
  
} 
  
int main(){ 
    
    cout<<"Enter Total no. of Process : ";
    cin>>totalprocess;
    int *arrivaltime = (int *)malloc(totalprocess * sizeof(int)) ;
    int *bursttime = (int *)malloc(totalprocess * sizeof(int)) ;
    int *priority = (int *)malloc(totalprocess * sizeof(int)) ;
    cout<<"Enter Arrival Time : ";
    for(int i=0;i<totalprocess;i++)
        cin>>arrivaltime[i];
    
    cout<<"Enter Burst Time : ";
    for(int i=0;i<totalprocess;i++)
        cin>>bursttime[i];
     
     cout<<"Enter Priority : ";
    for(int i=0;i<totalprocess;i++)
        cin>>priority[i];

      
for(int i=0;i<totalprocess;i++) 
{ 
    proc[i].at=arrivaltime[i]; 
    proc[i].bt=bursttime[i]; 
    proc[i].pr=priority[i]; 
    proc[i].pno=i+1; 
    }  
      
      
    sort(proc,proc+totalprocess,comp); 
    
      
    findgc();  
  
    return 0; 
} 

