#include <stdio.h>
int main(){
int n;
printf("enter the no. of processes: \n");
scanf("%d", &n);
int at[n],bt[n],ct[n],tat[n],wt[n];
printf("enter AT and BT for each processes \n");
for(int i=0;i<n;i++){
printf("P%d : ",i+1);
scanf("%d %d",&at[i],&bt[i]);}
int curr_time=0;
for(int i=0;i<n;i++){
if(curr_time<at[i]){
curr_time=at[i];}
ct[i]=curr_time+bt[i];
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
curr_time=ct[i];
}
printf("\nProcess | AT | BT | CT | TAT | WT\n");
printf("--------------------------------------\n");
for(int i=0;i<n;i++){
printf(" P%d   | %2d | %2d | %2d | %2d | %2d \n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
return 0;
}
