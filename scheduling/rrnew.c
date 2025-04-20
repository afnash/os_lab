#include<stdio.h>
int main()
{
 int n;
int gpid[100],gtime[100],gcount=0;
printf("Enter no. of processes\n");
scanf("%d",&n);
int at[n],bt[n],ct[n],tat[n],wt[n],rbt[n];

for(int i=0;i<n;i++)
{
 printf("Enter the arrival time and burst time of process %d \n",i+1);
 scanf("%d%d",&at[i],&bt[i]);
rbt[i]=bt[i];
}
int qt;
printf("Enter the time quantum:");
scanf("%d",&qt);
int t=0,done=0,flag;
gtime[gcount]=t;
while(done<n)
{
 flag=0;
 for(int i=0;i<n;i++)
{
 if(rbt[i]>0&&at[i]<=t)
{
 flag=1;
if(rbt[i]>qt)
{
 t+=qt;
rbt[i]-=qt;
}
else
{
 t+=rbt[i];
ct[i]=t;
rbt[i]=0;
done++;
}
gpid[gcount]=i+1;
gcount++;
gtime[gcount]=t;
}}
if(flag==0)
{
 int min=1000000;
for(int i=0;i<n;i++)
{
 if(rbt[i]>0&&at[i]<min)
{
min=at[i];
}}
if(t<min)
{
gpid[gcount]=-1;
gcount++;
t=min;
gtime[gcount]=t;
}}}
for(int i=0;i<n;i++)
{
  tat[i]=ct[i]-at[i];
  wt[i]=tat[i]-bt[i];
 }
printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++)
{
 printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\nGantt chart:\n");
for(int i=0;i<gcount;i++)
{
 if(gpid[i]==-1)
{
 printf("| Idle ");
}
else
{
 printf("| \tP%d",gpid[i]);
}}
printf("|\n");
for(int i=0;i<=gcount;i++)
{
 printf("%d\t",gtime[i]);
}
int total_wt
return 0;
}












