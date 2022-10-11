#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int processNumbers[n];

    for (int i = 0; i < n; i++)
    {
        processNumbers[i] = i + 1;
    }

    int arrivalTime[n];
    int burstTime[n];
    int burstTime_tmp[n];

    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter the burst time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
        burstTime_tmp[i] = burstTime[i];
    }

    int completeionTime[n];
    int turnAroundTime[n];
    int waitingTime[n];

    int sumTurnAroundTime = 0;
    int sumWaitingTime = 0;

    int currentProcess = 0;
    int completed = 0;
    int timer = 0;

    int executedProcess[n];

    for (int i = 0; i < n; i++)
    {
        executedProcess[i] = 0;
    }

    while (completed < n)
    {
        if (executedProcess[currentProcess] == 0 && arrivalTime[currentProcess] <= timer)
        {
            if (burstTime[currentProcess] <= time_quantum)
            {
                completeionTime[currentProcess] = timer + burstTime[currentProcess];
                turnAroundTime[currentProcess] = completeionTime[currentProcess] - arrivalTime[currentProcess];
                waitingTime[currentProcess] = turnAroundTime[currentProcess] - burstTime_tmp[currentProcess];
                sumTurnAroundTime += turnAroundTime[currentProcess];
                sumWaitingTime += waitingTime[currentProcess];
                timer += burstTime[currentProcess];
                ++completed;
                executedProcess[currentProcess] = 1;
            }
            else
            {
                timer += time_quantum;
                burstTime[currentProcess] -= time_quantum;
            }
        }
        ++currentProcess;
        if (currentProcess == n)
            currentProcess = 0;
    }

    double averageTurnAroundTime = (double)sumTurnAroundTime / n;
    double averageWaitingTime = (double)sumWaitingTime / n;

    printf("Process Numbers\t Completeion Time:\t Turnaround Time:\t Waiting Time:\t\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processNumbers[i], completeionTime[i], turnAroundTime[i], waitingTime[i]);
    }

    printf("Average TurnAroundTime:%.2f\n", averageTurnAroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
}