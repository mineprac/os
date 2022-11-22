

#include <stdio.h>
#include <string.h>
void main()
{
int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
int totwt=0,totta=0;
float awt,ata;
char pn[10][10],t[10];
//clrscr();
printf("Enter the number of process:");
scanf("%d",&n);
for(i=0; i<n; i++)
{
printf("Enter process name, arrival time& execution time:");
//flushall();
scanf("%s%d%d",pn[i],&at[i],&et[i]);
}
for(i=0; i<n; i++)
for(j=0; j<n; j++)
{
if(et[i]<et[j])
{
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=et[i];
et[i]=et[j];
et[j]=temp;
strcpy(t,pn[i]);
strcpy(pn[i],pn[j]);
strcpy(pn[j],t);
}
}
for(i=0; i<n; i++)
{
if(i==0)
st[i]=at[i];
else
st[i]=ft[i-1];
wt[i]=st[i]-at[i];
ft[i]=st[i]+et[i];
ta[i]=ft[i]-at[i];
totwt+=wt[i];
totta+=ta[i];
}
awt=(float)totwt/n;
ata=(float)totta/n;
printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
for(i=0; i<n; i++)
printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],wt[i],ta[i]);
printf("\nAverage waiting time is:%f",awt);
printf("\nAverage turnaroundtime is:%f",ata);
}






**********************************************************************************
**********************************************************************************
//Output
**********************************************************************************
**********************************************************************************



Enter the number of process:5
Enter process name, arrival time& execution time:P1 0 8
Enter process name, arrival time& execution time:P2 1 5
Enter process name, arrival time& execution time:P3 3 3
Enter process name, arrival time& execution time:P4 4 1
Enter process name, arrival time& execution time:P5 6 4
Pname	arrivaltime	executiontime	waitingtime	tatime
P4	    4		    1		    0		    1
P3	    3		    3		    2		    5
P5	    6		    4		    2		    6
P2	    1		    5		   11		   16
P1	    0		    8		   17		   25
Average waiting time is:6.400000
Average turnaroundtime is:10.600000




Algorithms::


1. Sort all the processes according to the arrival time.
2. Then select that process that has minimum arrival time and minimum burst time
3. After completion of the process make a pool of process that arrives afterwards till the
Completion of previous among the pool which is having minimum burst time.
4. Take process, arrival time, burst time input from the user.
5. Sort the process according to arival time and the process has the same arrival time then 
Sort them having less burst time.
6. Swap the process one above one in the order of execution.
7. Find the turnaround time (tat) and waiting time
8. Find average tat and average waiting time.
