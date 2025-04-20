#include<stdio.h>
void pp(int n,int pid[],int at[],int bt[],int pr[])
{
int i,j,temp,t=0,ct[n],tat[n],wt[n];
for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
		if(pr[j]<pr[i])
{
temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;
temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}
printf("\nGANTT CHART\n");
for(i=0;i<n;i++)
{
printf("| P%d",pid[i]);
t+=bt[i];
ct[i]=t;
}
printf("|\n");
printf("0");
for(i=1;i<n;i++)
{
printf("  %d",ct[i]);
}
printf("\n");
float tot_tat=0;float tot_wt=0;float avgtat,avgwt;
for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
tot_tat+=tat[i];
tot_wt+=wt[i];
}
printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}
avgtat=tot_tat/n;
avgwt=tot_wt/n;
printf("Average TAT :%f\n ",avgtat);
printf("Average WT :%f ",avgwt);
}
int main()
{
int n,i;
printf("Enter the number of processes: ");
scanf("%d",&n);
int at[n],bt[n],pid[n],pr[n];
for(i=0;i<n;i++)
{
printf("Enter pid,arrival time and burst time,priority for process: ");
scanf("%d%d%d%d",&pid[i],&at[i],&bt[i],&pr[i]);
}
pp(n,pid,at,bt,pr);
return 0;
}
