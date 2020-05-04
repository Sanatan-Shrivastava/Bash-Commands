#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int pn[10], at[10],bt[10],star[10],ct[10],tat[10],wt[10],i,j,n,temp;
    int totwt=0,tottat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the ProcessID, arrivalTime burst Time:");
        scanf("%d%d%d",&pn[i],&at[i],&bt[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(at[i]<at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
 
        }
    }
    for(i=0; i<n; i++)
    {
        if(i==0)
            star[i]=at[i];
        else
            star[i]=ct[i-1];
        wt[i]=star[i]-at[i];
        ct[i]=star[i]+bt[i];
        tat[i]=ct[i]-at[i];
    }
    printf("\nPID arrivalT btstT WaitingT TurnArT CompletionT");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t%3d\t%3d\t%3d\t%6d\t%6d",pn[i],at[i],bt[i],wt[i],tat[i],ct[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("\nAverage Waiting time:%f",(float)totwt/n);
    printf("\nAverage Turn Around Time:%f\n",(float)tottat/n);
return 0;
}