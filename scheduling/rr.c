#include<stdio.h>
int main()
{
int n,i,j,index,current_time=0,completed=0,time_q,min_at,temp;
float tot_tat=0,tot_wt=0,avgtat,avgwt;
printf("Enter the number of processes: ");
scanf("%d",&n);
int at[n],bt[n],ct[n],tat[n],wt[n],pid[n],completed_flag[n],rt[n];

for(i=0;i<n;i++)
{
printf("Enter pid,arrival time and burst time: ");
scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
completed_flag[i]=0;
rt[i]=bt[i];
}
printf("Enter time quantum :");
scanf("%d",&time_q);
for( i=0; i<n-1; i++)
{
for( j=0; j<n-i-1; j++)
{
if(at[j]>at[j+1])
{
temp=at[j];
at[j]=at[j+1];
at[j+1]=temp;
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
temp=pid[j];
pid[j]=pid[j+1];
pid[j+1]=temp;
}
}}
if(at[0]>current_time)
{
current_time=at[0];
}
printf("current%d",current_time);
while(completed<n)
{
int executed=0;
for( i=0; i<n; i++){
if(at[i]<=current_time&&!completed_flag[i])
{
if(rt[i]>time_q)
{
current_time+=time_q;
rt[i]-=time_q;
}
else
{
current_time+=rt[i];
rt[i]=0;
ct[i]=current_time;
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];

tot_tat+=tat[i];
tot_wt+=wt[i];
completed_flag[i]=1;
completed++;
}
executed=1;
}}
printf("\nPID\tAT\tBT\tRT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],rt[i]);
}
printf("current%d",current_time);

if(!executed)
{
current_time++;
}}
printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
}
avgtat=tot_tat/n;
avgwt=tot_wt/n;
printf("Average TAT :%f\n ",avgtat);
printf("Average WT :%f ",avgwt);
printf("\nGANTT CHART\n");
for(i=0;i<n;i++)    
{
printf("| P%d",pid[i]);
}
printf("\n");
printf("0");
for(i=0;i<n;i++)
{
printf("  %d",ct[i]);
}
printf("\n");
return 0;
}
