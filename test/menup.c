#include<stdio.h>
#include<limits.h>
void fcfs();
void sjf();
void prio();
void fcfs(){
    int n,i,j,temp=0;
    printf("Enter the number of processes");
    scanf("%d",&n);
    int at[n],pid[n],ct[n],bt[n],tat[n],wt[n],t_tat,t_wt;
    float av_tat,av_wt;
    for(i=0;i<n;i++){
        printf("\n Enter the pid,at,bt :");
        scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        }
        else{
            ct[i]=ct[i-1]+bt[i];
        }
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        t_tat+=tat[i];
        t_wt+=wt[i];
    }
    av_wt=t_wt/n;
    av_tat=t_tat/n;
    printf("\npid\tat\tbt\tct\ttat\twt");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\ngant chart");
    for(i=0;i<n;i++){
        printf(" P %d |",pid[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("\t%d ",ct[i]);
    }
    
}
void sjf(){
    int n,i,j,current_time=0;
    printf("Enter the processs :");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],completed_flag[n],complete=0,t_tat,t_wt;
    int gantpid[100],gantct[100],gi=0;
    for(i=0;i<n;i++){
        printf("\nEnter the pid,at,bt :");
        scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
        completed_flag[i]=0;
    }
    
    while(complete<n){
        int min_br=INT_MAX;
        int index=-1;
        for(i=0;i<n;i++){
            if(at[i]<=current_time&&!completed_flag[i]&&bt[i]<min_br){
                min_br=bt[i];
                index=i;
            }
        }
        if(index==-1){
            current_time++;
        }
        else{
            ct[index]=current_time+bt[index];
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];
            t_tat+=tat[index];
            t_wt+=wt[index];
            completed_flag[index]=-1;
            current_time=ct[index];
            complete++;
            
            gantpid[gi]=pid[index];
            gantct[gi]=ct[index];
            gi++;
            
        }
    }
    printf("\npid\tat\tbt\tct\ttat\twt");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n");
    for(i=0;i<gi;i++){
        printf(" p %d |",gantpid[i]);
    }
    printf("\n");
    for(i=0;i<gi;i++){
        printf("\t%d",gantct[i]);
    }
    
    
}
void prio(){
    int n,i,j,current_time=0,complete=0;
    int gantpid[100],gantct[100],gi=0;
    printf("Enter the n umber of processes :");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],pr[n],completed_flag[n],t_tat,t_wt;
    for(i=0;i<n;i++){
        printf("\nEnter the pid,at,bt,prio :");
        scanf("%d%d%d%d",&pid[i],&at[i],&bt[i],&pr[i]);
        completed_flag[i]=0;
    }
    while(complete<n){
        int min_pr=INT_MAX;
        int index=-1;
        for(i=0;i<n;i++){
            if(at[i]<=current_time&&!completed_flag[i]&&pr[i]<min_pr){
                min_pr=pr[i];
                index=i;
            }
        }
        if(index==-1){
            current_time++;
            
        }
        else{
            ct[index]=current_time+bt[index];
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];
            t_tat+=tat[index];
            t_wt+=wt[index];
            completed_flag[index]=1;
            current_time=ct[index];
            complete++;
            
            gantpid[gi]=pid[index];
            gantct[gi]=ct[index];
            gi++;
        }
    }
     printf("\npid\tat\tbt\tct\ttat\twt");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n");
    for(i=0;i<gi;i++){
        printf(" p %d |",gantpid[i]);
    }
    printf("\n");
    for(i=0;i<gi;i++){
        printf("\t%d",gantct[i]);
    }
}
void sjr(){
    int n,i,j,current_time=0,complete=0;
    printf("Enter the number of processes :");
    scanf("%d",&n);
    int start_time[n],rt[n],t_rt;
     int timeline[1000], timeline_pid[1000], timeline_index = 0;
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],completed_flag[n],remaining_time[n],t_wt,t_tat;
    for(i=0;i<n;i++){
        printf("\nEnter the pid,at,bt :");
        scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
        completed_flag[i]=0;
        remaining_time[i]=bt[i];
        start_time[i]=-1;
    }
    
    while(complete<n){
        int min_br=INT_MAX;
        int index=-1;
        for(i=0;i<n;i++){
            if(at[i]<=current_time&&!completed_flag[i]&&remaining_time[i]<min_br){
                min_br=remaining_time[i];
                index=i;
            }
        }
        if(index==-1){
            current_time++;
            timeline_pid[timeline_index]=-1;
            timeline[timeline_index++]=current_time;
            
        }
           if (start_time[index] == -1) {
            start_time[index] = current_time;
        }

        remaining_time[index]--;
         timeline_pid[timeline_index]=pid[index];
        timeline[timeline_index++]=current_time;
        current_time++;
        
        if(remaining_time[index]==0){
            ct[index]=current_time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            rt[index] = start_time[index] - at[index];
            completed_flag[index] = 1;
            complete++;

            t_tat += tat[index];
            t_wt += wt[index];
            t_rt += rt[index];
        }
        
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
    
   

    // Gantt Chart (Accurate)
    printf("\nGANTT CHART:\n");
    
    printf("PID  : ");
    for (i = 0; i < timeline_index; i++) {
        if (timeline_pid[i] == -1)
            printf(" - ");
        else
            printf("P%d ", timeline_pid[i]);
    }
    printf("\n");
    printf("Time : ");
    for (i = 0; i < timeline_index; i++) {
        printf("%2d ", timeline[i]);
    }
    printf("%2d\n", current_time); // final time
}
void priop(){
    int n,i,j,complete=0,current_time=0;
    printf("Enter the number of processes :");
    scanf("%d",&n);
    int t_tat,t_wt,t_rt,rt[n];
    int timeline[1000],timeline_pid[1000],timeline_index=0;
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],pr[n],completed_flag[n],remaining_time[n],start_time[n];
    for(i=0;i<n;i++){
        printf("\nEnter the pid,at,bt,pr :");
        scanf("%d%d%d%d",&pid[i],&at[i],&bt[i],&pr[i]);
        completed_flag[i]=0;
        remaining_time[i]=bt[i];
        start_time[i]=-1;
    }
    while(complete<n){
        int min_pr=INT_MAX;
        int index=-1;
        for(i=0;i<n;i++){
            if(at[i]<=current_time&&!completed_flag[i]&&pr[i]<min_pr&&remaining_time[i]>0){
                min_pr=pr[i];
                index=i;
            }
        }
        if(index==-1){
            current_time++;
            timeline_pid[timeline_index]=-1;
            timeline[timeline_index++]=current_time;
        }
        if(start_time[index]==-1){
            start_time[index]=current_time;
        }
        remaining_time[index]--;
        timeline_pid[timeline_index]=pid[index];
        timeline[timeline_index++]=current_time;
        
        current_time++;
        if(remaining_time[index]==0){
            ct[index]=current_time;
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];
            rt[index]=(start_time[index]-at[index]);
            t_tat+=tat[index];
            t_wt+=wt[index];
            completed_flag[i]=1;
            complete++;
            
        }}
        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
    
        printf("\ngant chart\n");
        for(i=0;i<timeline_index;i++){
            printf("P %d |",timeline_pid[i]);
        }
        printf("\n");
        for(i=0;i<timeline_index;i++){
            printf("\t%d",timeline[i]);
        }
        
    }

int main(){
    int choice;
printf("Enter your choice");
printf("1.fcfs\n 2.sjf \n 3.priority\n 4.sjr\n 5.preprio");
scanf("%d",&choice);
switch(choice){
case 1 :
 fcfs();
 break;
case 2:
 sjf();
 break;
case 3:
prio();
break;
case 4:
sjr();
break;
case 5:
priop();
break;


}
return 0;

}