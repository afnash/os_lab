#include<stdio.h>
int fm[25];
int fsize;
void display(){
for(int i=0;i<fsize;i++)
printf("\t%d",fm[i]);
}
int main(){
int pg[100],i,j,npage,pf=0,top=-1,flag=0,hit=0,miss=0;
printf("Enter frame size : ");
scanf("%d",&fsize);
printf("Enter no. of pages : ");
scanf("%d",&npage);
for(i=0;i<npage;i++){
printf("Enter page [%d] : ",i+1);
scanf("%d",&pg[i]);
}
for(i=0;i<fsize;i++)
fm[i]=-1;
printf("\npage \t frame content");
printf("\n------------------------------");
for(j=0;j<npage;j++){
flag=0;
for(i=0;i<fsize;i++){
if(fm[i]==pg[j]){
flag=1;
hit++;
break;
}
}
if(flag==0){
miss++;
if(top==(fsize-1))
top=-1;
pf++;
top++;
fm[top]=pg[j];
}
printf("\n%d",pg[j]);
display();
}
printf("\n---------------------------------");
printf("\nTotal page faults: %d",pf);
printf("\nTotal hits: %d",hit);
printf("\nHit Ratio: %.2f", (float)hit/npage);
printf("\nMiss Ratio: %.2f", (float)miss/npage);
return 0;
}

