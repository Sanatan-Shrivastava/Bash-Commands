#include<iostream>
using namespace std;
int main(){
	int num, temp;
	cout << "Enter number of processes: ";
	cin >> num;
	int pid[num], at[num], bt[num], ct[num], tat[num], wt[num], st[num];
	int totalWT = 0; int totalTAT = 0;
	int i, j, n;
	for(i=0; i<num; i++)
    {
        cout << "Enter the ProcessID, atival Time burst Time:";
        cin >> pid[i] >> at[i] >> bt[i];
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
            st[i]=at[i];
        else
            st[i]=ct[i-1];
        wt[i]=st[i]-at[i];
        ct[i]=st[i]+bt[i];
        tat[i]=ct[i]-at[i];
    }
    cout << "PID arrivalT burstT WaitingT TurnAT CompletionT";
    for(i=0; i<n; i++)
    {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" <<wt[i] << "\t" << tat[i] << "\t" << ct[i];
        totalWT = totalWT + wt[i];
        totalTAT = totalTAT + tat[i];
    }
    cout << "\nAverage Waiting time: " << (float)totalWT/num;
    cout << "\nAverage Turn Around Time: " << (float)totalTAT/num;
return 0;
}