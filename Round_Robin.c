#include<stdio.h>
#include<conio.h>
int main()
{
    int i, nop, ct= 0, time_quantum, counter;
    int total_wait_time = 0, total_turnaround_time = 0, arrival_time[10], burst_time[10], rt[10];
    float average_wait_time, average_turnaround_time;
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d", &nop);
    counter = nop;
    for(i = 0; i < nop; i++)
    {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Arrival Time: \t");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: \t");
        scanf("%d", &burst_time[i]);
        rt[i] = burst_time[i];
    }
    printf("\nEnter Time Quantum: \t");
    scanf("%d", &time_quantum);
    printf("\nProcess ID\tBurst Time\tTurnaround Time\t\tWaiting Time");
    for(ct = 0, i = 0; counter != 0;)
    {
        if(rt[i] <= time_quantum && rt[i] > 0)
        {
            ct = ct + rt[i];
            rt[i] = 0;
            counter--;
            printf("\nProcess[%d]\t %d\t\t \t%d\t\t\t %d", i + 1, burst_time[i], ct - arrival_time[i], ct - arrival_time[i]);
            total_wait_time = total_wait_time + ct - arrival_time[i] - burst_time[i];
            total_turnaround_time = total_turnaround_time + ct - arrival_time[i];
        }
        else if(rt[i] > 0)
        {
            rt[i] = rt[i] - time_quantum;
            ct = ct + time_quantum;
        }
        if(i == nop - 1)
        {
            i = 0;
        }
        else if(arrival_time[i + 1] <= ct)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    average_wait_time = (float)total_wait_time / nop;
    average_turnaround_time = (float)total_turnaround_time / nop;
    printf("\nAverage Waiting Time:\t%f", average_wait_time);
    printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
    return 0;
}